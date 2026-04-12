#include <bits/stdc++.h>

using namespace std;

int n, a[3010];
long long dp[3010][3010];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = max(a[i] - dp[i + 1][j], a[j - 1] - dp[i][j - 1]);
		}
	}
	
	cout << dp[0][n] << '\n';
}
