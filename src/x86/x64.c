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
#include <stdio.h>

void x86_64_reg_set_sp(uint8_t* bin, uint64_t bn) {
	bn = bn - 138;
	bin[32] = bn;
	bin[33] = bn >> 8;
	bin[34] = bn >> 16;
	bin[35] = bn >> 24;
	bin[36] = bn >> 32;
	bin[37] = bn >> 40;
	bin[38] = bn >> 48;
	bin[39] = bn >> 56;
}

uint64_t x86_64_reg_get_sp(uint8_t* bin) {
	uint64_t sp = bin[32] + (bin[33] << 8) + (bin[34] << 16) + (bin[35] << 24) + (bin[36] << 32) + (bin[37] << 40) + (bin[38] << 48) + (bin[39] << 56);
	return sp;
}

uint64_t x86_64_reg_get_ip(uint8_t* bin) {
	uint64_t ip = bin[128] + (bin[129] << 8) + (bin[130] << 16) + (bin[131] << 24) + (bin[132] << 32) + (bin[133] << 40) + (bin[134] << 48) + (bin[135] << 56);
	return ip;
}

void x86_64_reg_print(uint8_t* bin) {
	printf("rip        :eip  :ip   \n");	
	printf("%02x %02x %02x %02x:%02x %02x:%02x %02x\n\n", bin[135], bin[134], bin[133], bin[132], bin[131], bin[130], bin[129], bin[128]);
	printf("            of df if tf    sf zf    af    pf    cf\n");
	printf("%u  %u  %u  %u  %u  %u  %u  %u     %u  %u  %u  %u  %u  %u  %u  %u \n\n", !!(bin[137] & 128), !!(bin[137] & 64), !!(bin[137] & 32), !!(bin[137] & 16), !!(bin[137] & 8), !!(bin[137] & 4), !!(bin[137] & 2), !!(bin[137] & 1), !!(bin[136] & 128), !!(bin[136] & 64), !!(bin[136] & 32), !!(bin[136] & 16), !!(bin[136] & 8), !!(bin[136] & 4), !!(bin[136] & 2), !!(bin[136] & 1));
	printf("rax        :eax  :ax   ");
	printf("    rsp        :esp  :sp     \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[7], bin[6], bin[5], bin[4], bin[3], bin[2], bin[1], bin[0]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[39], bin[38], bin[37], bin[36], bin[35], bin[34], bin[33], bin[32]);
	printf("                  ah:al");
	printf("                        :spl \n");
	printf("rcx        :ecx  :cx   ");
	printf("    rbp        :ebp  :bp     \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[15], bin[14], bin[13], bin[12], bin[11], bin[10], bin[9], bin[8]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[47], bin[46], bin[45], bin[44], bin[43], bin[42], bin[41], bin[40]);
	printf("                  ch:cl");
	printf("                        :bpl \n");
	printf("rdx        :edx  :dx   ");
	printf("    rsi        :esi  :si     \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[23], bin[22], bin[21], bin[20], bin[19], bin[18], bin[17], bin[16]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[55], bin[54], bin[53], bin[52], bin[51], bin[50], bin[49], bin[58]);
	printf("                  dh:dl");
	printf("                        :sil \n");
	printf("rbx        :ebx  :bx   ");
	printf("    rdi        :edi  :di     \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[31], bin[30], bin[29], bin[28], bin[27], bin[26], bin[25], bin[24]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[63], bin[62], bin[61], bin[60], bin[59], bin[58], bin[57], bin[56]);
	printf("                  bh:bl");
	printf("                        :dil \n");
	printf("r8         :r8d  :r8w  ");
	printf("    r12        :r12d :r12w   \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[71], bin[70], bin[69], bin[68], bin[67], bin[66], bin[65], bin[64]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[103], bin[102], bin[101], bin[100], bin[99], bin[98], bin[97], bin[96]);
	printf("                    :r8b");
	printf("                       :r12b\n");
	printf("r9         :r9d  :r9w  ");
	printf("    r13        :r13d :r13w   \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[79], bin[78], bin[77], bin[76], bin[75], bin[74], bin[73], bin[72]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[111], bin[110], bin[109], bin[108], bin[107], bin[106], bin[105], bin[104]);
	printf("                    :r9b");
	printf("                       :r13b\n");
	printf("r10        :r10d :r10w ");
	printf("    r14        :r14d :r14w   \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[87], bin[86], bin[85], bin[84], bin[83], bin[82], bin[81], bin[80]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[119], bin[118], bin[117], bin[116], bin[115], bin[114], bin[113], bin[112]);
	printf("                    :r10b");
	printf("                      :r14b\n");
	printf("r11        :r11d :r11w ");
	printf("    r15        :r15d :r15w   \n");
	printf("%02x %02x %02x %02x:%02x %02x:%02x:%02x", bin[95], bin[94], bin[93], bin[92], bin[91], bin[90], bin[89], bin[88]);
	printf("    %02x %02x %02x %02x:%02x %02x:%02x:%02x  \n", bin[127], bin[126], bin[125], bin[124], bin[123], bin[122], bin[121], bin[120]);
	printf("                    :r11b");
	printf("                      :r15b\n\n");
}

void x86_64_print_stack(uint8_t* bin, uint64_t* bn) {
	printf("%02x %02x %02x %02x %02x %02x %02x %02x                      ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3], bin[*bn + 4], bin[*bn + 5], bin[*bn + 6], bin[*bn + 7]);
	for (uint8_t i = 0; i < 8; i++) {
		if (bin[*bn + i] >= 32 && bin[*bn + i] < 127) {
			printf("%c", bin[*bn + i]);
		}
		else if (bin[*bn + i] == 0) {
			printf("\\0");
		}
		else if (bin[*bn + i] == 7) {
			printf("\\a");
		}
		else if (bin[*bn + i] == 8) {
			printf("\\b");
		}
		else if (bin[*bn + i] == 9) {
			printf("\\t");
		}
		else if (bin[*bn + i] == 10) {
			printf("\\n");
		}
		else if (bin[*bn + i] == 11) {
			printf("\\v");
		}
		else if (bin[*bn + i] == 12) {
			printf("\\f");
		}
		else if (bin[*bn + i] == 13) {
			printf("\\r");
		}
		else if (bin[*bn + i] == 27) {
			printf("\\e");
		}
	}
	*bn = *bn + 8;
}

int8_t* x86_64_dec_r8(uint8_t r) {
	if (r == 0) {
		return "al";
	}
	else if (r == 1) {
		return "cl";
	}
	else if (r == 2) {
		return "dl";
	}
	else if (r == 3) {
		return "bl";
	}
	else if (r == 4) {
		return "ah";
	}
	else if (r == 5) {
		return "ch";
	}
	else if (r == 6) {
		return "dh";
	}
	else if (r == 7) {
		return "bh";
	}	
}

int8_t* x86_64_dec_r8x(uint8_t r) {
	if (r == 0) {
		return "al";
	}
	else if (r == 1) {
		return "cl";
	}
	else if (r == 2) {
		return "dl";
	}
	else if (r == 3) {
		return "bl";
	}
	else if (r == 4) {
		return "spl";
	}
	else if (r == 5) {
		return "bpl";
	}
	else if (r == 6) {
		return "sil";
	}
	else if (r == 7) {
		return "dil";
	}
	else if (r == 8) {
		return "r8b";
	}
	else if (r == 9) {
		return "r9b";
	}
	else if (r == 10) {
		return "r10b";
	}
	else if (r == 11) {
		return "r11b";
	}
	else if (r == 12) {
		return "r12b";
	}
	else if (r == 13) {
		return "r13b";
	}
	else if (r == 14) {
		return "r14b";
	}
	else if (r == 15) {
		return "r15b";
	}
}

int8_t* x86_64_dec_r16(uint8_t r) {
	if (r == 0) {
		return "ax";
	}
	else if (r == 1) {
		return "cx";
	}
	else if (r == 2) {
		return "dx";
	}
	else if (r == 3) {
		return "bx";
	}
	else if (r == 4) {
		return "sp";
	}
	else if (r == 5) {
		return "bp";
	}
	else if (r == 6) {
		return "si";
	}
	else if (r == 7) {
		return "di";
	}
	else if (r == 8) {
		return "r8w";
	}
	else if (r == 9) {
		return "r9w";
	}
	else if (r == 10) {
		return "r10w";
	}
	else if (r == 11) {
		return "r11w";
	}
	else if (r == 12) {
		return "r12w";
	}
	else if (r == 13) {
		return "r13w";
	}
	else if (r == 14) {
		return "r14w";
	}
	else if (r == 15) {
		return "r15w";
	}
}

int8_t* x86_64_dec_r32(uint8_t r) {
	if (r == 0) {
		return "eax";
	}
	else if (r == 1) {
		return "ecx";
	}
	else if (r == 2) {
		return "edx";
	}
	else if (r == 3) {
		return "ebx";
	}
	else if (r == 4) {
		return "esp";
	}
	else if (r == 5) {
		return "ebp";
	}
	else if (r == 6) {
		return "esi";
	}
	else if (r == 7) {
		return "edi";
	}
	else if (r == 8) {
		return "r8d";
	}
	else if (r == 9) {
		return "r9d";
	}
	else if (r == 10) {
		return "r10d";
	}
	else if (r == 11) {
		return "r11d";
	}
	else if (r == 12) {
		return "r12d";
	}
	else if (r == 13) {
		return "r13d";
	}
	else if (r == 14) {
		return "r14d";
	}
	else if (r == 15) {
		return "r15d";
	}
}

int8_t* x86_64_dec_r64(uint8_t r) {
	if (r == 0) {
		return "rax";
	}
	else if (r == 1) {
		return "rcx";
	}
	else if (r == 2) {
		return "rdx";
	}
	else if (r == 3) {
		return "rbx";
	}
	else if (r == 4) {
		return "rsp";
	}
	else if (r == 5) {
		return "rbp";
	}
	else if (r == 6) {
		return "rsi";
	}
	else if (r == 7) {
		return "rdi";
	}
	else if (r == 8) {
		return "r8";
	}
	else if (r == 9) {
		return "r9";
	}
	else if (r == 10) {
		return "r10";
	}
	else if (r == 11) {
		return "r11";
	}
	else if (r == 12) {
		return "r12";
	}
	else if (r == 13) {
		return "r13";
	}
	else if (r == 14) {
		return "r14";
	}
	else if (r == 15) {
		return "r15";
	}
}

uint8_t x86_64_dec_s8(uint8_t k) {
	if (k == 0) {
		return 1;
	}
	else if (k == 1) {
		return 2;
	}
	else if (k == 2) {
		return 4;
	}
	else if (k == 3) {
		return 8;
	}
}

uint8_t x86_64_dec_r80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (rex) {
						printf("               %s (%u), %s", mn, d, x86_64_dec_r8x(mrs));
					}
					else {
						printf("               %s (%u), %s", mn, d, x86_64_dec_r8(mrs));
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s), %s", mn, x86_64_dec_r32(b), x86_64_dec_r8x(mrs));
						}
						else {
							printf("                           %s (%s), %s", mn, x86_64_dec_r64(b), x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s), %s", mn, x86_64_dec_r32(b), x86_64_dec_r8(mrs));
						}
						else {
							printf("                           %s (%s), %s", mn, x86_64_dec_r64(b), x86_64_dec_r8(mrs));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), x86_64_dec_r8x(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), x86_64_dec_r8(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), x86_64_dec_r8(mrs));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_r8x(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_r8(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_r8(mrs));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s (eip, -%u), %s", mn, d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (rip, -%u), %s", mn, d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (eip, -%u), %s", mn, d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (rip, -%u), %s", mn, d, x86_64_dec_r8(mrs));
							}
						}
						*addr = *bn - d;
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s (eip, %u), %s", mn, d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (rip, %u), %s", mn, d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (eip, %u), %s", mn, d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (rip, %u), %s", mn, d, x86_64_dec_r8(mrs));
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %s (eip), %s", mn, x86_64_dec_r8x(mrs));
						}
						else {
							printf("               %s (rip), %s", mn, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip), %s", mn, x86_64_dec_r8(mrs));
						}
						else {
							printf("               %s (rip), %s", mn, x86_64_dec_r8(mrs));
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (rex) {
					if (lga) {
						printf("                              %s (%s), %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r8x(mrs));
					}
					else {
						printf("                              %s (%s), %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r8x(mrs));
					}
				}
				else {
					if (lga) {
						printf("                              %s (%s), %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r8(mrs));
					}
					else {
						printf("                              %s (%s), %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r8(mrs));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8x(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8(mrs));
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8x(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8(mrs));
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8(mrs));
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8x(mrs));
							}
							else {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8x(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r8(mrs));
							}
							else {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r8(mrs));
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8x(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8(mrs));
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8x(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r8(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r8(mrs));
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (rex) {
				printf("                              %s %s, %s", mn, x86_64_dec_r8x(mrd), x86_64_dec_r8x(mrs));
			}
			else {
				printf("                              %s %s, %s", mn, x86_64_dec_r8(mrd), x86_64_dec_r8(mrs));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rg0(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lgo) {
						printf("               %s (%u), %s", mn, d, x86_64_dec_r16(mrs));
					}
					else if (!rx3) {
						printf("               %s (%u), %s", mn, d, x86_64_dec_r32(mrs));
					}
					else {
						printf("               %s (%u), %s", mn, d, x86_64_dec_r64(mrs));
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s), %s", mn, x86_64_dec_r32(b), x86_64_dec_r16(mrs));
						}
						else {
							printf("                           %s (%s), %s", mn, x86_64_dec_r64(b), x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(mrs));
						}
						else {
							printf("                           %s (%s), %s", mn, x86_64_dec_r64(b), x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s), %s", mn, x86_64_dec_r32(b), x86_64_dec_r64(mrs));
						}
						else {
							printf("                           %s (%s), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(mrs));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), x86_64_dec_r16(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), x86_64_dec_r32(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), x86_64_dec_r64(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), x86_64_dec_r64(mrs));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_r16(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_r32(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_r64(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_r64(mrs));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s (eip, -%u), %s", mn, d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (rip, -%u), %s", mn, d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (eip, -%u), %s", mn, d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (rip, -%u), %s", mn, d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (eip, -%u), %s", mn, d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (rip, -%u), %s", mn, d, x86_64_dec_r64(mrs));
							}
						}
						*addr = *bn - d;
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s (eip, %u), %s", mn, d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (rip, %u), %s", mn, d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (eip, %u), %s", mn, d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (rip, %u), %s", mn, d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (eip, %u), %s", mn, d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (rip, %u), %s", mn, d, x86_64_dec_r64(mrs));
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s (eip), %s", mn, x86_64_dec_r16(mrs));
						}
						else {
							printf("               %s (rip), %s", mn, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (eip), %s", mn, x86_64_dec_r32(mrs));
						}
						else {
							printf("               %s (rip), %s", mn, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip), %s", mn, x86_64_dec_r64(mrs));
						}
						else {
							printf("               %s (rip), %s", mn, x86_64_dec_r64(mrs));
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                              %s (%s), %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r16(mrs));
					}
					else {
						printf("                              %s (%s), %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r16(mrs));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %s (%s), %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r32(mrs));
					}
					else {
						printf("                              %s (%s), %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r32(mrs));
					}
				}
				else {
					if (lga) {
						printf("                              %s (%s), %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r64(mrs));
					}
					else {
						printf("                              %s (%s), %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r64(mrs));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("                        %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r16(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r32(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r64(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r64(mrs));
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r16(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r32(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r64(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r64(mrs));
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(b), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(b), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, (%s, %u), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, (%s), -%u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r64(mrs));
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r16(mrs));
							}
							else {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r16(mrs));
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r32(mrs));
							}
							else {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r32(mrs));
							}
						}
						else {
							if (lga) {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, x86_64_dec_r64(mrs));
							}
							else {
								printf("               %s (%s, (%s), %u), %s", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, x86_64_dec_r64(mrs));
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r16(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r32(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r64(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r64(mrs));
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r16(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r32(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r32(mrd), d, x86_64_dec_r64(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, x86_64_dec_r64(mrd), d, x86_64_dec_r64(mrs));
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (lgo) {
				printf("                              %s %s, %s", mn, x86_64_dec_r16(mrd), x86_64_dec_r16(mrs));
			}
			else if (!rx3) {
				printf("                              %s %s, %s", mn, x86_64_dec_r32(mrd), x86_64_dec_r32(mrs));
			}
			else {
				printf("                              %s %s, %s", mn, x86_64_dec_r64(mrd), x86_64_dec_r64(mrs));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_r81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (rex) {
						printf("               %s %s, (%u)", mn, x86_64_dec_r8x(mrs), d);
					}
					else {
						printf("               %s %s, (%u)", mn, x86_64_dec_r8(mrs), d);
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b));
						}
						else {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b));
						}
						else {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                  %s %s, (eip, -%u)", mn, x86_64_dec_r8x(mrs), d);
							}
							else {
								printf("                  %s %s, (rip, -%u)", mn, x86_64_dec_r8x(mrs), d);
							}
						}
						else {
							if (lga) {
								printf("                  %s %s, (eip, -%u)", mn, x86_64_dec_r8(mrs), d);
							}
							else {
								printf("                  %s %s, (rip, -%u)", mn, x86_64_dec_r8(mrs), d);
							}
						}
						*addr = *bn - d;
					}
					else {
						if (rex) {
							if (lga) {
								printf("                  %s %s, (eip, %u)", mn, x86_64_dec_r8x(mrs), d);
							}
							else {
								printf("                  %s %s, (rip, %u)", mn, x86_64_dec_r8x(mrs), d);
							}
						}
						else {
							if (lga) {
								printf("                  %s %s, (eip, %u)", mn, x86_64_dec_r8(mrs), d);
							}
							else {
								printf("                  %s %s, (rip, %u)", mn, x86_64_dec_r8(mrs), d);
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("                  %s %s, (eip)", mn, x86_64_dec_r8x(mrs));
						}
						else {
							printf("                  %s %s, (rip)", mn, x86_64_dec_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                  %s %s, (eip)", mn, x86_64_dec_r8(mrs));
						}
						else {
							printf("                  %s %s, (rip)", mn, x86_64_dec_r8(mrs));
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (rex) {
					if (lga) {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8x(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r8(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (rex) {
				printf("                              %s %s, %s", mn, x86_64_dec_r8x(mrs), x86_64_dec_r8x(mrd));
			}
			else {
				printf("                              %s %s, %s", mn, x86_64_dec_r8(mrs), x86_64_dec_r8(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rg1(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lgo) {
						printf("               %s %s, (%u)", mn, x86_64_dec_r16(mrs), d);
					}
					else if (!rx3) {
						printf("               %s %s, (%u)", mn, x86_64_dec_r32(mrs), d);
					}
					else {
						printf("               %s %s, (%u)", mn, x86_64_dec_r64(mrs), d);
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b));
						}
						else {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b));
						}
						else {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b));
						}
						else {
							printf("                           %s %s, (%s)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s))", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s %s, (eip, -%u)", mn, x86_64_dec_r16(mrs), d);
							}
							else {
								printf("               %s %s, (rip, -%u)", mn, x86_64_dec_r16(mrs), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (eip, -%u)", mn, x86_64_dec_r32(mrs), d);
							}
							else {
								printf("               %s %s, (rip, -%u)", mn, x86_64_dec_r32(mrs), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (eip, -%u)", mn, x86_64_dec_r64(mrs), d);
							}
							else {
								printf("               %s %s, (rip, -%u)", mn, x86_64_dec_r64(mrs), d);
							}
						}
						*addr = *bn - d;
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s %s, (eip, %u)", mn, x86_64_dec_r16(mrs), d);
							}
							else {
								printf("               %s %s, (rip, %u)", mn, x86_64_dec_r16(mrs), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (eip, %u)", mn, x86_64_dec_r32(mrs), d);
							}
							else {
								printf("               %s %s, (rip, %u)", mn, x86_64_dec_r32(mrs), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (eip, %u)", mn, x86_64_dec_r64(mrs), d);
							}
							else {
								printf("               %s %s, (rip, %u)", mn, x86_64_dec_r64(mrs), d);
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s %s, (eip)", mn, x86_64_dec_r16(mrs));
						}
						else {
							printf("               %s %s, (rip)", mn, x86_64_dec_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (eip)", mn, x86_64_dec_r32(mrs));
						}
						else {
							printf("               %s %s, (rip)", mn, x86_64_dec_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (eip)", mn, x86_64_dec_r64(mrs));
						}
						else {
							printf("               %s %s, (rip)", mn, x86_64_dec_r64(mrs));
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(mrd));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %s %s, (%s, (%s), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), d);
							}
							else {
								printf("               %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %s %s, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %s %s, (%s, (%s), %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r16(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r32(mrs), x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (lgo) {
				printf("                              %s %s, %s", mn, x86_64_dec_r16(mrs), x86_64_dec_r16(mrd));
			}
			else if (!rx3) {
				printf("                              %s %s, %s", mn, x86_64_dec_r32(mrs), x86_64_dec_r32(mrd));
			}
			else if (rx3) {
				printf("                              %s %s, %s", mn, x86_64_dec_r64(mrs), x86_64_dec_r64(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_ral(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		printf("            %s al, %u", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rax(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn = *bn + 2;
			printf("         %s ax, %u", mn, k);
		}
		else if (!rx3) {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %s eax, %u", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %s rax, %u", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lga) {
					printf("            %sb (%u), %u", mn, d, k);
				}
				else {
					printf("            %sb (%u), %u", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lga) {
					printf("            %sb (%s), %u", mn, x86_64_dec_r32(b), k);
				}
				else {
					printf("            %sb (%s), %u", mn, x86_64_dec_r64(b), k);
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lga) {
					printf("            %sb (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
				}
				else {
					printf("            %sb (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
				}
			}
			else {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lga) {
					printf("            %sb (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
				}
				else {
					printf("            %sb (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d) {
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (eip, -%u), %u", mn, d, k);
					}
					else {
						printf("            %sb (rip, -%u), %u", mn, d, k);
					}
					*addr = *bn - d;
				}
				else {
					if (lga) {
						printf("            %sb (eip, %u), %u", mn, d, k);
					}
					else {
						printf("            %sb (rip, %u), %u", mn, d, k);
					}
					*addr = *bn + d;
				}
			}
			else {
				if (lga) {
					printf("            %sb (eip), %u", mn, k);
				}
				else {
					printf("            %sb (rip), %u", mn, k);
				}
				*addr = *bn;
			}
		}
		else {
			*bn = *bn + 1;
			printf("               %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (lga) {
				printf("            %sb (%s), %u", mn, x86_64_dec_r32(mrd), k);
			}
			else {
				printf("            %sb (%s), %u", mn, x86_64_dec_r64(mrd), k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lga) {
					printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
			else {
				if (lga) {
					printf("            %sb (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("            %sb (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lga) {
					printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
			else {
				if (lga) {
					printf("            %sb (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		if (rex) {
			printf("            %sb %s, %u", mn, x86_64_dec_r8x(mrd + (8 * rx2)), k);
		}
		else {
			printf("            %sb %s, %u", mn, x86_64_dec_r8(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					printf("         %sw (%u), %u", mn, d, k);
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					printf("   %sd (%u), %u", mn, d, k);
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					printf("   %sq (%u), %u", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("         %sw (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("   %sd (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("   %sq (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("         %sw (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("   %sd (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("   %sq (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("         %sw (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("   %sd (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("   %sq (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d) {
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lga) {
							printf("         %sw (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("         %sw (rip, -%u), %u", mn, d, k);
						}
						*addr = *bn - d;
					}
					else {
						if (lga) {
							printf("         %sw (eip, %u), %u", mn, d, k);
						}
						else {
							printf("         %sw (rip, %u), %u", mn, d, k);
						}
						*addr = *bn + d;
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lga) {
							printf("   %sd (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("   %sd (rip, -%u), %u", mn, d, k);
						}
						*addr = *bn - d;
					}
					else {
						if (lga) {
							printf("   %sd (eip, %u), %u", mn, d, k);
						}
						else {
							printf("   %sd (rip, %u), %u", mn, d, k);
						}
						*addr = *bn + d;
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lga) {
							printf("   %sq (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("   %sq (rip, -%u), %u", mn, d, k);
						}
						*addr = *bn - d;
					}
					else {
						if (lga) {
							printf("   %sq (eip, %u), %u", mn, d, k);
						}
						else {
							printf("   %sq (rip, %u), %u", mn, d, k);
						}
						*addr = *bn + d;
					}
				}
			}
			else {
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (eip), %u", mn, k);
					}
					else {
						printf("         %sw (rip), %u", mn, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (eip), %u", mn, k);
					}
					else {
						printf("   %sd (rip), %u", mn, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (eip), %u", mn, k);
					}
					else {
						printf("   %sq (rip), %u", mn, k);
					}
				}
				*addr = *bn;
			}
		}
		else {
			*bn = *bn + 1;
			if (lgo) {
				printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn = *bn + 2;
				if (lga) {
					printf("         %sw (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("         %sw (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
			else if (!rx3) {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lga) {
					printf("   %sd (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("   %sd (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
			else {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lga) {
					printf("   %sq (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("   %sq (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("         %sw (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("   %sd (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
					}
					else {
						printf("   %sq (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("         %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("   %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
					}
					else {
						printf("   %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("         %sw (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("   %sd (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
					}
					else {
						printf("   %sq (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (lgo) {
				printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn = *bn + 2;
				if (lga) {
					printf("         %sw (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("         %sw (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
			else if (!rx3) {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lga) {
					printf("   %sd (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("   %sd (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
			else {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lga) {
					printf("   %sq (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
				}
				else {
					printf("   %sq (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("         %sw (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("   %sd (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("   %sq (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
				else {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("         %sw (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("   %sd (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("   %sq (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("         %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("   %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("   %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
				else {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("         %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("   %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("   %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("         %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("   %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("   %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
				else {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn = *bn + 2;
						if (lga) {
							printf("         %sw (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("         %sw (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sd (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("   %sd (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn = *bn + 4;
						if (lga) {
							printf("   %sq (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("   %sq (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("         %sw (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("   %sd (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("   %sq (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
			else {
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn = *bn + 2;
					if (lga) {
						printf("         %sw (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("         %sw (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sd (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("   %sd (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lga) {
						printf("   %sq (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("   %sq (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (lgo) {
			printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn = *bn + 2;
			printf("         %sw %s, %u", mn, x86_64_dec_r16(mrd + (8 * rx2)), k);
		}
		else if (!rx3) {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %sd %s, %u", mn, x86_64_dec_r32(mrd + (8 * rx2)), k);
		}
		else {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %sq %s, %u", mn, x86_64_dec_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					printf("            %sw (%u), %u", mn, d, k);
				}
				else if (!rx3) {
					printf("            %sd (%u), %u", mn, d, k);
				}
				else {
					printf("            %sq (%u), %u", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("            %sw (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("            %sd (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s), %u", mn, x86_64_dec_r32(b), k);
					}
					else {
						printf("            %sq (%s), %u", mn, x86_64_dec_r64(b), k);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("            %sw (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("            %sd (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s, %u)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), k);
					}
					else {
						printf("            %sq (%s, (%s, %u)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), k);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("            %sw (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("            %sd (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s)), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), k);
					}
					else {
						printf("            %sq (%s, (%s)), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), k);
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d) {
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("            %sw (rip, -%u), %u", mn, d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("            %sd (rip, -%u), %u", mn, d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (eip, -%u), %u", mn, d, k);
						}
						else {
							printf("            %sq (rip, -%u), %u", mn, d, k);
						}
					}
					*addr = *bn - d;
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (eip, %u), %u", mn, d, k);
						}
						else {
							printf("            %sw (rip, %u), %u", mn, d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (eip, %u), %u", mn, d, k);
						}
						else {
							printf("            %sd (rip, %u), %u", mn, d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (eip, %u), %u", mn, d, k);
						}
						else {
							printf("            %sq (rip, %u), %u", mn, d, k);
						}
					}
					*addr = *bn + d;
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("            %sw (eip), %u", mn, k);
					}
					else {
						printf("            %sw (rip), %u", mn, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (eip), %u", mn, k);
					}
					else {
						printf("            %sd (rip), %u", mn, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (eip), %u", mn, k);
					}
					else {
						printf("            %sq (rip), %u", mn, k);
					}
				}
				*addr = *bn;
			}
		}
		else {
			*bn = *bn + 1;
			printf("               %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (lgo) {
				if (lga) {
					printf("            %sw (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("            %sw (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("            %sd (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("            %sd (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
			else {
				if (lga) {
					printf("            %sq (%s), %u", mn, x86_64_dec_r32(mrd), k);
				}
				else {
					printf("            %sq (%s), %u", mn, x86_64_dec_r64(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sw (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sq (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sw (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sq (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sw (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sq (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sw (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, %u), %u", mn, x86_64_dec_r32(b), d, k);
						}
						else {
							printf("            %sq (%s, %u), %u", mn, x86_64_dec_r64(b), d, k);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sw (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sq (%s, (%s, %u), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d, k);
						}
						else {
							printf("            %sq (%s, (%s, %u), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d, k);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn = *bn + 1;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sw (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sq (%s, (%s), -%u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("            %sw (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sw (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("            %sd (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
					else {
						if (lga) {
							printf("            %sq (%s, (%s), %u), %u", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d, k);
						}
						else {
							printf("            %sq (%s, (%s), %u), %u", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d, k);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn = *bn + 1;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sw (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sq (%s, -%u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sw (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, %u), %u", mn, x86_64_dec_r32(mrd), d, k);
					}
					else {
						printf("            %sq (%s, %u), %u", mn, x86_64_dec_r64(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		if (lgo) {
			printf("            %sw %s, %u", mn, x86_64_dec_r16(mrd + (8 * rx2)), k);
		}
		else if (!rx3) {
			printf("            %sd %s, %u", mn, x86_64_dec_r32(mrd + (8 * rx2)), k);
		}
		else {
			printf("            %sq %s, %u", mn, x86_64_dec_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_stck(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0); 
		*bn = *bn + 1;
		
		if (lgo) {
			printf("                                 %sw %s", mn, x86_64_dec_r16(reg));
		}
		else {
			printf("                                 %s %s", mn, x86_64_dec_r64(reg));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_mvp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0);
		*bn = *bn + 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		printf("            %s %s, %u", mn, x86_64_dec_r8(reg), k);
		
		return 0;
	}
	else if ((bin[*bn] & 248) == op + 8) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0);
		*bn = *bn + 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn = *bn + 2;
			printf("         %s %s, %u", mn, x86_64_dec_r16(reg), k);
		}
		else if (!rx3) {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %s %s, %u", mn, x86_64_dec_r32(reg), k);
		}
		else {
			printf("      %02x %02x %02x %02x %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3], bin[*bn + 4], bin[*bn + 5], bin[*bn + 6], bin[*bn + 7]);
			uint64_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24) + (bin[*bn + 4] << 32) + (bin[*bn + 5] << 40) + (bin[*bn + 6] << 48) + (bin[*bn + 7] << 56);
			*bn = *bn + 8;
			printf("   %s %s, %lu", mn, x86_64_dec_r64(reg), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_op_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn = *bn + 2;
			printf("         %sw %u", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			printf("   %s %u", mn, k);
		}
		return 0;
	}
	else if (bin[*bn] == op + 2) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		if (lgo) {
			printf("            %sw %u", mn, k);
		}
		else {
			printf("            %s %u", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_blnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lgo) {
					printf("               %sw (%u)", mn, d);
				}
				else {
					printf("               %s (%u)", mn, d);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sw (%s)", mn, x86_64_dec_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %s (%s)", mn, x86_64_dec_r64(b));
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %s (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %s (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sw (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %s (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %s (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %s (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %s (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %s (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %s (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %s (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %s (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %s (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %s (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %s (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %s (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %s (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %s (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %s (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %s (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %s (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %s (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (lgo) {
			printf("                              %sw %s", mn, x86_64_dec_r16(mrd));
		}
		else {
			printf("                              %s %s", mn, x86_64_dec_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_alnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("               %sb (%u)", mn, d);
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s)", mn, x86_64_dec_r32(b));
				}
				else {
					printf("                           %sb (%s)", mn, x86_64_dec_r64(b));
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
				}
				else {
					printf("                           %sb (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
				}
			}
			else {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
				}
				else {
					printf("                           %sb (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
				}
			}
		}
		else {
			*bn = *bn + 1;
			if (lga) {
				printf("                              %sb (%s)", mn, x86_64_dec_r32(mrd));
			}
			else {
				printf("                              %sb (%s)", mn, x86_64_dec_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, -%u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb (%s, -%u)", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, %u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb (%s, %u)", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lga) {
					printf("                        %sb (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %sb (%s, %u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, %u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, -%u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb (%s, -%u)", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, %u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb (%s, %u)", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lga) {
					printf("               %sb (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sb (%s, %u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, %u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (rex) {
			printf("                              %s %s", mn, x86_64_dec_r8x(mrd));
		}
		else {
			printf("                              %s %s", mn, x86_64_dec_r8(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lgo) {
					printf("               %sw (%u)", mn, d);
				}
				else if (!rx3) {
					printf("               %sd (%u)", mn, d);
				}
				else {
					printf("               %sq (%u)", mn, d);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sw (%s)", mn, x86_64_dec_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sd (%s)", mn, x86_64_dec_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sq (%s)", mn, x86_64_dec_r64(b));
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sq (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sq (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sw (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sd (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sq (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sq (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sq (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (lgo) {
			printf("                              %s %s", mn, x86_64_dec_r16(mrd));
		}
		else if (!rx3) {
			printf("                              %s %s", mn, x86_64_dec_r32(mrd));
		}
		else {
			printf("                              %s %s", mn, x86_64_dec_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_mlnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				printf("               %sb ax, (%u)", mn, d);
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb ax, (%s)", mn, x86_64_dec_r32(b));
				}
				else {
					printf("                           %sb ax, (%s)", mn, x86_64_dec_r64(b));
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb ax, (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
				}
				else {
					printf("                           %sb ax, (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
				}
			}
			else {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb ax, (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
				}
				else {
					printf("                           %sb ax, (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
				}
			}
		}
		else {
			*bn = *bn + 1;
			if (lga) {
				printf("                              %sb ax, (%s)", mn, x86_64_dec_r32(mrd));
			}
			else {
				printf("                              %sb ax, (%s)", mn, x86_64_dec_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb ax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb ax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb ax, (%s, %u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb ax, (%s, %u)", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb ax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb ax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lga) {
					printf("                        %sb ax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb ax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %sb ax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb ax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb ax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb ax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb ax, (%s, %u)", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb ax, (%s, %u)", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb ax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb ax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb ax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb ax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lga) {
					printf("               %sb ax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb ax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sb ax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb ax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (rex) {
			printf("                              %s ax, %s", mn, x86_64_dec_r8x(mrd));
		}
		else {
			printf("                              %s ax, %s", mn, x86_64_dec_r8(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lgo) {
					printf("               %sw ax, (%u)", mn, d);
				}
				else if (!rx3) {
					printf("               %sd eax, (%u)", mn, d);
				}
				else {
					printf("               %sq rax, (%u)", mn, d);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sw ax, (%s)", mn, x86_64_dec_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sd eax, (%s)", mn, x86_64_dec_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s)", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sq rax, (%s)", mn, x86_64_dec_r64(b));
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sw ax, (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sd eax, (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s, (%s, %u))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sq rax, (%s, (%s, %u))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sw ax, (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sd eax, (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s, (%s))", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sq rax, (%s, (%s))", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw ax, (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sw ax, (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd eax, (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sd eax, (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq rax, (%s)", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sq rax, (%s)", mn, x86_64_dec_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw ax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd eax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq rax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw ax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd eax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq rax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq rax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq rax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw ax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq rax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw ax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw ax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd eax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq rax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq rax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw ax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw ax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd eax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sd eax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq rax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sq rax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("                        %sw ax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sw ax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd eax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sd eax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq rax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                        %sq rax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw ax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd eax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, -%u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq rax, (%s, -%u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw ax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd eax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, %u)", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq rax, (%s, %u)", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw ax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd eax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq rax, (%s, (%s, %u), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw ax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd eax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, (%s, %u), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq rax, (%s, (%s, %u), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw ax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd eax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, (%s), -%u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq rax, (%s, (%s), -%u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw ax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw ax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd eax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd eax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq rax, (%s, (%s), %u)", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq rax, (%s, (%s), %u)", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("               %sw ax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw ax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd eax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd eax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq rax, (%s, -%u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq rax, (%s, -%u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw ax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw ax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd eax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd eax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq rax, (%s, %u)", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq rax, (%s, %u)", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (lgo) {
			printf("                              %s ax, %s", mn, x86_64_dec_r16(mrd));
		}
		else if (!rx3) {
			printf("                              %s eax, %s", mn, x86_64_dec_r32(mrd));
		}
		else {
			printf("                              %s rax, %s", mn, x86_64_dec_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_byt_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn = *bn + 1;
		
		if (k & 128) {
			k = ~k + 1;
			printf("            %s -%u", mn, k);
			*addr = *bn - k;
		}
		else {
			printf("            %s %u", mn, k);
			*addr = *bn + k;
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_cond(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == 15 && bin[*bn + 1] == op) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn = *bn + 2;
		
		printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn = *bn + 4;
		
		if (k & 2147483648) {
			k = ~k + 1;
			printf("   %s -%u", mn, k);
			*addr = *bn - k;
		}
		else {
			printf("   %s %u", mn, k);
			*addr = *bn + k;
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_jmp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn = *bn + 2;
			if (k & 32768) {
				printf("         %sw -%u", mn, k);
				*addr = *bn - k;
			}
			else {
				printf("         %sw %u", mn, k);
				*addr = *bn + k;
			}
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (k & 2147483648) {
				k = ~k + 1;
				printf("   %s -%u", mn, k);
				*addr = *bn - k;
			}
			else {
				printf("   %s %u", mn, k);
				*addr = *bn + k;
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lga) {
					printf("               %sb (%u), 1", mn, d);
				}
				else {
					printf("               %sb (%u), 1", mn, d);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s), 1", mn, x86_64_dec_r32(b));
				}
				else {
					printf("                           %sb (%s), 1", mn, x86_64_dec_r64(b));
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s, (%s, %u)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
				}
				else {
					printf("                           %sb (%s, (%s, %u)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
				}
			}
			else {
				*bn = *bn + 1;
				if (lga) {
					printf("                           %sb (%s, (%s)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
				}
				else {
					printf("                           %sb (%s, (%s)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d) {
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (eip, -%u), 1", mn, d);
					}
					else {
						printf("               %sb (rip, -%u), 1", mn, d);
					}
					*addr = *bn - d;
				}
				else {
					if (lga) {
						printf("               %sb (eip, %u), 1", mn, d);
					}
					else {
						printf("               %sb (rip, %u), 1", mn, d);
					}
					*addr = *bn + d;
				}
			}
			else {
				if (lga) {
					printf("               %sb (eip), 1", mn);
				}
				else {
					printf("               %sb (rip), 1", mn);
				}
				*addr = *bn;
			}
		}
		else {
			*bn = *bn + 1;
			if (lga) {
				printf("                              %sb (%s), 1", mn, x86_64_dec_r32(mrd));
			}
			else {
				printf("                              %sb (%s), 1", mn, x86_64_dec_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, %u), 1", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("                        %sb (%s, %u), 1", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lga) {
						printf("                        %sb (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lga) {
					printf("                        %sb (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %sb (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, %u), 1", mn, x86_64_dec_r32(b), d);
					}
					else {
						printf("               %sb (%s, %u), 1", mn, x86_64_dec_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lga) {
						printf("               %sb (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lga) {
					printf("               %sb (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sb (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (rex) {
			printf("                              %sb %s, 1", mn, x86_64_dec_r8x(mrd + (8 * rx2)));
		}
		else {
			printf("                              %sb %s, 1", mn, x86_64_dec_r8(mrd + (8 * rx2)));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (lgo) {
					printf("               %sw (%u), 1", mn, d);
				}
				else if (!rx3) {
					printf("               %sd (%u), 1", mn, d);
				}
				else {
					printf("               %sq (%u), 1", mn, d);
				}
			}
			else if (i == 4) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s), 1", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sw (%s), 1", mn, x86_64_dec_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s), 1", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sd (%s), 1", mn, x86_64_dec_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s), 1", mn, x86_64_dec_r32(b));
					}
					else {
						printf("                           %sq (%s), 1", mn, x86_64_dec_r64(b));
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s, %u)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s, %u)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
					}
					else {
						printf("                           %sq (%s, (%s, %u)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
					}
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s)), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
					}
					else {
						printf("                           %sq (%s, (%s)), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d) {
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (eip, -%u), 1", mn, d);
						}
						else {
							printf("               %sw (rip, -%u), 1", mn, d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (eip, -%u), 1", mn, d);
						}
						else {
							printf("               %sd (rip, -%u), 1", mn, d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (eip, -%u), 1", mn, d);
						}
						else {
							printf("               %sq (rip, -%u), 1", mn, d);
						}
					}
					*addr = *bn - d;
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (eip, %u), 1", mn, d);
						}
						else {
							printf("               %sw (rip, %u), 1", mn, d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (eip, %u), 1", mn, d);
						}
						else {
							printf("               %sd (rip, %u), 1", mn, d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (eip, %u), 1", mn, d);
						}
						else {
							printf("               %sq (rip, %u), 1", mn, d);
						}
					}
					*addr = *bn + d;
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw (eip), 1", mn);
					}
					else {
						printf("               %sw (rip), 1", mn);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (eip), 1", mn);
					}
					else {
						printf("               %sd (rip), 1", mn);
					}
				}
				else {
					if (lga) {
						printf("               %sq (eip), 1", mn);
					}
					else {
						printf("               %sq (rip), 1", mn);
					}
				}
				*addr = *bn;
			}
		}
		else {
			*bn = *bn + 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s), 1", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sw (%s), 1", mn, x86_64_dec_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd (%s), 1", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sd (%s), 1", mn, x86_64_dec_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq (%s), 1", mn, x86_64_dec_r32(mrd));
				}
				else {
					printf("                              %sq (%s), 1", mn, x86_64_dec_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sw (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("                        %sq (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("                        %sq (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("                        %sq (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn = *bn + 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("                         %sw (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sw (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                         %sd (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sd (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                         %sq (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sq (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("                         %sw (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sw (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                         %sd (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sd (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                         %sq (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("                         %sq (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn = *bn + 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, -%u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq (%s, -%u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sw (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, %u), 1", mn, x86_64_dec_r32(b), d);
						}
						else {
							printf("               %sq (%s, %u), 1", mn, x86_64_dec_r64(b), d);
						}
					}
				}
			}
			else if (s) {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq (%s, (%s, %u), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s, %u), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
						}
						else {
							printf("               %sq (%s, (%s, %u), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s), -%u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq (%s, (%s), -%u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s), %u), 1", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
						}
						else {
							printf("               %sq (%s, (%s), %u), 1", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
						}
					}
				}
			}
		}
		else {
			*bn = *bn + 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn = *bn + 4;
			if (d & 2147483648) {
				d = ~d + 1;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, -%u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq (%s, -%u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, %u), 1", mn, x86_64_dec_r32(mrd), d);
					}
					else {
						printf("               %sq (%s, %u), 1", mn, x86_64_dec_r64(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn = *bn + 1;
		if (lgo) {
			printf("                              %sw %s, 1", mn, x86_64_dec_r16(mrd + (8 * rx2)));
		}
		else if (!rx3) {
			printf("                              %sd %s, 1", mn, x86_64_dec_r32(mrd + (8 * rx2)));
		}
		else {
			printf("                              %sq %s, 1", mn, x86_64_dec_r64(mrd + (8 * rx2)));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_r8(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (rex) {
						printf("               %sb (%u), cl", mn, d);
					}
					else {
						printf("               %sb (%u), cl", mn, d);
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s), cl", mn, x86_64_dec_r32(b));
						}
						else {
							printf("                           %sb (%s), cl", mn, x86_64_dec_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s), cl", mn, x86_64_dec_r32(b));
						}
						else {
							printf("                           %sb (%s), cl", mn, x86_64_dec_r64(b));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s, (%s, %u)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %sb (%s, (%s, %u)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s, (%s, %u)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %sb (%s, (%s, %u)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s, (%s)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %sb (%s, (%s)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s, (%s)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %sb (%s, (%s)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %sb (eip, -%u), cl", mn, d);
							}
							else {
								printf("               %sb (rip, -%u), cl", mn, d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (eip, -%u), cl", mn, d);
							}
							else {
								printf("               %sb (rip, -%u), cl", mn, d);
							}
						}
						*addr = *bn - d;
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %sb (eip, %u), cl", mn, d);
							}
							else {
								printf("               %sb (rip, %u), cl", mn, d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (eip, %u), cl", mn, d);
							}
							else {
								printf("               %sb (rip, %u), cl", mn, d);
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %sb (eip), cl", mn);
						}
						else {
							printf("               %sb (rip), cl", mn);
						}
					}
					else {
						if (lga) {
							printf("               %sb (eip), cl", mn);
						}
						else {
							printf("               %sb (rip), cl", mn);
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (rex) {
					if (lga) {
						printf("                              %sb (%s), cl", mn, x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %sb (%s), cl", mn, x86_64_dec_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %sb (%s), cl", mn, x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %sb (%s), cl", mn, x86_64_dec_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("                        %sb (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sb (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sb (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sb (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sb (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sb (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %sb (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sb (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sb (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sb (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sb (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (rex) {
							if (lga) {
								printf("               %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sb (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (rex) {
							if (lga) {
								printf("               %sb (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sb (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %sb (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sb (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sb (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %sb (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sb (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sb (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (rex) {
				printf("                              %sb %s, cl", mn, x86_64_dec_r8x(mrd));
			}
			else {
				printf("                              %sb %s, cl", mn, x86_64_dec_r8(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_reg(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (lgo) {
						printf("               %sw (%u), cl", mn, d);
					}
					else if (!rx3) {
						printf("               %sd (%u), cl", mn, d);
					}
					else {
						printf("               %sq (%u), cl", mn, d);
					}
				}
				else if (i == 4) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s), cl", mn, x86_64_dec_r32(b));
						}
						else {
							printf("                           %sw (%s), cl", mn, x86_64_dec_r64(b));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s), cl", mn, x86_64_dec_r32(b));
						}
						else {
							printf("                           %sd (%s), cl", mn, x86_64_dec_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s), cl", mn, x86_64_dec_r32(b));
						}
						else {
							printf("                           %sq (%s), cl", mn, x86_64_dec_r64(b));
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s, (%s, %u)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %sw (%s, (%s, %u)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s, (%s, %u)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %sd (%s, (%s, %u)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s, (%s, %u)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s));
						}
						else {
							printf("                           %sq (%s, (%s, %u)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s));
						}
					}
				}
				else {
					*bn = *bn + 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s, (%s)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %sw (%s, (%s)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s, (%s)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %sd (%s, (%s)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s, (%s)), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i));
						}
						else {
							printf("                           %sq (%s, (%s)), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d) {
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %sw (eip, -%u), cl", mn, d);
							}
							else {
								printf("               %sw (rip, -%u), cl", mn, d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (eip, -%u), cl", mn, d);
							}
							else {
								printf("               %sd (rip, -%u), cl", mn, d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (eip, -%u), cl", mn, d);
							}
							else {
								printf("               %sq (rip, -%u), cl", mn, d);
							}
						}
						*addr = *bn - d;
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %sw (eip, %u), cl", mn, d);
							}
							else {
								printf("               %sw (rip, %u), cl", mn, d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (eip, %u), cl", mn, d);
							}
							else {
								printf("               %sd (rip, %u), cl", mn, d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (eip, %u), cl", mn, d);
							}
							else {
								printf("               %sq (rip, %u), cl", mn, d);
							}
						}
						*addr = *bn + d;
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (eip), cl", mn);
						}
						else {
							printf("               %sw (rip), cl", mn);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (eip), cl", mn);
						}
						else {
							printf("               %sd (rip), cl", mn);
						}
					}
					else {
						if (lga) {
							printf("               %sq (eip), cl", mn);
						}
						else {
							printf("               %sq (rip), cl", mn);
						}
					}
					*addr = *bn;
				}
			}
			else {
				*bn = *bn + 1;
				if (lgo) {
					if (lga) {
						printf("                              %sw (%s), cl", mn, x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %sw (%s), cl", mn, x86_64_dec_r64(mrd));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %sd (%s), cl", mn, x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %sd (%s), cl", mn, x86_64_dec_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %sq (%s), cl", mn, x86_64_dec_r32(mrd));
					}
					else {
						printf("                              %sq (%s), cl", mn, x86_64_dec_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sw (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sd (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sq (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sw (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sd (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("                        %sq (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sw (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sd (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sq (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sw (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sd (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("                        %sq (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn = *bn + 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sw (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sd (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sq (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("                        %sw (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sw (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("                        %sd (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sd (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("                        %sq (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("                        %sq (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn = *bn + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sw (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sd (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sq (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sw (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sd (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("                        %sq (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn = *bn + 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sw (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sd (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, -%u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sq (%s, -%u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sw (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sd (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, %u), cl", mn, x86_64_dec_r32(b), d);
							}
							else {
								printf("               %sq (%s, %u), cl", mn, x86_64_dec_r64(b), d);
							}
						}
					}
				}
				else if (s) {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sw (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sd (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sq (%s, (%s, %u), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sw (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sd (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, (%s, %u), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), x86_64_dec_s8(s), d);
							}
							else {
								printf("               %sq (%s, (%s, %u), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), x86_64_dec_s8(s), d);
							}
						}
					}
				}
				else {
					*bn = *bn + 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn = *bn + 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sw (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sd (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, (%s), -%u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sq (%s, (%s), -%u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
					else {
						if (lgo) {
							if (lga) {
								printf("               %sw (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sw (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else if (!rx3) {
							if (lga) {
								printf("               %sd (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sd (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
						else {
							if (lga) {
								printf("               %sq (%s, (%s), %u), cl", mn, x86_64_dec_r32(b), x86_64_dec_r32(i), d);
							}
							else {
								printf("               %sq (%s, (%s), %u), cl", mn, x86_64_dec_r64(b), x86_64_dec_r64(i), d);
							}
						}
					}
				}
			}
			else {
				*bn = *bn + 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn = *bn + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sw (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sd (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, -%u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sq (%s, -%u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sw (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sd (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, %u), cl", mn, x86_64_dec_r32(mrd), d);
						}
						else {
							printf("               %sq (%s, %u), cl", mn, x86_64_dec_r64(mrd), d);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			*bn = *bn + 1;
			if (lgo) {
				printf("                              %sw %s, cl", mn, x86_64_dec_r16(mrd));
			}
			else if (!rx3) {
				printf("                              %sd %s, cl", mn, x86_64_dec_r32(mrd));
			}
			else {
				printf("                              %sq %s, cl", mn, x86_64_dec_r64(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_byt(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
		
		printf("                                 %s", mn);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_sys(uint8_t* bin, uint64_t* bn) {
	if (bin[*bn] == 15 && bin[*bn + 1] == 5) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn = *bn + 2;
		
		printf("                              syscall");
		return 0;
	}
	return 1;
}

void x86_64_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	uint8_t lga = 0;
	uint8_t lgo = 0;
	uint8_t rex = 0;
	uint8_t rx0 = 0;
	uint8_t rx1 = 0;
	uint8_t rx2 = 0;
	uint8_t rx3 = 0;
	
	if (bin[*bn] == 102) { //leg addr
		printf("66 ");
		lgo = 1;
		*bn = *bn + 1;
	}
	else {
		printf("   ");
	}
	
	if (bin[*bn] == 103) { //leg op
		printf("67 ");
		lga = 1;
		*bn = *bn + 1;
	}
	else {
		printf("   ");
	}
	
	if ((bin[*bn] & 240) == 64) { //rex
		printf("%02x ", bin[*bn]);
		rex = 1;
		if (bin[*bn] & 1) {
			rx0 = 1;
		}
		if (bin[*bn] & 2) {
			rx1 = 1;
		}
		if (bin[*bn] & 4) {
			rx2 = 1;
		}
		if (bin[*bn] & 8) {
			rx3 = 1;
		}
		*bn = *bn + 1;
	}
	else {
		printf("   ");
	}
	
	uint8_t eo = 1;
	
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 1, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 2, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 3, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 4, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 5, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 9, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 10, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 11, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 12, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 13, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 17, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 18, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 19, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 20, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 21, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 25, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 26, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 27, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 28, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 29, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 33, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 34, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 35, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 36, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 37, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 41, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 42, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 43, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 44, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 45, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 49, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 50, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 51, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 52, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 53, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 57, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 58, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 59, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 60, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 61, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 80, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 88, "pop", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_op_imm(bin, bn, addr, 104, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 112, "jo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 113, "jno", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 114, "jc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 115, "jnc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 116, "je", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 117, "jne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 118, "jna", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 119, "ja", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 120, "js", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 121, "jns", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 122, "jpe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 123, "jpo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 124, "jl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 125, "jge", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 126, "jle", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 127, "jg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 134, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 135, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 136, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 137, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 138, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 139, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 141, "lea", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 143, 0, "pop", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 144, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 156, "pushf", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 157, "popf", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 158, "sahf ah", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 159, "lahf ah", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mvp(bin, bn, addr, 176, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 195, "ret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 198, 0, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 199, 0, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 204, "int 3", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt_imm(bin, bn, addr, 205, "int", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 206, "into", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 207, "iret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 232, "call", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 233, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 235, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 240, "lock", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 241, "icebp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 242, "repne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 243, "repe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 244, "hlt", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 245, "cmc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 246, 2, "not", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 246, 3, "neg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 4, "mul", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 5, "imul", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 6, "div", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 7, "idiv", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 248, "clc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 249, "stc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 250, "cli", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 251, "sti", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 252, "cld", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 253, "std", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 254, 0, "inc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 254, 1, "dec", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 2, "call", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 4, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 6, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_sys(bin, bn);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 128, "jo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 129, "jno", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 130, "jc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 131, "jnc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 132, "je", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 133, "jne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 134, "jna", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 135, "ja", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 136, "js", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 137, "jns", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 138, "jpe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 139, "jpo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 140, "jl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 141, "jge", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 142, "jle", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 143, "jg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn = *bn + 1;
	}
}

void x86_64_reg_set_ip(uint8_t* bin, uint64_t bn, uint64_t ip) {
	if (ip >= bn || ip < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		ip = ip - 138;
		bin[128] = ip;
		bin[129] = ip >> 8;
		bin[130] = ip >> 16;
		bin[131] = ip >> 24;
		bin[132] = ip >> 32;
		bin[133] = ip >> 40;
		bin[134] = ip >> 48;
		bin[135] = ip >> 56;
	}
}

uint32_t x86_64_inc_addr_u32(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t i, uint8_t s, uint32_t d) {
	uint32_t addr;
	uint32_t base = bin[b] + (bin[b + 1] << 8) + (bin[b + 2] << 16) + (bin[b + 3] << 24);
	uint32_t index = bin[i] + (bin[i + 1] << 8) + (bin[i + 2] << 16) + (bin[i + 3] << 24);
	if (i == 32) {
		addr = base + d;
	}
	else if (s == 0) {
		addr = base + index + d;
	}
	else if (s == 1) {
		addr = base + (index * 2) + d;
	}
	else if (s == 2) {
		addr = base + (index * 4) + d;
	}
	else {
		addr = base + (index * 8) + d;
	}
	return addr;
}

uint32_t x86_64_inc_addr_s32(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t i, uint8_t s, uint32_t d) {
	uint32_t addr;
	uint32_t base = bin[b] + (bin[b + 1] << 8) + (bin[b + 2] << 16) + (bin[b + 3] << 24);
	uint32_t index = bin[i] + (bin[i + 1] << 8) + (bin[i + 2] << 16) + (bin[i + 3] << 24);
	if (i == 32) {
		addr = base - d;
	}
	else if (s == 0) {
		addr = base + index - d;
	}
	else if (s == 1) {
		addr = base + (index * 2) - d;
	}
	else if (s == 2) {
		addr = base + (index * 4) - d;
	}
	else {
		addr = base + (index * 8) - d;
	}
	return addr;
}

uint64_t x86_64_inc_addr_u64(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t i, uint8_t s, uint32_t d) {
	uint64_t addr;
	uint64_t base = bin[b] + (bin[b + 1] << 8) + (bin[b + 2] << 16) + (bin[b + 3] << 24) + (bin[b + 4] << 32) + (bin[b + 5] << 40) + (bin[b + 6] << 48) + (bin[b + 7] << 56);
	uint64_t index = bin[i] + (bin[i + 1] << 8) + (bin[i + 2] << 16) + (bin[i + 3] << 24) + (bin[i + 4] << 32) + (bin[i + 5] << 40) + (bin[i + 6] << 48) + (bin[i + 7] << 56);
	if (i == 32) {
		addr = base + d;
	}
	else if (s == 0) {
		addr = base + index + d;
	}
	else if (s == 1) {
		addr = base + (index * 2) + d;
	}
	else if (s == 2) {
		addr = base + (index * 4) + d;
	}
	else {
		addr = base + (index * 8) + d;
	}
	return addr;
}

uint64_t x86_64_inc_addr_s64(uint8_t* bin, uint64_t bn, uint8_t b, uint8_t i, uint8_t s, uint32_t d) {
	uint64_t addr;
	uint64_t base = bin[b] + (bin[b + 1] << 8) + (bin[b + 2] << 16) + (bin[b + 3] << 24) + (bin[b + 4] << 32) + (bin[b + 5] << 40) + (bin[b + 6] << 48) + (bin[b + 7] << 56);
	uint64_t index = bin[i] + (bin[i + 1] << 8) + (bin[i + 2] << 16) + (bin[i + 3] << 24) + (bin[i + 4] << 32) + (bin[i + 5] << 40) + (bin[i + 6] << 48) + (bin[i + 7] << 56);
	if (i == 32) {
		addr = base - d;
	}
	else if (s == 0) {
		addr = base + index - d;
	}
	else if (s == 1) {
		addr = base + (index * 2) - d;
	}
	else if (s == 2) {
		addr = base + (index * 4) - d;
	}
	else {
		addr = base + (index * 8) - d;
	}
	return addr;
}

uint8_t x86_64_parity_flag(uint8_t byt, uint8_t pf) {
	if (byt & 1) {
		pf = !pf << 2;
	}
	if (byt & 2) {
		pf = !pf << 2;
	}
	if (byt & 4) {
		pf = !pf << 2;
	}
	if (byt & 8) {
		pf = !pf << 2;
	}
	if (byt & 16) {
		pf = !pf << 2;
	}
	if (byt & 32) {
		pf = !pf << 2;
	}
	if (byt & 64) {
		pf = !pf << 2;
	}
	if (byt & 128) {
		pf = !pf << 2;
	}
	return pf;
}

void x86_64_inc_add_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src]) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src], 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15)) & 16;
		uint8_t zf = !(bin[dst] + bin[src]) << 6;
		uint8_t sf = (bin[dst] + bin[src]) & 128;
		uint8_t of = ((bin[dst] & 128) && (bin[src] & 128)) << 3;
		bin[dst] = bin[dst] + bin[src];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src]) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src], 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15)) & 16;
		uint8_t zf = !(bin[dst] + bin[src]) << 6;
		bin[dst] = bin[dst] + bin[src];
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + bin[src + 1] + car) & 128;
		uint8_t of = ((bin[dst + 1] & 128) && (bin[src + 1] & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src]) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src], 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15)) & 16;
		uint8_t zf = !(bin[dst] + bin[src]) << 6;
		bin[dst] = bin[dst] + bin[src];
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		car = cf;
		
		cf = ((bin[dst + 2] + bin[src + 2] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + bin[src + 2] + car, pf);
		zf = (!(bin[dst + 2] + bin[src + 2] + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + bin[src + 2] + car;
		car = cf;
		
		cf = ((bin[dst + 3] + bin[src + 3] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + bin[src + 3] + car, pf);
		zf = (!(bin[dst + 3] + bin[src + 3] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + bin[src + 3] + car) & 128;
		uint8_t of = ((bin[dst + 3] & 128) && (bin[src + 3] & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + bin[src + 3] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src]) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src], 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15)) & 16;
		uint8_t zf = !(bin[dst] + bin[src]) << 6;
		bin[dst] = bin[dst] + bin[src];
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		car = cf;
		
		cf = ((bin[dst + 2] + bin[src + 2] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + bin[src + 2] + car, pf);
		zf = (!(bin[dst + 2] + bin[src + 2] + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + bin[src + 2] + car;
		car = cf;
		
		cf = ((bin[dst + 3] + bin[src + 3] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + bin[src + 3] + car, pf);
		zf = (!(bin[dst + 3] + bin[src + 3] + car) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + bin[src + 3] + car;
		car = cf;
		
		cf = ((bin[dst + 4] + bin[src + 4] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 4] + bin[src + 4] + car, pf);
		zf = (!(bin[dst + 4] + bin[src + 4] + car) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] + bin[src + 4] + car;
		car = cf;
		
		cf = ((bin[dst + 5] + bin[src + 5] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 5] + bin[src + 5] + car, pf);
		zf = (!(bin[dst + 5] + bin[src + 5] + car) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] + bin[src + 5] + car;
		car = cf;
		
		cf = ((bin[dst + 6] + bin[src + 6] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 6] + bin[src + 6] + car, pf);
		zf = (!(bin[dst + 6] + bin[src + 6] + car) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] + bin[src + 6] + car;
		car = cf;
		
		cf = ((bin[dst + 7] + bin[src + 7] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 7] + bin[src + 7] + car, pf);
		zf = (!(bin[dst + 7] + bin[src + 7] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 7] + bin[src + 7] + car) & 128;
		uint8_t of = ((bin[dst + 7] & 128) && (bin[src + 7] & 128)) << 3;
		bin[dst + 7] = bin[dst + 7] + bin[src + 7] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + imm) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + imm, 1);
		uint8_t af = ((bin[dst] & 15) + (imm & 15)) & 16;
		uint8_t zf = !(bin[dst] + imm) << 6;
		uint8_t sf = (bin[dst] + imm) & 128;
		uint8_t of = ((bin[dst] & 128) && (imm & 128)) << 3;
		bin[dst] = bin[dst] + imm;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255)) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255), 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15)) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255)) << 6;
		bin[dst] = bin[dst] + (imm & 255);
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + (imm >> 8) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + (imm >> 8) + car, pf);
		zf = (!(bin[dst + 1] + (imm >> 8) + car) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + (imm >> 8) + car) & 128;
		uint8_t of = ((bin[dst + 1] & 128) && ((imm >> 8) & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + (imm >> 8) + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255)) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255), 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15)) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255)) << 6;
		bin[dst] = bin[dst] + (imm & 255);
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + ((imm >> 8) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ((imm >> 8) & 255) + car, pf);
		zf = (!(bin[dst + 1] + ((imm >> 8) & 255) + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ((imm >> 8) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 2] + ((imm >> 16) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ((imm >> 16) & 255) + car, pf);
		zf = (!(bin[dst + 2] + ((imm >> 16) & 255) + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ((imm >> 16) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 3] + ((imm >> 24) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ((imm >> 24) & 255) + car, pf);
		zf = (!(bin[dst + 3] + ((imm >> 24) & 255) + car) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ((imm >> 24) & 255) + car) & 128;
		uint8_t of = ((bin[dst + 3] & 128) && (((imm >> 24) & 255) & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ((imm >> 24) & 255) + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_add_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255)) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255), 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15)) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255)) << 6;
		bin[dst] = bin[dst] + (imm & 255);
		uint8_t car = cf;
		
		cf = ((bin[dst + 1] + ((imm >> 8) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ((imm >> 8) & 255) + car, pf);
		zf = (!(bin[dst + 1] + ((imm >> 8) & 255) + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ((imm >> 8) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 2] + ((imm >> 16) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ((imm >> 16) & 255) + car, pf);
		zf = (!(bin[dst + 2] + ((imm >> 16) & 255) + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ((imm >> 16) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 3] + ((imm >> 24) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ((imm >> 24) & 255) + car, pf);
		zf = (!(bin[dst + 3] + ((imm >> 24) & 255) + car) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ((imm >> 24) & 255) + car;
		car = cf;
		
		cf = 0;
		pf = x86_64_parity_flag(car, pf);
		zf = (!car && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		uint8_t of = 0;
		bin[dst + 4] = car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | bin[src]) << 6;
		uint8_t sf = (bin[dst] | bin[src]) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] | bin[src];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] | bin[src + 1], pf);
		zf = (!(bin[dst + 1] | bin[src + 1]) && zf) << 6;
		uint8_t sf = (bin[dst + 1] | bin[src + 1]) & 128;
		bin[dst + 1] = bin[dst + 1] | bin[src + 1];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] | bin[src + 1], pf);
		zf = (!(bin[dst + 1] | bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] | bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] | bin[src + 2], pf);
		zf = (!(bin[dst + 2] | bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] | bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] | bin[src + 3], pf);
		zf = (!(bin[dst + 3] | bin[src + 3]) && zf) << 6;
		uint8_t sf = (bin[dst + 3] | bin[src + 3]) & 128;
		bin[dst + 3] = bin[dst + 3] | bin[src + 3];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] | bin[src + 1], pf);
		zf = (!(bin[dst + 1] | bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] | bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] | bin[src + 2], pf);
		zf = (!(bin[dst + 2] | bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] | bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] | bin[src + 3], pf);
		zf = (!(bin[dst + 3] | bin[src + 3]) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] | bin[src + 3];
		
		pf = x86_64_parity_flag(bin[dst + 4] | bin[src + 4], pf);
		zf = (!(bin[dst + 4] | bin[src + 4]) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] | bin[src + 4];
		
		pf = x86_64_parity_flag(bin[dst + 5] | bin[src + 5], pf);
		zf = (!(bin[dst + 5] | bin[src + 5]) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] | bin[src + 5];
		
		pf = x86_64_parity_flag(bin[dst + 6] | bin[src + 6], pf);
		zf = (!(bin[dst + 6] | bin[src + 6]) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] | bin[src + 6];
		
		pf = x86_64_parity_flag(bin[dst + 7] | bin[src + 7], pf);
		zf = (!(bin[dst + 7] | bin[src + 7]) && zf) << 6;
		uint8_t sf = (bin[dst + 7] | bin[src + 7]) & 128;
		bin[dst + 7] = bin[dst + 7] | bin[src + 7];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | imm, 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | imm) << 6;
		uint8_t sf = (bin[dst] | imm) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] | imm;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] | (imm >> 8), pf);
		zf = (!(bin[dst + 1] | (imm >> 8)) && zf) << 6;
		uint8_t sf = (bin[dst + 1] | (imm >> 8)) & 128;
		bin[dst + 1] = bin[dst + 1] | (imm >> 8);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] | ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] | ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] | ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 2] | ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] | ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] | ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 3] | ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] | ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = (bin[dst + 3] | ((imm >> 24) & 255)) & 128;
		bin[dst + 3] = bin[dst + 3] | ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_or_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] | (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] | (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] | (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] | ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] | ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] | ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 2] | ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] | ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] | ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 3] | ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] | ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		bin[dst + 3] = bin[dst + 3] | ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src] + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src] + car, 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + bin[src] + car) << 6;
		uint8_t sf = (bin[dst] + bin[src] + car) & 128;
		uint8_t of = ((bin[dst] & 128) && (bin[src] & 128)) << 3;
		bin[dst] = bin[dst] + bin[src] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src] + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src] + car, 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + bin[src] + car) << 6;
		bin[dst] = bin[dst] + bin[src] + car;
		car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + bin[src + 1] + car) & 128;
		uint8_t of = ((bin[dst + 1] & 128) && (bin[src + 1] & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src] + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src] + car, 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + bin[src] + car) << 6;
		bin[dst] = bin[dst] + bin[src]  + car;
		car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		car = cf;
		
		cf = ((bin[dst + 2] + bin[src + 2] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + bin[src + 2] + car, pf);
		zf = (!(bin[dst + 2] + bin[src + 2] + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + bin[src + 2] + car;
		car = cf;
		
		cf = ((bin[dst + 3] + bin[src + 3] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + bin[src + 3] + car, pf);
		zf = (!(bin[dst + 3] + bin[src + 3] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + bin[src + 3] + car) & 128;
		uint8_t of = ((bin[dst + 3] & 128) && (bin[src + 3] & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + bin[src + 3] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + bin[src] + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + bin[src] + car, 1);
		uint8_t af = ((bin[dst] & 15) + (bin[src] & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + bin[src] + car) << 6;
		bin[dst] = bin[dst] + bin[src] + car;
		car = cf;
		
		cf = ((bin[dst + 1] + bin[src + 1] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + bin[src + 1] + car, pf);
		zf = (!(bin[dst + 1] + bin[src + 1] + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + bin[src + 1] + car;
		car = cf;
		
		cf = ((bin[dst + 2] + bin[src + 2] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + bin[src + 2] + car, pf);
		zf = (!(bin[dst + 2] + bin[src + 2] + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + bin[src + 2] + car;
		car = cf;
		
		cf = ((bin[dst + 3] + bin[src + 3] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + bin[src + 3] + car, pf);
		zf = (!(bin[dst + 3] + bin[src + 3] + car) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + bin[src + 3] + car;
		car = cf;
		
		cf = ((bin[dst + 4] + bin[src + 4] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 4] + bin[src + 4] + car, pf);
		zf = (!(bin[dst + 4] + bin[src + 4] + car) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] + bin[src + 4] + car;
		car = cf;
		
		cf = ((bin[dst + 5] + bin[src + 5] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 5] + bin[src + 5] + car, pf);
		zf = (!(bin[dst + 5] + bin[src + 5] + car) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] + bin[src + 5] + car;
		car = cf;
		
		cf = ((bin[dst + 6] + bin[src + 6] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 6] + bin[src + 6] + car, pf);
		zf = (!(bin[dst + 6] + bin[src + 6] + car) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] + bin[src + 6] + car;
		car = cf;
		
		cf = ((bin[dst + 7] + bin[src + 7] + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 7] + bin[src + 7] + car, pf);
		zf = (!(bin[dst + 7] + bin[src + 7] + car) && zf) << 6;
		uint8_t sf = (bin[dst + 7] + bin[src + 7] + car) & 128;
		uint8_t of = ((bin[dst + 7] & 128) && (bin[src + 7] & 128)) << 3;
		bin[dst + 7] = bin[dst + 7] + bin[src + 7] + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + imm + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + imm + car, 1);
		uint8_t af = ((bin[dst] & 15) + (imm & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + imm + car) << 6;
		uint8_t sf = (bin[dst] + imm + car) & 128;
		uint8_t of = ((bin[dst] & 128) && (imm & 128)) << 3;
		bin[dst] = bin[dst] + imm + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255) + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255) + car, 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255) + car) << 6;
		bin[dst] = bin[dst] + (imm & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 1] + (imm >> 8) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + (imm >> 8) + car, pf);
		zf = (!(bin[dst + 1] + (imm >> 8) + car) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + (imm >> 8) + car) & 128;
		uint8_t of = ((bin[dst + 1] & 128) && ((imm >> 8) & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + (imm >> 8) + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255) + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255) + car, 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255) + car) << 6;
		bin[dst] = bin[dst] + (imm & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 1] + ((imm >> 8) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ((imm >> 8) & 255) + car, pf);
		zf = (!(bin[dst + 1] + ((imm >> 8) & 255) + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ((imm >> 8) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 2] + ((imm >> 16) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ((imm >> 16) & 255) + car, pf);
		zf = (!(bin[dst + 2] + ((imm >> 16) & 255) + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ((imm >> 16) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 3] + ((imm >> 24) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ((imm >> 24) & 255) + car, pf);
		zf = (!(bin[dst + 3] + ((imm >> 24) & 255) + car) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ((imm >> 24) & 255) + car) & 128;
		uint8_t of = ((bin[dst + 3] & 128) && (((imm >> 24) & 255) & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ((imm >> 24) & 255) + car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_adc_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t car = bin[136] & 1;
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + (imm & 255) + car) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + (imm & 255) + car, 1);
		uint8_t af = ((bin[dst] & 15) + ((imm & 255) & 15) + car) & 16;
		uint8_t zf = !(bin[dst] + (imm & 255)) << 6;
		bin[dst] = bin[dst] + (imm & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 1] + ((imm >> 8) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ((imm >> 8) & 255) + car, pf);
		zf = (!(bin[dst + 1] + ((imm >> 8) & 255) + car) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ((imm >> 8) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 2] + ((imm >> 16) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ((imm >> 16) & 255) + car, pf);
		zf = (!(bin[dst + 2] + ((imm >> 16) & 255) + car) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ((imm >> 16) & 255) + car;
		car = cf;
		
		cf = ((bin[dst + 3] + ((imm >> 24) & 255) + car) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ((imm >> 24) & 255) + car, pf);
		zf = (!(bin[dst + 3] + ((imm >> 24) & 255) + car) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ((imm >> 24) & 255) + car;
		car = cf;
		
		cf = 0;
		pf = x86_64_parity_flag(car, pf);
		zf = (!car && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		uint8_t of = 0;
		bin[dst + 4] = car;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + bor) << 6;
		uint8_t sf = (bin[dst] + ~bin[src] + bor) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (bin[src] & 128)) << 3;
		bin[dst] = bin[dst] + ~bin[src] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + bor) << 6;
		bin[dst] = bin[dst] + ~bin[src] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~bin[src + 1] + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ (bin[src + 1] & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + bor) << 6;
		bin[dst] = bin[dst] + ~bin[src] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~bin[src + 2] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~bin[src + 3] + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (bin[src + 3] & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ~bin[src + 3] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + bor) << 6;
		bin[dst] = bin[dst] + ~bin[src] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~bin[src + 2] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ~bin[src + 3] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 4] + ~bin[src + 4] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 4] + ~bin[src + 4] + bor, pf);
		zf = (!(bin[dst + 4] + ~bin[src + 4] + bor) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] + ~bin[src + 4] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 5] + ~bin[src + 5] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 5] + ~bin[src + 5] + bor, pf);
		zf = (!(bin[dst + 5] + ~bin[src + 5] + bor) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] + ~bin[src + 5] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 6] + ~bin[src + 6] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 6] + ~bin[src + 6] + bor, pf);
		zf = (!(bin[dst + 6] + ~bin[src + 6] + bor) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] + ~bin[src + 6] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 7] + ~bin[src + 7] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 7] + ~bin[src + 7] + bor, pf);
		zf = (!(bin[dst + 7] + ~bin[src + 7] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 7] + ~bin[src + 7] + bor) & 128;
		uint8_t of = ((bin[dst + 7] & 128) ^ (bin[src + 7] & 128)) << 3;
		bin[dst + 7] = bin[dst + 7] + ~bin[src + 7] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~imm + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~imm + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~imm & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~imm + bor) << 6;
		uint8_t sf = (bin[dst] + ~imm + bor) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (imm & 128)) << 3;
		bin[dst] = bin[dst] + ~imm + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + bor) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~(imm >> 8) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~(imm >> 8) + bor, pf);
		zf = (!(bin[dst + 1] + ~(imm >> 8) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~(imm >> 8) + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ ((imm >> 8) & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + ~(imm >> 8) + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + bor) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~((imm >> 8) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~((imm >> 16) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (((imm >> 24) & 255) & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ~((imm >> 24) & 255) + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sbb_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		uint8_t bor = !(bin[136] & 1);
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + bor) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + bor, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + bor) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + bor) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~((imm >> 8) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~((imm >> 16) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ~((imm >> 24) & 255) + bor;
		bor = !cf;
		
		cf = 0;
		pf = x86_64_parity_flag(bor, pf);
		zf = (!bor && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		uint8_t of = 0;
		bin[dst + 4] = bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & bin[src]) << 6;
		uint8_t sf = (bin[dst] & bin[src]) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] & bin[src];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] & bin[src + 1], pf);
		zf = (!(bin[dst + 1] & bin[src + 1]) && zf) << 6;
		uint8_t sf = (bin[dst + 1] & bin[src + 1]) & 128;
		bin[dst + 1] = bin[dst + 1] & bin[src + 1];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] & bin[src + 1], pf);
		zf = (!(bin[dst + 1] & bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] & bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] & bin[src + 2], pf);
		zf = (!(bin[dst + 2] & bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] & bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] & bin[src + 3], pf);
		zf = (!(bin[dst + 3] & bin[src + 3]) && zf) << 6;
		uint8_t sf = (bin[dst + 3] & bin[src + 3]) & 128;
		bin[dst + 3] = bin[dst + 3] & bin[src + 3];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] & bin[src + 1], pf);
		zf = (!(bin[dst + 1] & bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] & bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] & bin[src + 2], pf);
		zf = (!(bin[dst + 2] & bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] & bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] & bin[src + 3], pf);
		zf = (!(bin[dst + 3] & bin[src + 3]) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] & bin[src + 3];
		
		pf = x86_64_parity_flag(bin[dst + 4] & bin[src + 4], pf);
		zf = (!(bin[dst + 4] & bin[src + 4]) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] & bin[src + 4];
		
		pf = x86_64_parity_flag(bin[dst + 5] & bin[src + 5], pf);
		zf = (!(bin[dst + 5] & bin[src + 5]) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] & bin[src + 5];
		
		pf = x86_64_parity_flag(bin[dst + 6] & bin[src + 6], pf);
		zf = (!(bin[dst + 6] & bin[src + 6]) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] & bin[src + 6];
		
		pf = x86_64_parity_flag(bin[dst + 7] & bin[src + 7], pf);
		zf = (!(bin[dst + 7] & bin[src + 7]) && zf) << 6;
		uint8_t sf = (bin[dst + 7] & bin[src + 7]) & 128;
		bin[dst + 7] = bin[dst + 7] & bin[src + 7];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & imm, 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & imm) << 6;
		uint8_t sf = (bin[dst] & imm) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] & imm;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & (imm >> 8), pf);
		zf = (!(bin[dst + 1] & (imm >> 8)) && zf) << 6;
		uint8_t sf = (bin[dst + 1] & (imm >> 8)) & 128;
		bin[dst + 1] = bin[dst + 1] & (imm >> 8);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] & ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] & ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] & ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] & ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] & ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = (bin[dst + 3] & ((imm >> 24) & 255)) & 128;
		bin[dst + 3] = bin[dst + 3] & ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_and_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] & (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] & (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] & (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] & ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] & ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] & ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] & ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] & ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] & ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		bin[dst + 3] = bin[dst + 3] & ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		uint8_t sf = (bin[dst] + ~bin[src] + 1) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (bin[src] & 128)) << 3;
		bin[dst] = bin[dst] + ~bin[src] + 1;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		bin[dst] = bin[dst] + ~bin[src] + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~bin[src + 1] + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ (bin[src + 1] & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		bin[dst] = bin[dst] + ~bin[src] + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~bin[src + 2] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~bin[src + 3] + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (bin[src + 3] & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ~bin[src + 3] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		bin[dst] = bin[dst] + ~bin[src] + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~bin[src + 1] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~bin[src + 2] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ~bin[src + 3] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 4] + ~bin[src + 4] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 4] + ~bin[src + 4] + bor, pf);
		zf = (!(bin[dst + 4] + ~bin[src + 4] + bor) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] + ~bin[src + 4] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 5] + ~bin[src + 5] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 5] + ~bin[src + 5] + bor, pf);
		zf = (!(bin[dst + 5] + ~bin[src + 5] + bor) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] + ~bin[src + 5] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 6] + ~bin[src + 6] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 6] + ~bin[src + 6] + bor, pf);
		zf = (!(bin[dst + 6] + ~bin[src + 6] + bor) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] + ~bin[src + 6] + bor;
		bor = !cf;
		
		cf = ((bin[dst + 7] + ~bin[src + 7] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 7] + ~bin[src + 7] + bor, pf);
		zf = (!(bin[dst + 7] + ~bin[src + 7] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 7] + ~bin[src + 7] + bor) & 128;
		uint8_t of = ((bin[dst + 7] & 128) ^ (bin[src + 7] & 128)) << 3;
		bin[dst + 7] = bin[dst + 7] + ~bin[src + 7] + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~imm + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~imm + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~imm & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~imm + 1) << 6;
		uint8_t sf = (bin[dst] + ~imm + 1) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (imm & 128)) << 3;
		bin[dst] = bin[dst] + ~imm + 1;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~(imm >> 8) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~(imm >> 8) + bor, pf);
		zf = (!(bin[dst + 1] + ~(imm >> 8) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~(imm >> 8) + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ ((imm >> 8) & 128)) << 3;
		bin[dst + 1] = bin[dst + 1] + ~(imm >> 8) + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~((imm >> 8) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~((imm >> 16) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (((imm >> 24) & 255) & 128)) << 3;
		bin[dst + 3] = bin[dst + 3] + ~((imm >> 24) & 255) + bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_sub_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		bin[dst] = bin[dst] + ~(imm & 255) + 1;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] + ~((imm >> 8) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] + ~((imm >> 16) & 255) + bor;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] + ~((imm >> 24) & 255) + bor;
		bor = !cf;
		
		cf = 0;
		pf = x86_64_parity_flag(bor, pf);
		zf = (!bor && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		uint8_t of = 0;
		bin[dst + 4] = bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ bin[src]) << 6;
		uint8_t sf = (bin[dst] ^ bin[src]) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ bin[src];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ bin[src + 1], pf);
		zf = (!(bin[dst + 1] ^ bin[src + 1]) && zf) << 6;
		uint8_t sf = (bin[dst + 1] ^ bin[src + 1]) & 128;
		bin[dst + 1] = bin[dst + 1] ^ bin[src + 1];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ bin[src + 1], pf);
		zf = (!(bin[dst + 1] ^ bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] ^ bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] ^ bin[src + 2], pf);
		zf = (!(bin[dst + 2] ^ bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] ^ bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] ^ bin[src + 3], pf);
		zf = (!(bin[dst + 3] ^ bin[src + 3]) && zf) << 6;
		uint8_t sf = (bin[dst + 3] ^ bin[src + 3]) & 128;
		bin[dst + 3] = bin[dst + 3] ^ bin[src + 3];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ bin[src], 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ bin[src]) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ bin[src];
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ bin[src + 1], pf);
		zf = (!(bin[dst + 1] ^ bin[src + 1]) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] ^ bin[src + 1];
		
		pf = x86_64_parity_flag(bin[dst + 2] ^ bin[src + 2], pf);
		zf = (!(bin[dst + 2] ^ bin[src + 2]) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] ^ bin[src + 2];
		
		pf = x86_64_parity_flag(bin[dst + 3] ^ bin[src + 3], pf);
		zf = (!(bin[dst + 3] ^ bin[src + 3]) && zf) << 6;
		bin[dst + 3] = bin[dst + 3] ^ bin[src + 3];
		
		pf = x86_64_parity_flag(bin[dst + 4] ^ bin[src + 4], pf);
		zf = (!(bin[dst + 4] ^ bin[src + 4]) && zf) << 6;
		bin[dst + 4] = bin[dst + 4] ^ bin[src + 4];
		
		pf = x86_64_parity_flag(bin[dst + 5] ^ bin[src + 5], pf);
		zf = (!(bin[dst + 5] ^ bin[src + 5]) && zf) << 6;
		bin[dst + 5] = bin[dst + 5] ^ bin[src + 5];
		
		pf = x86_64_parity_flag(bin[dst + 6] ^ bin[src + 6], pf);
		zf = (!(bin[dst + 6] ^ bin[src + 6]) && zf) << 6;
		bin[dst + 6] = bin[dst + 6] ^ bin[src + 6];
		
		pf = x86_64_parity_flag(bin[dst + 7] ^ bin[src + 7], pf);
		zf = (!(bin[dst + 7] ^ bin[src + 7]) && zf) << 6;
		uint8_t sf = (bin[dst + 7] ^ bin[src + 7]) & 128;
		bin[dst + 7] = bin[dst + 7] ^ bin[src + 7];
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ imm, 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ imm) << 6;
		uint8_t sf = (bin[dst] ^ imm) & 128;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ imm;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ (imm >> 8), pf);
		zf = (!(bin[dst + 1] ^ (imm >> 8)) && zf) << 6;
		uint8_t sf = (bin[dst + 1] ^ (imm >> 8)) & 128;
		bin[dst + 1] = bin[dst + 1] ^ (imm >> 8);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] ^ ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] ^ ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 2] ^ ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] ^ ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] ^ ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 3] ^ ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] ^ ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = (bin[dst + 3] ^ ((imm >> 24) & 255)) & 128;
		bin[dst + 3] = bin[dst + 3] ^ ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_xor_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = 0;
		uint8_t pf = x86_64_parity_flag(bin[dst] ^ (imm & 255), 1);
		uint8_t af = 0;
		uint8_t zf = !(bin[dst] ^ (imm & 255)) << 6;
		uint8_t of = 0;
		bin[dst] = bin[dst] ^ (imm & 255);
		
		pf = x86_64_parity_flag(bin[dst + 1] ^ ((imm >> 8) & 255), pf);
		zf = (!(bin[dst + 1] ^ ((imm >> 8) & 255)) && zf) << 6;
		bin[dst + 1] = bin[dst + 1] ^ ((imm >> 8) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 2] ^ ((imm >> 16) & 255), pf);
		zf = (!(bin[dst + 2] ^ ((imm >> 16) & 255)) && zf) << 6;
		bin[dst + 2] = bin[dst + 2] ^ ((imm >> 16) & 255);
		
		pf = x86_64_parity_flag(bin[dst + 3] ^ ((imm >> 24) & 255), pf);
		zf = (!(bin[dst + 3] ^ ((imm >> 24) & 255)) && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		bin[dst + 3] = bin[dst + 3] ^ ((imm >> 24) & 255);
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_reg_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		uint8_t sf = (bin[dst] + ~bin[src] + 1) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (bin[src] & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_reg_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~bin[src + 1] + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ (bin[src + 1] & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_reg_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~bin[src + 3] + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (bin[src + 3] & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_reg_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint64_t src) {
	if (dst >= bn || src >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~bin[src] + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~bin[src] + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~bin[src] & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~bin[src] + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~bin[src + 1] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~bin[src + 1] + bor, pf);
		zf = (!(bin[dst + 1] + ~bin[src + 1] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~bin[src + 2] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~bin[src + 2] + bor, pf);
		zf = (!(bin[dst + 2] + ~bin[src + 2] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~bin[src + 3] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~bin[src + 3] + bor, pf);
		zf = (!(bin[dst + 3] + ~bin[src + 3] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 4] + ~bin[src + 4] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 4] + ~bin[src + 4] + bor, pf);
		zf = (!(bin[dst + 4] + ~bin[src + 4] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 5] + ~bin[src + 5] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 5] + ~bin[src + 5] + bor, pf);
		zf = (!(bin[dst + 5] + ~bin[src + 5] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 6] + ~bin[src + 6] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 6] + ~bin[src + 6] + bor, pf);
		zf = (!(bin[dst + 6] + ~bin[src + 6] + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 7] + ~bin[src + 7] + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 7] + ~bin[src + 7] + bor, pf);
		zf = (!(bin[dst + 7] + ~bin[src + 7] + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 7] + ~bin[src + 7] + bor) & 128;
		uint8_t of = ((bin[dst + 7] & 128) ^ (bin[src + 7] & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_imm_8(uint8_t* bin, uint64_t bn, uint64_t dst, uint8_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~imm + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~imm + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~imm & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~imm + 1) << 6;
		uint8_t sf = (bin[dst] + ~imm + 1) & 128;
		uint8_t of = ((bin[dst] & 128) ^ (imm & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_imm_16(uint8_t* bin, uint64_t bn, uint64_t dst, uint16_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~(imm >> 8) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~(imm >> 8) + bor, pf);
		zf = (!(bin[dst + 1] + ~(imm >> 8) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 1] + ~(imm >> 8) + bor) & 128;
		uint8_t of = ((bin[dst + 1] & 128) ^ ((imm >> 8) & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_imm_32(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		uint8_t sf = (bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 128;
		uint8_t of = ((bin[dst + 3] & 128) ^ (((imm >> 24) & 255) & 128)) << 3;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_cmp_imm_64(uint8_t* bin, uint64_t bn, uint64_t dst, uint32_t imm) {
	if (dst >= bn) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[136] = 0;
		bin[137] = 0;
		
		uint8_t cf = ((bin[dst] + ~(imm & 255) + 1) & 256) >> 8;
		uint8_t pf = x86_64_parity_flag(bin[dst] + ~(imm & 255) + 1, 1);
		uint8_t af = ((bin[dst] & 15) + (~(imm & 255) & 15) + 1) & 16;
		uint8_t zf = !(bin[dst] + ~(imm & 255) + 1) << 6;
		uint8_t bor = !cf;
		
		cf = ((bin[dst + 1] + ~((imm >> 8) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 1] + ~((imm >> 8) & 255) + bor, pf);
		zf = (!(bin[dst + 1] + ~((imm >> 8) & 255) + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 2] + ~((imm >> 16) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 2] + ~((imm >> 16) & 255) + bor, pf);
		zf = (!(bin[dst + 2] + ~((imm >> 16) & 255) + bor) && zf) << 6;
		bor = !cf;
		
		cf = ((bin[dst + 3] + ~((imm >> 24) & 255) + bor) & 256) >> 8;
		pf = x86_64_parity_flag(bin[dst + 3] + ~((imm >> 24) & 255) + bor, pf);
		zf = (!(bin[dst + 3] + ~((imm >> 24) & 255) + bor) && zf) << 6;
		bor = !cf;
		
		cf = 0;
		pf = x86_64_parity_flag(bor, pf);
		zf = (!bor && zf) << 6;
		uint8_t sf = bin[dst + 7] & 128;
		uint8_t of = 0;
		bin[dst + 4] = bor;
		
		bin[136] = bin[136] | cf;
		bin[136] = bin[136] | pf;
		bin[136] = bin[136] | af;
		bin[136] = bin[136] | sf;
		bin[136] = bin[136] | zf;
		bin[137] = bin[137] | of;
	}
}

void x86_64_inc_push_reg_16(uint8_t* bin, uint64_t bn, uint8_t reg) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if ((sp - 2) >= bn || (sp - 2) < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		sp = sp - 2;
		bin[sp] = bin[reg];
		bin[sp + 1] = bin[reg + 1];
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_push_reg_64(uint8_t* bin, uint64_t bn, uint8_t reg) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if ((sp - 8) >= bn || (sp - 8) < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		sp = sp - 8;
		bin[sp] = bin[reg];
		bin[sp + 1] = bin[reg + 1];
		bin[sp + 2] = bin[reg + 2];
		bin[sp + 3] = bin[reg + 3];
		bin[sp + 4] = bin[reg + 4];
		bin[sp + 5] = bin[reg + 5];
		bin[sp + 6] = bin[reg + 6];
		bin[sp + 7] = bin[reg + 7];
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_push_imm_16(uint8_t* bin, uint64_t bn, uint16_t k) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if ((sp - 2) >= bn || (sp - 2) < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		sp = sp - 2;
		bin[sp] = k;
		bin[sp + 1] = k >> 8;
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_push_imm_64(uint8_t* bin, uint64_t bn, uint32_t k) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if ((sp - 8) >= bn || (sp - 8) < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		sp = sp - 8;
		bin[sp] = k;
		bin[sp + 1] = k >> 8;
		bin[sp + 2] = k >> 16;
		bin[sp + 3] = k >> 24;
		bin[sp + 4] = 0;
		bin[sp + 5] = 0;
		bin[sp + 6] = 0;
		bin[sp + 7] = 0;
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_pop_reg_16(uint8_t* bin, uint64_t bn, uint8_t reg) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if (sp >= bn || sp < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[reg] = bin[sp];
		bin[reg + 1] = bin[sp + 1];
		sp = sp + 2;
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_pop_reg_64(uint8_t* bin, uint64_t bn, uint8_t reg) {
	uint64_t sp = x86_64_reg_get_sp(bin) + 138;
	if (sp >= bn || sp < 138) {
		printf("[error] illegal memory access\n");
	}
	else {
		bin[reg] = bin[sp];
		bin[reg + 1] = bin[sp + 1];
		bin[reg + 2] = bin[sp + 2];
		bin[reg + 3] = bin[sp + 3];
		bin[reg + 4] = bin[sp + 4];
		bin[reg + 5] = bin[sp + 5];
		bin[reg + 6] = bin[sp + 6];
		bin[reg + 7] = bin[sp + 7];
		sp = sp + 8;
		x86_64_reg_set_sp(bin, sp);
	}
}

void x86_64_inc_jo_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) {
	uint8_t of = bin[137] & 8;
	if (of) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jo_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t of = bin[137] & 8;
	if (of) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jno_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t of = bin[137] & 8;
	if (!of) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jno_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t of = bin[137] & 8;
	if (!of) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jc_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) {
	uint8_t cf = bin[136] & 1;
	if (cf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jc_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) {
	uint8_t cf = bin[136] & 1;
	if (cf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jnc_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) {
	uint8_t cf = bin[136] & 1;
	if (!cf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jnc_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) {
	uint8_t cf = bin[136] & 1;
	if (!cf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_je_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t zf = bin[136] & 64;
	if (zf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_je_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t zf = bin[136] & 64;
	if (zf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jne_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t zf = bin[136] & 64;
	if (!zf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jne_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t zf = bin[136] & 64;
	if (!zf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jna_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t af = bin[136] & 16;
	if (!af) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jna_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t af = bin[136] & 16;
	if (!af) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_ja_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t af = bin[136] & 16;
	if (af) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_ja_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t af = bin[136] & 16;
	if (af) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_js_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t sf = bin[136] & 128;
	if (sf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_js_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t sf = bin[136] & 128;
	if (sf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jns_s8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t sf = bin[136] & 128;
	if (!sf) {
		ip = ip - k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

void x86_64_inc_jns_u8(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t k) { 
	uint8_t sf = bin[136] & 128;
	if (!sf) {
		ip = ip + k;
		if (ip >= bn || ip < 138) {
			printf("[error] illegal memory access\n");
		}
		else {
			x86_64_reg_set_ip(bin, bn, ip);
		}
	}
	else {
		x86_64_reg_set_ip(bin, bn, ip);
	}
}

uint8_t x86_64_inc_r80(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op) (uint8_t*, uint64_t, uint64_t, uint64_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		uint8_t mod = bin[ip] >> 6;
		uint8_t mrd = (bin[ip] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[ip] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				if (i == 4 && (b & 7) == 5) {
					ip = ip + 1;
					uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
					ip = ip + 4;
					//do not use
					x86_64_reg_set_ip(bin, bn, ip);
				}
				else {
					ip = ip + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, ((uint32_t) ip) - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ip - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((uint32_t) ip) - d, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ip - d, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, ((uint32_t) ip) + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ip + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((uint32_t) ip) + d, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ip - d, ((mrs & 3) * 8) + !!(mrs & 4));
								x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				if (rex) {
					if (lga) {
						x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else {
					if (lga) {
						x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, ((mrs & 3) * 8) + !!(mrs & 4));
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			ip = ip + 1;
			if (rex) {
				x86_64_inc_op(bin, bn, mrd * 8, mrs * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else {
				x86_64_inc_op(bin, bn, ((mrd & 3) * 8) + !!(mrd & 4), ((mrs & 3) * 8) + !!(mrs & 4));
				x86_64_reg_set_ip(bin, bn, ip);
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_rg0(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_16) (uint8_t*, uint64_t, uint64_t, uint64_t), void (*x86_64_inc_op_32) (uint8_t*, uint64_t, uint64_t, uint64_t), void (*x86_64_inc_op_64) (uint8_t*, uint64_t, uint64_t, uint64_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		uint8_t mod = bin[ip] >> 6;
		uint8_t mrd = (bin[ip] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[ip] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				if (i == 4 && (b & 7) == 5) {
					ip = ip + 1;
					uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
					ip = ip + 4;
					//do not use
					x86_64_reg_set_ip(bin, bn, ip);
				}
				else {
					ip = ip + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, ((uint32_t) ip) - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, ip - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, ((uint32_t) ip) - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, ip - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, ((uint32_t) ip) - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, ip - d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, ((uint32_t) ip) + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, ip + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, ((uint32_t) ip) + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, ip + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, ((uint32_t) ip) + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, ip + d, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				if (lgo) {
					if (lga) {
						x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else if (!rx3) {
					if (lga) {
						x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else {
					if (lga) {
						x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138, mrs * 8);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (lgo) {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138, mrs * 8);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			ip = ip + 1;
			if (lgo) {
				x86_64_inc_op_16(bin, bn, mrd * 8, mrs * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else if (!rx3) {
				x86_64_inc_op_32(bin, bn, mrd * 8, mrs * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else {
				x86_64_inc_op_64(bin, bn, mrd * 8, mrs * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_r81(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op) (uint8_t*, uint64_t, uint64_t, uint64_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		uint8_t mod = bin[ip] >> 6;
		uint8_t mrd = (bin[ip] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[ip] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				if (i == 4 && (b & 7) == 5) {
					ip = ip + 1;
					uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
					ip = ip + 4;
					//do not use
					x86_64_reg_set_ip(bin, bn, ip);
				}
				else {
					ip = ip + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, ((uint32_t) ip) - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, ip - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), ((uint32_t) ip) - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), ip - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, ((uint32_t) ip) + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, ip + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), ((uint32_t) ip) + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), ip - d);
								x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				if (rex) {
					if (lga) {
						x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else {
					if (lga) {
						x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			ip = ip + 1;
			if (rex) {
				x86_64_inc_op(bin, bn, mrs * 8, mrd * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else {
				x86_64_inc_op(bin, bn, ((mrs & 3) * 8) + !!(mrs & 4), ((mrd & 3) * 8) + !!(mrd & 4));
				x86_64_reg_set_ip(bin, bn, ip);
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_rg1(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_16) (uint8_t*, uint64_t, uint64_t, uint64_t), void (*x86_64_inc_op_32) (uint8_t*, uint64_t, uint64_t, uint64_t), void (*x86_64_inc_op_64) (uint8_t*, uint64_t, uint64_t, uint64_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		uint8_t mod = bin[ip] >> 6;
		uint8_t mrd = (bin[ip] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[ip] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				if (i == 4 && (b & 7) == 5) {
					ip = ip + 1;
					uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
					ip = ip + 4;
					//do not use
					x86_64_reg_set_ip(bin, bn, ip);
				}
				else {
					ip = ip + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, 0) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, ((uint32_t) ip) - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, ip - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, ((uint32_t) ip) - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, ip - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, ((uint32_t) ip) - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, ip - d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, ((uint32_t) ip) + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, ip + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, ((uint32_t) ip) + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, ip + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, ((uint32_t) ip) + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, ip + d);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				if (lgo) {
					if (lga) {
						x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else if (!rx3) {
					if (lga) {
						x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
				else {
					if (lga) {
						x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
					else {
						x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, 0) + 138);
						x86_64_reg_set_ip(bin, bn, ip);
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint8_t d = bin[ip];
				ip = ip + 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				ip = ip + 1;
				uint8_t b = (bin[ip] & 7) + (8 * rx0);
				uint8_t i = ((bin[ip] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[ip] >> 6);
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, b * 8, i * 8, s, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
			else {
				ip = ip + 1;
				uint32_t d = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
				ip = ip + 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (lgo) {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_s64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_16(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else if (!rx3) {
						if (lga) {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_32(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
					else {
						if (lga) {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u32(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
						else {
							x86_64_inc_op_64(bin, bn, mrs * 8, x86_64_inc_addr_u64(bin, bn, mrd * 8, 32, 0, d) + 138);
							x86_64_reg_set_ip(bin, bn, ip);
						}
					}
				}
			}
		}
		else if (mod == 3) {
			ip = ip + 1;
			if (lgo) {
				x86_64_inc_op_16(bin, bn, mrs * 8, mrd * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else if (!rx3) {
				x86_64_inc_op_32(bin, bn, mrs * 8, mrd * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
			else {
				x86_64_inc_op_64(bin, bn, mrs * 8, mrd * 8);
				x86_64_reg_set_ip(bin, bn, ip);
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_ral(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op) (uint8_t*, uint64_t, uint64_t, uint8_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		uint8_t k = bin[ip];
		ip = ip + 1;
		x86_64_inc_op(bin, bn, 0, k);
		x86_64_reg_set_ip(bin, bn, ip);
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_rax(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_16) (uint8_t*, uint64_t, uint64_t, uint16_t), void (*x86_64_inc_op_32) (uint8_t*, uint64_t, uint64_t, uint32_t), void (*x86_64_inc_op_64) (uint8_t*, uint64_t, uint64_t, uint32_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		if (lgo) {
			uint16_t k = bin[ip] + (bin[ip + 1] << 8);
			ip = ip + 2;
			x86_64_inc_op_16(bin, bn, 0, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		else if (!rx3) {
			uint32_t k = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
			ip = ip + 4;
			x86_64_inc_op_32(bin, bn, 0, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		else {
			uint32_t k = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
			ip = ip + 4;
			x86_64_inc_op_64(bin, bn, 0, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_stck(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_16) (uint8_t*, uint64_t, uint8_t), void (*x86_64_inc_op_64) (uint8_t*, uint64_t, uint8_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[ip] & 248) == op) {
		uint8_t reg = (bin[ip] & 7) + (8 * rx0); 
		ip = ip + 1;
		
		if (lgo) {
			x86_64_inc_op_16(bin, bn, reg * 8);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		else {
			x86_64_inc_op_64(bin, bn, reg * 8);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_op_imm(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_16) (uint8_t*, uint64_t, uint16_t), void (*x86_64_inc_op_64) (uint8_t*, uint64_t, uint32_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		
		if (lgo) {
			uint16_t k = bin[ip] + (bin[ip + 1] << 8);
			ip = ip + 2;
			x86_64_inc_op_16(bin, bn, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		else {
			uint32_t k = bin[ip] + (bin[ip + 1] << 8) + (bin[ip + 2] << 16) + (bin[ip + 3] << 24);
			ip = ip + 4;
			x86_64_inc_op_64(bin, bn, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		return 0;
	}
	else if (bin[ip] == op + 2) {
		ip = ip + 1;
		uint8_t k = bin[ip];
		ip = ip + 1;
		if (lgo) {
			x86_64_inc_op_16(bin, bn, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		else {
			x86_64_inc_op_64(bin, bn, k);
			x86_64_reg_set_ip(bin, bn, ip);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_inc_byt_imm(uint8_t* bin, uint64_t bn, uint64_t ip, uint8_t op, void (*x86_64_inc_op_s) (uint8_t*, uint64_t, uint64_t, uint8_t), void (*x86_64_inc_op_u) (uint8_t*, uint64_t, uint64_t, uint8_t), uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[ip] == op) {
		ip = ip + 1;
		
		uint8_t k = bin[ip];
		ip = ip + 1;
		
		if (k & 128) {
			k = ~k + 1;
			x86_64_inc_op_s(bin, bn, ip, k);
		}
		else {
			x86_64_inc_op_u(bin, bn, ip, k);
		}
		return 0;
	}
	return 1;
}

void x86_64_inc(uint8_t* bin, uint64_t bn, uint64_t ip) {
	uint8_t lga = 0;
	uint8_t lgo = 0;
	uint8_t rex = 0;
	uint8_t rx0 = 0;
	uint8_t rx1 = 0;
	uint8_t rx2 = 0;
	uint8_t rx3 = 0;
	
	ip = ip + 138;
	
	if (bin[ip] == 102) { //leg addr
		lgo = 1;
		ip = ip + 1;
	}
	
	if (bin[ip] == 103) { //leg op
		lga = 1;
		ip = ip + 1;
	}
	
	if ((bin[ip] & 240) == 64) { //rex
		rex = 1;
		if (bin[ip] & 1) {
			rx0 = 1;
		}
		if (bin[ip] & 2) {
			rx1 = 1;
		}
		if (bin[ip] & 4) {
			rx2 = 1;
		}
		if (bin[ip] & 8) {
			rx3 = 1;
		}
		ip = ip + 1;
	}
	
	uint8_t eo = 1;
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 0, x86_64_inc_add_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 1, x86_64_inc_add_reg_16, x86_64_inc_add_reg_32, x86_64_inc_add_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 2, x86_64_inc_add_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 3, x86_64_inc_add_reg_16, x86_64_inc_add_reg_32, x86_64_inc_add_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 4, x86_64_inc_add_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 5, x86_64_inc_add_imm_16, x86_64_inc_add_imm_32, x86_64_inc_add_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 8, x86_64_inc_or_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 9, x86_64_inc_or_reg_16, x86_64_inc_or_reg_32, x86_64_inc_or_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 10, x86_64_inc_or_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 11, x86_64_inc_or_reg_16, x86_64_inc_or_reg_32, x86_64_inc_or_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 12, x86_64_inc_or_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 13, x86_64_inc_or_imm_16, x86_64_inc_or_imm_32, x86_64_inc_or_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 16, x86_64_inc_adc_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 17, x86_64_inc_adc_reg_16, x86_64_inc_adc_reg_32, x86_64_inc_adc_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 18, x86_64_inc_adc_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 19, x86_64_inc_adc_reg_16, x86_64_inc_adc_reg_32, x86_64_inc_adc_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 20, x86_64_inc_adc_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 21, x86_64_inc_adc_imm_16, x86_64_inc_adc_imm_32, x86_64_inc_adc_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 24, x86_64_inc_sbb_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 25, x86_64_inc_sbb_reg_16, x86_64_inc_sbb_reg_32, x86_64_inc_sbb_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 26, x86_64_inc_sbb_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 27, x86_64_inc_sbb_reg_16, x86_64_inc_sbb_reg_32, x86_64_inc_sbb_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 28, x86_64_inc_sbb_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 29, x86_64_inc_sbb_imm_16, x86_64_inc_sbb_imm_32, x86_64_inc_sbb_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 32, x86_64_inc_and_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 33, x86_64_inc_and_reg_16, x86_64_inc_and_reg_32, x86_64_inc_and_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 34, x86_64_inc_and_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 35, x86_64_inc_and_reg_16, x86_64_inc_and_reg_32, x86_64_inc_and_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 36, x86_64_inc_and_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 37, x86_64_inc_and_imm_16, x86_64_inc_and_imm_32, x86_64_inc_and_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 40, x86_64_inc_sub_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 41, x86_64_inc_sub_reg_16, x86_64_inc_sub_reg_32, x86_64_inc_sub_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 42, x86_64_inc_sub_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 43, x86_64_inc_sub_reg_16, x86_64_inc_sub_reg_32, x86_64_inc_sub_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 44, x86_64_inc_sub_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 45, x86_64_inc_sub_imm_16, x86_64_inc_sub_imm_32, x86_64_inc_sub_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 48, x86_64_inc_xor_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 49, x86_64_inc_xor_reg_16, x86_64_inc_xor_reg_32, x86_64_inc_xor_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 50, x86_64_inc_xor_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 51, x86_64_inc_xor_reg_16, x86_64_inc_xor_reg_32, x86_64_inc_xor_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 52, x86_64_inc_xor_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 53, x86_64_inc_xor_imm_16, x86_64_inc_xor_imm_32, x86_64_inc_xor_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r80(bin, bn, ip, 56, x86_64_inc_cmp_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg0(bin, bn, ip, 57, x86_64_inc_cmp_reg_16, x86_64_inc_cmp_reg_32, x86_64_inc_cmp_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_r81(bin, bn, ip, 58, x86_64_inc_cmp_reg_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rg1(bin, bn, ip, 59, x86_64_inc_cmp_reg_16, x86_64_inc_cmp_reg_32, x86_64_inc_cmp_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_ral(bin, bn, ip, 60, x86_64_inc_cmp_imm_8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_rax(bin, bn, ip, 61, x86_64_inc_cmp_imm_16, x86_64_inc_cmp_imm_32, x86_64_inc_cmp_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_stck(bin, bn, ip, 80, x86_64_inc_push_reg_16, x86_64_inc_push_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_stck(bin, bn, ip, 88, x86_64_inc_pop_reg_16, x86_64_inc_pop_reg_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_op_imm(bin, bn, ip, 104, x86_64_inc_push_imm_16, x86_64_inc_push_imm_64, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_byt_imm(bin, bn, ip, 112, x86_64_inc_jo_s8, x86_64_inc_jo_u8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_inc_byt_imm(bin, bn, ip, 113, x86_64_inc_jno_s8, x86_64_inc_jno_u8, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		printf("[error] unknown instruction\n");
		ip = ip + 1;
	}
}
