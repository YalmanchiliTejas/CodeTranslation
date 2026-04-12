#include <bits/stdc++.h>
using namespace std;

map<int, int64_t> dp[200010][2];
const int64_t INF = 1e18;
int main() {
	int n; cin >> n;
	int64_t a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = (i - 1) / 2; k <= (i + 1) / 2; ++k) {
				dp[i][j][k] = -INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i < n; ++i) {
		for(int k = (i - 1) / 2; k <= (i + 1) / 2; ++k) {
			dp[i + 1][1][k + 1] = max(dp[i + 1][1][k + 1], dp[i][0][k] + a[i]);
			dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][0][k]);
			dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][1][k]);
		}
	}
	cout << max(dp[n][0][n / 2], dp[n][1][n / 2]) << '\n';
	return 0;
}