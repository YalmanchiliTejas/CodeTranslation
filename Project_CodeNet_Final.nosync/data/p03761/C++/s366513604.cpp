#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i <(n); i++)
using namespace std;

const int INF = (int)1e9;

signed main(void)
{
	int n, cnt, ans[26]; cin >> n;
	string s[n];
	string alpha = "abcdefghijklmnopqrstuvwxyz";

	rep(i, 26) ans[i] = INF;
	rep(i, n) cin >> s[i];
	rep(k, 26)
	{
		rep(j, n)
		{	
			cnt = 0;
			rep(i, s[j].size())
			{
				if (alpha[k] == s[j][i])
					cnt++;
			}
			ans[k] = min(ans[k], cnt);
		}
	}
	rep(i, 26)
		rep(j, ans[i])
			cout << alpha[i];
	cout << endl;
	return 0;
}
