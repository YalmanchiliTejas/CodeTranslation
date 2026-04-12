#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

map<char, string> table1;
map<string, char> table2;

void init_table1() {
	table1['A'] = "00000"; table1['B'] = "00001"; table1['C'] = "00010"; table1['D'] = "00011"; table1['E'] = "00100"; table1['F'] = "00101";
	table1['G'] = "00110"; table1['H'] = "00111"; table1['I'] = "01000"; table1['J'] = "01001"; table1['K'] = "01010"; table1['L'] = "01011";
	table1['M'] = "01100"; table1['N'] = "01101"; table1['O'] = "01110"; table1['P'] = "01111"; table1['Q'] = "10000"; table1['R'] = "10001";
	table1['S'] = "10010"; table1['T'] = "10011"; table1['U'] = "10100"; table1['V'] = "10101"; table1['W'] = "10110"; table1['X'] = "10111";
	table1['Y'] = "11000"; table1['Z'] = "11001"; table1[' '] = "11010"; table1['.'] = "11011"; table1[','] = "11100"; table1['-'] = "11101";
	table1['\''] = "11110"; table1['?'] = "11111";
}

int main() {
	string decode;
	string str;

	init_table1();

	while(getline(cin,str)) {
		for(int i = 0; i < str.size(); i++) {
			decode += table1[str[i]];
		}

		for(int i = 0; i < decode.size(); i++) {
			if(decode[i] == '0') { /* 0 */
				if(decode[i + 1] == '0') { /* 00 */
					if(decode[i + 2] == '0') { /* 000 */
						if(decode[i + 3] == '0') { /* 0000 */
							if(decode[i + 4] == '0') { /* 00000 */
								if(decode[i + 5] == '0') { /* 000000 */
									putchar('\''); i += 5;
								}
								else if(decode[i + 5] == '1') { /* 000001 */
									putchar('?'); i += 5;
								}
							}
							else if(decode[i + 4] == '1') { /* 00001 */
								if(decode[i + 5] == '0') { /* 000010 */
									putchar('W'); i += 5;
								}
								else if(decode[i + 5] == '1') { /* 000011 */
									putchar(','); i += 5;
								}
							}
						}
						else if(decode[i + 3] == '1') { /* 0001 */
							putchar('D'); i += 3;
						}
					}
					else if(decode[i + 2] == '1') { /* 001 */
						if(decode[i + 3] == '0') { /* 0010 */
							if(decode[i + 4] == '0') { /* 00100 */
								putchar('L'); i += 4;
							}
							else if(decode[i + 4] == '1') { /* 00101 */
								putchar('O'); i += 4;
							}
						}
						else if(decode[i + 3] == '1') { /* 0011 */
							if(decode[i + 4] == '0') { /* 00110 */
								putchar('S'); i += 4;
							}
							else if(decode[i + 4] == '1') { /* 00111 */
								putchar('T'); i += 4;
							}
						}
					}
				}
				else if(decode[i + 1] == '1') { /* 01 */
					if(decode[i + 2] == '0') { /* 010 */
						if(decode[i + 3] == '0') { /* 0100 */
							if(decode[i + 4] == '0') { /* 01000 */
								if(decode[i + 5] == '0') { /* 010000 */
									putchar('H'); i += 5;
								}
								else if(decode[i + 5] == '1') { /* 010001 */
									putchar('.'); i += 5;
								}
							}
							else if(decode[i + 4] == '1') { /* 01001 */
								putchar('F'); i += 4;
							}
						}
						else if(decode[i + 3] == '1') { /* 0101 */
							putchar('C'); i += 3;
						}
					}
					else if(decode[i + 2] == '1') { /* 011 */
						if(decode[i + 3] == '0') { /* 0110 */
							putchar('K'); i += 3;
						}
						else if(decode[i + 3] == '1') { /* 0111 */
							putchar('I'); i += 3;
						}
					}
				}
			}
			else if(decode[i] == '1') { /* 1 */
				if(decode[i + 1] == '0') { /* 10 */
					if(decode[i + 2] == '0') { /* 100 */
						if(decode[i + 3] == '0') { /* 1000 */
							putchar('R'); i += 3;
						}
						else if(decode[i + 3] == '1') { /* 1001 */
							if(decode[i + 4] == '0') { /* 10010 */
								if(decode[i + 5] == '0') { /* 100100 */
									if(decode[i + 6] == '0') { /* 1001000 */
										if(decode[i + 7] == '0') { /* 10010000 */
											putchar('Z'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10010001 */
											putchar('-'); i += 7;
										}
									}
									else if(decode[i + 6] == '1') { /* 1001001 */
										if(decode[i + 7] == '0') { /* 10010010 */
											putchar('X'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10010011 */
											putchar('Y'); i += 7;
										}
									}
								}
								else if(decode[i + 5] == '1') { /* 100101 */
									putchar('A'); i += 5;
								}
							}
							else if(decode[i + 4] == '1') { /* 10011 */
								if(decode[i + 5] == '0') { /* 100110 */
									if(decode[i + 6] == '0') { /* 1001100 */
										if(decode[i + 7] == '0') { /* 10011000 */
											putchar('J'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10011001 */
											putchar('M'); i += 7;
										}
									}
									else if(decode[i + 6] == '1') { /* 1001101 */
										if(decode[i + 7] == '0') { /* 10011010 */
											putchar('B'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10011011 */
											putchar('G'); i += 7;
										}
									}
								}
								else if(decode[i + 5] == '1') { /* 100111 */
									if(decode[i + 6] == '0') { /* 1001110 */
										if(decode[i + 7] == '0') { /* 10011100 */
											putchar('U'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10011101 */
											putchar('V'); i += 7;
										}
									}
									else if(decode[i + 6] == '1') { /* 1001111 */
										if(decode[i + 7] == '0') { /* 10011110 */
											putchar('N'); i += 7;
										}
										else if(decode[i + 7] == '1') { /* 10011111 */
											putchar('Q'); i += 7;
										}
									}
								}
							}
						}
					}
					else if(decode[i + 2] == '1') { /* 101 */
						putchar(' '); i += 2;
					}
				}
				else if(decode[i + 1] == '1') { /* 11 */
					if(decode[i + 2] == '0') { /* 110 */
						putchar('E'); i += 2;
					}
					else if(decode[i + 2] == '1') { /* 111 */
						putchar('P'); i += 2;
					}
				}
			}
		}
		putchar('\n');
		str.clear();
		decode.clear();
	}
	return 0;
}