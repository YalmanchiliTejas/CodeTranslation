#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
#define MOD 1000000007
int main() {
	std::string a;
	std::cin >> a;
	for (auto &c : a) c -= '0';
	int n = a.size();
	int d = ri();
	int dp[n][d][2]; // 1 : strict
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= a[0]; i++) dp[0][i % d][i == a[0]]++;
	auto add = [&] (int &i, int &j) {
		i += j;
		if (i >= MOD) i -= MOD;
	};
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 0; k <= a[i + 1]; k++) add(dp[i + 1][(j + k) % d][k == a[i + 1]], dp[i][j][1]);
			for (int k = 0; k < 10; k++) add(dp[i + 1][(j + k) % d][0], dp[i][j][0]);
		}
	}
	int res = dp[n - 1][0][0] + dp[n - 1][0][1] - 1;
	if (res >= MOD) res -= MOD;
	if (res < 0) res += MOD;
	std::cout << res << std::endl;
	return 0;
}
