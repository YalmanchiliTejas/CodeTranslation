#include <bits/stdc++.h>
using namespace std;

long long dp[3001][3001][3];
const long long MOD = 998244353;

long long sum_mod (int x, int y) {
	if (x + y < MOD)
		return x + y;
	return x + y - MOD;
}

signed main () {
	int n, s;
	cin >> n >> s;
	vector < int > a(n);
	for (int &x: a)
		cin >> x;
	for (int i = 0; i <= n; ++i) 
		dp[i][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= s; ++j) {
			dp[i + 1][j][1] = sum_mod(dp[i + 1][j][1], sum_mod(dp[i][j][0], dp[i][j][1]));
			dp[i + 1][j][2] = sum_mod(dp[i + 1][j][2], sum_mod(sum_mod(dp[i][j][0], dp[i][j][1]), dp[i][j][2]));
			if (j + a[i] <= s) {
				dp[i + 1][j + a[i]][1] = sum_mod(dp[i + 1][j + a[i]][1], sum_mod(dp[i][j][0], dp[i][j][1]));
				dp[i + 1][j + a[i]][2] = sum_mod(dp[i + 1][j + a[i]][2], sum_mod(dp[i][j][0], dp[i][j][1]));
			}
		}
	}
	cout << dp[n][s][2] << '\n';
}
