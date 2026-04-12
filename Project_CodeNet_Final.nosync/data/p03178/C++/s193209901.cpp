#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;


int main() {
	string s; cin >> s;
	int d; cin >> d;
	vector<vector<vector<ll> > > dp(s.size()+1, vector<vector<ll> >(d, vector<ll>(2)));
	dp[0][0][0] = 1;

	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < d; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				dp[i+1][(j+k)%d][1] += dp[i][j][1];
				dp[i+1][(j+k)%d][1] %= MOD;
				if (s[i]-'0' == k)
				{
					dp[i+1][(j+k)%d][0] += dp[i][j][0];
					dp[i+1][(j+k)%d][0] %= MOD;
				} else if (s[i]-'0' > k) {
					dp[i+1][(j+k)%d][1] += dp[i][j][0];
					dp[i+1][(j+k)%d][1] %= MOD;
				}
			}
		}
	}
	ll ans = dp[s.size()][0][0] + dp[s.size()][0][1] - 1;
	cout << (ans+MOD)%MOD << endl;
	return 0;
}