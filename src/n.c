//   Copyright 2025 Will Thomas
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0;
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

//   sub umbra alarum suarum

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

//#include "arm/32a.h"
//#include "arm/32m.h"
//#include "x86/x86.h"
//#include "x86/i386.h"
#include "x86/x64.h"

struct n_sym_s {
	uint8_t* str;
	uint8_t len;
	uint64_t addr;
	uint8_t typ;
};

void (*n_read) (uint8_t*, uint64_t*, struct n_sym_s*, uint64_t*, uint8_t*, int8_t*);

void (*n_writ) (uint8_t*, uint64_t, struct n_sym_s*, uint64_t, uint8_t*);

void (*n_reg_set_sp) (uint8_t*, uint64_t);

uint64_t (*n_reg_get_sp) (uint8_t*);

uint64_t (*n_reg_get_ip) (uint8_t*);

void (*n_reg_print) (uint8_t*);

void (*n_print_stack) (uint8_t*, uint64_t*);

void (*n_dec) (uint8_t*, uint64_t*, uint64_t*);

void (*n_inc) (uint8_t*, uint64_t, uint64_t);

uint64_t str_int_dec(int8_t* a) {
	uint64_t b = 0;
	for(uint8_t i = 0; i < 20; i++) {
		if (a[i] == 0 || a[i] == ')') {
			return b;
		}
		b *= 10;
		if (a[i] == '1') {
			b += 1;
		}
		else if (a[i] == '2') {
			b += 2;
		}
		else if (a[i] == '3') {
			b += 3;
		}
		else if (a[i] == '4') {
			b += 4;
		}
		else if (a[i] == '5') {
			b += 5;
		}
		else if (a[i] == '6') {
			b += 6;
		}
		else if (a[i] == '7') {
			b += 7;
		}
		else if (a[i] == '8') {
			b += 8;
		}
		else if (a[i] == '9') {
			b += 9;
		}
		else if (a[i] != '0' && a[i] != ')') {
			return -1;
		}
	}
}

void n_dasm(uint8_t* bin, uint64_t bn, struct n_sym_s* sym, uint64_t symn, int8_t* e, uint8_t regn, uint64_t sp, uint64_t ip) {
	n_reg_print(bin);
	uint64_t bi = 0;
	while (bi < (bn - regn)) {
		for (uint64_t i = 0; i < symn; i++) {
			if (sym[i].addr == bi + regn) {
				printf("[*%s]\n", sym[i].str);
			}
		}
		
		if (bi == ip) {
			if (bn < 256) {
				printf("%02x [+] ", bi & 255);
			}
			else if (bn < 65536) {
				printf("%02x %02x [+] ", (bi >> 8) & 255, bi & 255);
			}
			else if (bn < 16777216) {
				printf("%02x %02x %02x [+] ", (bi >> 16) & 255, (bi >> 8) & 255, bi & 255);
			}
			else if (bn < 4294967295) {
				printf("%02x %02x %02x %02x [+] ", (bi >> 24) & 255, (bi >> 16) & 255, (bi >> 8) & 255, bi & 255);
			}
		}
		else {
			if (bn < 256) {
				printf("%02x [ ] ", bi & 255);
			}
			else if (bn < 65536) {
				printf("%02x %02x [ ] ", (bi >> 8) & 255, bi & 255);
			}
			else if (bn < 16777216) {
				printf("%02x %02x %02x [ ] ", (bi >> 16) & 255, (bi >> 8) & 255, bi & 255);
			}
			else if (bn < 4294967295) {
				printf("%02x %02x %02x %02x [ ] ", (bi >> 24) & 255, (bi >> 16) & 255, (bi >> 8) & 255, bi & 255);
			}
		}
		if (bi < sp) {
			uint64_t addr = (uint64_t) -1;
			n_dec(bin + regn, &bi, &addr);
			
			if (addr != (uint64_t) -1) {
				for (uint64_t i = 0; i < symn; i++) {
					if (sym[i].addr == addr + regn) {
						printf("; [*%s]", sym[i].str);
					}
				}
			}
		}
		else {
			n_print_stack(bin + regn, &bi);
		}
		printf("\n");
	}
}

