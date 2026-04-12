#include <bits/stdc++.h>

typedef long long LL;
const int N = 3005;

int n, mod, dp[N];

int pow(int x, int y, int ans = 1, int mod = ::mod) {
	for (; y; y >>= 1, x = (LL) x * x % mod)
		if (y & 1) ans = (LL) ans * x % mod;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> mod;
	int c = 1, ans = 0; dp[0] = 1;
	for (int i = 0; i <= n; ++i) {
		int x = pow(2, n - i), y = 1, sum = 0;
		for (int j = 0; j <= i; ++j, y = (LL) y * x % mod)
			sum = (sum + (LL) y * dp[j]) % mod;
		ans = (ans + (LL) c * pow(2, pow(2, n - i, 1, mod - 1), sum)) % mod;
		c = (LL) c * pow(i + 1, mod - 2, i - n + mod) % mod;
		for (int j = i + 1; j; --j)
			dp[j] = (dp[j - 1] + (LL) (j + 1) * dp[j]) % mod;
	}
	std::cout << ans << '\n';
	return 0;
}