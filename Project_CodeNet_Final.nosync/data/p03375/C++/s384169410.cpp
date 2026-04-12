#include <bits/stdc++.h>
using namespace std;
int power(int a, int b, int p) {
	int c = 1;
	while (b > 0) {
		if (b & 1)
			c = 1LL * c * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p;
	cin >> n >> p;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1)), c(n + 1, vector<int>(n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * (j + 1)) % p;
			dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % p;
		}
	}
	for (int i = 0; i <= n; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int res = 0;
		int sets = power(2, n - i, p);
		for (int j = 0, x = 1; j <= i; ++j) {
			res = (res + 1LL * dp[i][j] * x) % p;
			x = 1LL * x * sets % p;
		}
		res = 1LL * res * power(2, power(2, n - i, p - 1), p) % p * c[n][i] % p;
		ans = (ans + (i % 2 == 0 ? res : p - res)) % p;
	}
	cout << ans << endl;
	return 0;
}