void n_read_bin(uint8_t* bin, uint64_t* bn, struct n_sym_s* sym, uint64_t* symn, uint8_t* path, int8_t* e) {
	FILE* f = fopen(path, "r");
	if (!f) {
		printf("[%s] error: file doesn't exist\n", path);
		*e = -1;
		return;
	}
	fseek(f, 0, SEEK_END);
	uint64_t fn = ftell(f);
	uint8_t* fx = malloc(fn);
	fseek(f, 0, SEEK_SET);
	fread(fx, fn, 1, f);
	fclose(f);
	
	memcpy(bin + *bn, fx, fn);
	*bn = *bn + fn;
}

void n_read_zn(uint8_t* bin, uint64_t* bn, struct n_sym_s* sym, uint64_t* symn, uint8_t* path, int8_t* e) {
	int32_t fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("error: failed to open file '%s'\n", path);
		*e = -1;
        return;
    }
	
    struct stat fs;
    fstat(fd, &fs);
	
    uint8_t* fx = mmap(0, fs.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
	
	uint32_t mag = *((uint32_t*) fx);
	uint64_t binoff = *((uint64_t*) (fx + 4));
	uint64_t binnum = *((uint64_t*) (fx + 12));
	uint64_t symoff = *((uint64_t*) (fx + 20));
	uint64_t symnum = *((uint64_t*) (fx + 28));
	
	if (mag != 1668180346) {
		printf("[%s] error: corrupted file\n", path);
		*e = -1;
		return;
	}
	
	memcpy(bin + *bn, fx + binoff, binnum);
	
	for (uint64_t i = 0; i < symnum; i++) {
		sym[i + *symn].len = *((uint8_t*) (fx + symoff + (18 * i) + 8));
		sym[i + *symn].addr = *((uint64_t*) (fx + symoff + (18 * i) + 9)) + *bn;
		sym[i + *symn].typ = *(fx + symoff + (18 * i) + 17);
		
		uint64_t stroff = *((uint64_t*) (fx + symoff + (18 * i)));
		sym[i + *symn].str = malloc(sym[i + *symn].len);
		memcpy(sym[i + *symn].str, fx + stroff, sym[i + *symn].len);
	}
	*bn = *bn + binnum;
	*symn = *symn + symnum;
	
	munmap(fx, fs.st_size);
}

void n_writ_bin(uint8_t* bin, uint64_t bn, struct n_sym_s* sym, uint64_t symn, uint8_t* path) {
	int32_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        printf("error: failed to create file '%s'\n", path);
        return;
    }
    ftruncate(fd, bn);
    uint8_t* mem = mmap(0, bn, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(mem, bin, bn);
	munmap(mem, bn);
	close(fd);
}

