#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[3005][3005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i + j <= n; i++) {
			int k = i + j;
			int turn = (n - j) % 2;
			if (turn == 0) {
				dp[i][k] = max(dp[i][k - 1] + a[k - 1], dp[i + 1][k] + a[i]);
			} else {
				dp[i][k] = min(dp[i][k - 1] - a[k - 1], dp[i + 1][k] - a[i]);
			}
		}
	}
	cout << dp[0][n] << endl;
	return 0;
}