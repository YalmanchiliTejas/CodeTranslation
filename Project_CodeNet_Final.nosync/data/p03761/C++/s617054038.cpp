//Frame_mzq
#include <bits/stdc++.h>
using namespace std;

int Frame[256], loves, Mzq[256];
string s;
int main()
{
	cin >> loves >> s;
	for (register int i = 0;i < s.length();i ++)
	{
		Frame[s[i]] ++;
	}
	while(-- loves)
	{
		cin >> s;
		memset(Mzq, 0, sizeof(Mzq));
		for (register int i = 0;i < s.length();i ++)
		{
			Mzq[s[i]] ++;
		}
		for (register int i = 'a';i <= 'z';i ++)
		{
			Frame[i] = min(Frame[i], Mzq[i]);
		}
	}
	for (register int i = 'a';i <= 'z';i ++)
	{
		while(Frame[i] --) putchar(i);
	}
}