void n_writ_zn(uint8_t* bin, uint64_t bn, struct n_sym_s* sym, uint64_t symn, uint8_t* path) {
	uint64_t strsz = 0;
	for (uint8_t i = 0; i < symn; i++) {
		strsz = strsz + sym[i].len;
	}
	
	uint64_t memsz = 52 + bn + (symn * 18) + strsz;
	
	int32_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        printf("error: failed to create file '%s'\n", path);
        return;
    }
    ftruncate(fd, memsz);
    uint8_t* mem = mmap(0, memsz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	uint64_t binoff = 52;
	uint64_t symoff = 52 + bn;
	uint64_t reloff = 52 + bn + (symn * 18);
	uint64_t stroff = 52 + bn + (symn * 18);
	
	uint64_t reln = 0;
	
	memcpy(mem, "zinc", 4);
	memcpy(mem + 4, &binoff, 8);
	memcpy(mem + 12, &bn, 8);
	memcpy(mem + 20, &symoff, 8);
	memcpy(mem + 28, &symn, 8);
	memcpy(mem + 36, &reloff, 8);
	memcpy(mem + 44, &reln, 8);
	
	memcpy(mem + binoff, bin, bn);
	for (uint64_t i = 0; i < symn; i++) {
		memcpy(mem + symoff + (18 * i), &stroff, 8);
		memcpy(mem + symoff + (18 * i) + 8, &(sym[i].len), 1);
		memcpy(mem + symoff + (18 * i) + 9, &(sym[i].addr), 8);
		memcpy(mem + symoff + (18 * i) + 17, &(sym[i].typ), 1);
		
		memcpy(mem + stroff, sym[i].str, sym[i].len);
		stroff = stroff + sym[i].len;
	}
	
	munmap(mem, memsz);
	close(fd);
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 5) {
		printf("usage: n [architecture] [binary.bin or link.zn] [flag] [value]\n");
		printf("  --init [stack_size]   initializes stack and registers\n");
		printf("  --inc  [steps]        increments instructions by step\n");
		return -1;
	}
		
	uint8_t regn;
	
	if (!strcmp(argv[1], "arm32-a")) {
		//n_dec = arm_32a_dec;
	}
	else if (!strcmp(argv[1], "arm32-m")) {
		//n_dec = arm_32m_dec;
	}
	else if (!strcmp(argv[1], "x86")) {
		//n_dec = x86_dec;
	}
	else if (!strcmp(argv[1], "i386")) {
		//n_dec = i386_dec;
	}
	else if (!strcmp(argv[1], "x86-64")) {
		n_reg_set_sp = x86_64_reg_set_sp;
		n_reg_get_sp = x86_64_reg_get_sp;
		n_reg_get_ip = x86_64_reg_get_ip;
		n_reg_print = x86_64_reg_print;
		n_print_stack = x86_64_print_stack;
		n_dec = x86_64_dec;
		n_inc = x86_64_inc;
		regn = 138;
	}
	else {
		printf("error: unsupported architecture\n");
	}
	
	if (!strcmp(argv[2] + strlen(argv[2]) - 4, ".bin")) {
		n_read = n_read_bin;
		n_writ = n_writ_bin;
	}
	else if (!strcmp(argv[2] + strlen(argv[2]) - 3, ".zn")) {
		n_read = n_read_zn;
		n_writ = n_writ_zn;
	}
	else {
		printf("error: invalid input format\n");
		return -1;
	}
	
	if (!strcmp(argv[3], "--init")) {
		uint8_t* bin = calloc(16777216, 1);
		uint64_t bn = 0;
		struct n_sym_s* sym = calloc(16777216, 1);
		uint64_t symn = 0;
		
		int8_t e = 0;
		
		bn = regn;
		
		n_read(bin, &bn, sym, &symn, argv[2], &e);
		
		bn = bn + str_int_dec(argv[4]);
		n_reg_set_sp(bin, bn);
		
		if (!e) {
			n_writ(bin, bn, sym, symn, argv[2]);
		}
		
		free(bin);
		free(sym);
		return 0;
	}
	else if (!strcmp(argv[3], "--inc")) {
		uint8_t* bin = calloc(16777216, 1);
		uint64_t bn = 0;
		struct n_sym_s* sym = calloc(16777216, 1);
		uint64_t symn = 0;
		
		int8_t e = 0;
		
		n_read(bin, &bn, sym, &symn, argv[2], &e);
		uint64_t sp = n_reg_get_sp(bin);
		uint64_t ip = n_reg_get_ip(bin);
		
		uint64_t step = str_int_dec(argv[4]);
		
		if (!e) {
			n_dasm(bin, bn, sym, symn, &e, regn, sp, ip);
			for (uint64_t i = 0; i < step; i++) {
				n_inc(bin, bn, ip);
			}
			n_writ(bin, bn, sym, symn, argv[2]);
		}
		
		free(bin);
		free(sym);
		return 0;		
	}
	else {
		printf("error: unknown flag\n");
		return -1;
	}
}
