#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <climits>
#include <cfloat>


using namespace std;

bool is_same_in_start(const char* super, const char* sub)
{
	for (int i = 0; sub[i] != '\0'; ++i)
		if (super[i] != sub[i])
			return false;
	return true;
}
int main()
{
	char buf[512];
	while (cin.getline(buf, sizeof(buf)))
	{
		const char* src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
		char bin[512*5];
		memset(bin, 0, sizeof(bin));
		for (int i = 0; buf[i] != '\0'; ++i)
		{
			int t = strchr(src, buf[i]) - src;
			for (int j = 0; j < 5; ++j)
			{
				char c;
				if (t & (1 << j))
					c = '1';
				else
					c = '0';
				bin[i*5 + 4-j] = c;
			}
		}

		const char* dest = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const char* code[] = { "101", "000000", "000011", "10010001", "010001", "000001"
			, "100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000"
			, "0111", "10011000", "0110", "00100", "10011001", "10011110", "00101"
			, "111", "10011111", "1000", "00110", "00111", "10011100", "10011101"
			, "000010", "10010010", "10010011", "10010000"
		};
		char dec[512];
		memset(dec, 0, sizeof(dec));
		char* p = bin;
		for (int i = 0; ; ++i)
		{
			int sel = -1;
			for (int j = 0; sel == -1 && j < sizeof(code)/sizeof(code[0]); ++j)
				if (is_same_in_start(p, code[j]))
					sel = j;
			if (sel == -1)
				break;

			p += strlen(code[sel]);
			dec[i] = dest[sel];
		}

		printf("%s\n", dec);
	}

	return 0;
}