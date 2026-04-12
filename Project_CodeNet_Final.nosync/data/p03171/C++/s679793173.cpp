#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3001;
int dp[maxn][maxn][2];
int solve(int l, int r, int type,vector<int>&a) {
	if (type == 1) {
		if (dp[l][r][0] != LLONG_MIN)return dp[l][r][0];
		if (r == l)return a[l];
		dp[l][r][0] = max(dp[l][r][0], solve(l + 1, r,2,a) + a[l]);
		dp[l][r][0] = max(dp[l][r][0], solve(l, r - 1, 2, a) + a[r]);
		return dp[l][r][0];
	}
	else {
		if (dp[l][r][1] != LLONG_MAX)return dp[l][r][1];
		if (r == l)return -a[l];
		dp[l][r][1] = min(dp[l][r][1], solve(l + 1, r, 1, a) - a[l]);
		dp[l][r][1] = min(dp[l][r][1], solve(l, r - 1, 1, a) - a[r]);
		return dp[l][r][1];
	}
}
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
	cout << solve(1, n, 1, a);
	return 0;
}