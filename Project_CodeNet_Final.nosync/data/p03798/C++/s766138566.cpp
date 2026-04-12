#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long
#define TIME cout << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << endl;

int n;
string s;
string assignment()
{
	VS ans(4, string(n, ' '));
	ans[0][0] = 'W', ans[0][1] = 'W';
	ans[1][0] = 'S', ans[1][1] = 'S';
	ans[2][0] = 'W', ans[2][1] = 'S';
	ans[3][0] = 'S', ans[3][1] = 'W';
	
	for(int iter = 0; iter < 4; ++iter)
	{
		bool valid = true;
		for(int i = 2; i < n; ++i)
		{
			int prev = (i - 1 < 0) ? n - 1 : i - 1;
			if(ans[iter][prev] == 'S' && s[prev] == 'o' ||
				ans[iter][prev] == 'W' && s[prev] == 'x')
			{
				int pp = (i - 2 < 0) ? i - 2 + n : i - 2;
				ans[iter][i] = ans[iter][pp];
			}
			else if(ans[iter][prev] == 'S' && s[prev] == 'x' ||
					ans[iter][prev] == 'W' && s[prev] == 'o')
			{
				int pp = (i - 2 < 0) ? i - 2 + n : i - 2;
				ans[iter][i] = 'W' + 'S' - ans[iter][pp];
			}
		}
		
		for(int i = 0; i < n; ++i)
		{
			int prev = (i - 1 < 0) ? n - 1 : i - 1;
			if(ans[iter][prev] == 'S' && s[prev] == 'o' ||
				ans[iter][prev] == 'W' && s[prev] == 'x')
			{
				int pp = (i - 2 < 0) ? i - 2 + n : i - 2;
				if(ans[iter][i] != ans[iter][pp]) {
					valid = false;
					break;
				}
			}
			else if(ans[iter][prev] == 'S' && s[prev] == 'x' ||
					ans[iter][prev] == 'W' && s[prev] == 'o')
			{
				int pp = (i - 2 < 0) ? i - 2 + n : i - 2;
				if(ans[iter][i] == ans[iter][pp]) {
					valid = false;
					break;
				}
			}
		}
		if(valid)
			return ans[iter];
	}
	 return "-1";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
	cin >> n >> s;

	cout << assignment() << endl;

	return 0;
}