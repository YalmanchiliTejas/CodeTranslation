#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w;
	bool tate[100] = {}, yoko[100] = {};
	cin >> h >> w;
	string s[100];
	for (int i = 0; i < h; ++i)
	{
		cin >> s[i];
	}
	for (int i = 0; i < h; ++i)
	{
		int way = 0;
		for (int j = 0; j < w; ++j)
		{
			way += (s[i][j] == '.');
		}
		if (way == w)
		{
			yoko[i] = 1;
		}
	}
	for (int i = 0; i < w; ++i)
	{
		int way = 0;
		for (int j = 0; j < h; ++j)
		{
			way += (s[j][i] == '.');
		}
		if (way == h)
		{
			tate[i] = 1;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		if (!yoko[i])
		{
			for (int j = 0; j < w; ++j)
			{
				if(!tate[j])
				{
					cout << s[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}