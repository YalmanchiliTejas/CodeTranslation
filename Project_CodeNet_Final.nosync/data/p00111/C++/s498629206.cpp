#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[1024] = "";
	char t[32][9] = {"100101", "10011010", "0101", "0001", "110",
		"01001", "10011011", "010000", "0111", "10011000", "0110",
		"00100", "10011001", "10011110", "00101", "111", "10011111",
		"1000", "00110", "00111", "10011100", "10011101", "000010",
		"10010010", "10010011", "10010000", "101", "010001", "000011",
		"10010001", "000000", "000001"};
	char u[32][6] = {"00000", "00001", "00010", "00011", "00100",
		"00101", "00110", "00111", "01000", "01001", "01010", "01011",
		"01100", "01101", "01110", "01111", "10000", "10001", "10010",
		"10011", "10100", "10101", "10110", "10111", "11000", "11001",
		"11010", "11011", "11100", "11101", "11110", "11111"};
	int i, j, k, c, f;
	while (cin.getline(s, sizeof(s)), !cin.eof())
	{
		char a[5120] = "", r[5120] = "";
		c = 0;
		for (i = 0; i < strlen(s); i++, c--)
		{
			switch (s[i])
			{
			case ' ':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[26][j];
				break;
			case '.':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[27][j];
				break;
			case ',':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[28][j];
				break;
			case '-':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[29][j];
				break;
			case '\'':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[30][j];
				break;
			case '?':
				for (j = 0; j < 6; j++, c++)
					a[c] = u[31][j];
				break;
			default:
				for (j = 0; j < 6; j++, c++)
					a[c] = u[s[i]-'A'][j];
			}
		}
		for (i = c = 0; i < strlen(a); i += j+1, c++)
		{
			f = 0;
			for (j = 2; j < 9; j++)
			{
				char b[9] = "";
				for (k = 0; k <= j; k++)
					b[k] = a[i+k];
				for (k = 0; k < 32; k++)
					if (strcmp(b, t[k]) == 0)
					{
						switch (k)
						{
						case 26:
							r[c] = ' ';
							break;
						case 27:
							r[c] = '.';
							break;
						case 28:
							r[c] = ',';
							break;
						case 29:
							r[c] = '-';
							break;
						case 30:
							r[c] = '\'';
							break;
						case 31:
							r[c] = '?';
							break;
						default:
							r[c] = k + 'A';
						}
						f = 1;
						break;
					}
				if (f)
					break;
			}
		}
		cout << r << endl;
	}
}