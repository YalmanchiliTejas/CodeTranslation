#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int n = ri();
	int a[n];
	int64_t sum = 0;
	for (int i = 0; i < n; i++) a[i] = ri(), sum += a[i];
	int64_t dp[n + 1][n + 1][2];
	memset(dp, 0, sizeof(dp));
	for (int i = n; i >= 0; i--) for (int j = n; j >= 0; j--) if (i + j < n) {
		dp[i][j][0] = std::max(dp[i + 1][j][1] + a[i], dp[i][j + 1][1] + a[n - j - 1]);
		dp[i][j][1] = std::min(dp[i + 1][j][0], dp[i][j + 1][0]);
	}
	std::cout << sum - 2 * dp[0][0][1] << std::endl;
	return 0;
}
