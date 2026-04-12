#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
#define MOD 998244353

int main() {
	int n = ri();
	int s = ri();
	int a[n];
	for (auto &i : a) i = ri();
	int dp[s + 1];
	memset(dp, 0, sizeof(dp));
	auto add = [] (int &i, int j) {
		i += j;
		if (i >= MOD) i -= MOD;
	};
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = s; j >= 0; j--) {
			if (j + a[i] == s) add(res, (int64_t) dp[j] * (n - i) % MOD);
			if (j + a[i] <= s) add(dp[j + a[i]], dp[j]);
		}
		if (a[i] <= s) add(dp[a[i]], i + 1);
		if (a[i] == s) add(res, (int64_t) (i + 1) * (n - i) % MOD);
	}
	printf("%d\n", res);
	return 0;
}
