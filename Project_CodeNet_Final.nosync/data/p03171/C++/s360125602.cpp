#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3001;
int dp[maxn][maxn][2];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			dp[i][j][0] = LLONG_MIN;
			dp[i][j][1] = LLONG_MAX;
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int len = 1; len <= n - 1; len++) {
		for (int l = 1; l <= n; l++) {
			int r = l + len;
			if (r > n)continue;
			dp[l][r][0] = max(dp[l][r][0], dp[l + 1][r][1] + a[l]);
			dp[l][r][0] = max(dp[l][r][0], dp[l][r - 1][1] + a[r]);
			dp[l][r][1] = min(dp[l][r][1], dp[l + 1][r][0] - a[l]);
			dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] - a[r]);
		}
	}
	cout << dp[1][n][0];
	return 0;
}