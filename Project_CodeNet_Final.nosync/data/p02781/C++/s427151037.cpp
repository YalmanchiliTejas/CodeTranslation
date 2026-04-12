#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string s; int p;
	cin >> s >> p;
	for(auto &i : s)i -= '0';
	int n = s.size();
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(110, vector<ll>(2))); //i桁目まで見て0がjこでフラグがk;
	dp[0][0][0] = 1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 105; j++) {
			for(int k = 0; k < 2; k++) {

				for(int d = 0; d <= (k ? 9 : s[i]); d++) {
					dp[i + 1][j + (d != 0)][k || d < s[i]] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n][p][0] + dp[n][p][1] << endl;
}