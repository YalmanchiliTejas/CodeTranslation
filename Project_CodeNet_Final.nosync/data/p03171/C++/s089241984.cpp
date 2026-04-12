#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	pair<long long, long long> dp[n][n];
	for (int j = 0; j < n; j++) {
		for (int i = j; i >= 0; i--) {
			if (i == j) dp[i][j] = {a[i], 0};
			else {
				if (dp[i + 1][j].second + a[i] > dp[i][j - 1].second + a[j]) {
					dp[i][j] = {dp[i + 1][j].second + a[i], dp[i + 1][j].first};
				} else {
					dp[i][j] = {dp[i][j - 1].second + a[j], dp[i][j - 1].first};
				}
			}
		}
	}
	cout << dp[0][n - 1].first - dp[0][n - 1].second;
}