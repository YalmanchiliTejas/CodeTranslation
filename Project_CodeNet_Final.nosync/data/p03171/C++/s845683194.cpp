#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;

int dp[4000][4000];
// int find(int arr[], int i, int j) {
// 	if (dp[i][j] != -1)
// 		return dp[i][j];
// 	if (i == j)
// 		return arr[i];
// 	int taro = INT_MIN, jiro = INT_MAX;
// 	taro = max(arr[i] + find(arr, i + 1, j) - jiro, arr[j] + find(arr, i, j - 1) - jiro);
// 	jiro = min(taro - arr[i] + find(arr, i + 1, j), taro - arr[j] + find(arr, i, j - 1));
// 	return dp[i][j] = taro - jiro;
// }


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	int arr[n + 5];
	// memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	// cout << find(arr, 0, n - 1);
	for (int i = n; i >= 0; i--) {
		for (int j = i; j <= n; j++) {
			dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
		}
	}
	cout << dp[1][n];
	return 0;
}