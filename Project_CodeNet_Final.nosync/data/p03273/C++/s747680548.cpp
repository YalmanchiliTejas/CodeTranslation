#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int h, w;
	cin >> h >> w;
	string s[h];
	bool flag_l[h], flag_r[w + 1];
	rep(i, h) {cin >> s[i]; s[i] +='\n';}
	rep(i, h) flag_l[i] = false; 
	rep(i, w + 1) flag_r[i] = false;
	rep(i, h) rep(j, w)
	{
		if (s[i][j] == '#')
			flag_l[i] = true;
	}
	rep(i, w + 1) rep(j, h)
	{
		if (s[j][i] != '.')
			flag_r[i] = true;
	}
	rep(i, h)
	{
		rep(j, w + 1)
		{
			if (flag_l[i] && flag_r[j])
				cout << s[i][j];
		}
	}
	return 0;
}
