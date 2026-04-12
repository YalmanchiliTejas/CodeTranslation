//#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AC 0
#define mod 1000000007
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int d;
	cin >> s >> d;
	vector< vector<int> > dp(d, vector<int>(2));
	dp[0][1] = 1;
	for (int i = 0; i < s.size(); i++) {
		vector< vector<int> > new_dp(d, vector<int>(2));
		for(int j=0;j<d;j++)
			for (int k = 0; k < 2; k++) {
				int mx = k ? s[i] - '0' : 9;
				for (int l = 0; l <= mx; l++) new_dp[(j + l) % d][k && l == mx] = (new_dp[(j + l) % d][k && l == mx] + dp[j][k]) % mod;
			}
		for (int j = 0; j < d; j++)
			for (int k = 0; k < 2; k++)
				dp[j][k] = new_dp[j][k];
	}
	cout << (dp[0][0] + dp[0][1] - 1 + mod) % mod << '\n';
	return AC;
}