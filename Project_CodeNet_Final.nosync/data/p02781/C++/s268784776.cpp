#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PL = pair<ll,ll>;


int main()
{
	string s; ll t; cin >> s >> t;
	for(auto &i : s) i -= '0';
	ll n = s.size();
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(120, vector<ll>(2)));
	dp[0][0][0] = 1;

	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < 110; j++) {
			for(ll k = 0; k < 2; k++) {

				for(ll d = 0; d <= (k ? 9 : s[i]); d++) {
					dp[i + 1][j + (d != 0)][k || d < s[i]] += dp[i][j][k];
				}

			}
		}
	}
	cout << dp[n][t][0] + dp[n][t][1] << endl;

}