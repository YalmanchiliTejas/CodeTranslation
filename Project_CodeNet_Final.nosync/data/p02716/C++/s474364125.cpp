#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 13;
const int hell = 1e9 + 7;

signed main () {
	int n;
	cin >> n;
	vector < int > a(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	long long dp[(n >> 1) + (n & 1) + 1][2][2];
	for (int i = 0; i <= (n >> 1) + (n & 1); ++i) {
		for (int j = 0; j <= 1; ++j) {
			for (int w = 0; w <= 1; ++w) 
				dp[i][j][w] = -inf;
		}
	}
	dp[1][0][0] = a[1], dp[1][1][0] = a[2], dp[1][0][1] = 0LL;
	for (int i = 2; i <= (n >> 1); ++i) {
		int x = a[2 * i - 1], y = a[2 * i];
		dp[i][0][0] = dp[i - 1][0][0] + x;
		dp[i][0][1] = max(max(dp[i - 1][0][0], dp[i - 1][1][0]), dp[i - 1][0][1] + x);
		dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + y;
		dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1]) + y;
	}
	if ((n & 1) && (n > 2)) {
		dp[(n >> 1) + (n & 1)][0][1] = max(max(dp[(n >> 1)][0][0], dp[(n >> 1)][1][0]), dp[(n >> 1)][0][1] + a.back());
		cout << dp[(n >> 1) + (n & 1)][0][1] << '\n';
	}
	else 
		cout << max(dp[(n >> 1)][0][0], dp[(n >> 1)][1][0]) << '\n';
}
