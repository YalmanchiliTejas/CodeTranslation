#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[3001][3001][2];

int solve(int* a, int i, int j, int t) {

	if (i > j)return 0;

	if (dp[i][j][t] != -1)return dp[i][j][t];

	if (t == 1)return dp[i][j][t] = max(a[i] + solve(a, i + 1, j, 0) , a[j] + solve(a, i, j - 1, 0));
	else return dp[i][j][t] = min(solve(a, i + 1, j, 1), solve(a, i, j - 1, 1));

}

int32_t main() {
	int n;
	cin >> n;
	int a[n + 1];
	int i;
	for (i = 1; i <= n; i++)cin >> a[i];

	memset(dp, -1, sizeof(dp));
	int ans = solve(a, 1, n, 1);

	int sum = 0;
	for (i = 1; i <= n; i++)sum += a[i];

	int ansy = sum - ans;
	cout << ans - ansy << endl;
	return 0;
}