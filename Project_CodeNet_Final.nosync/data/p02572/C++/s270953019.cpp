#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 200001
#define int long long

const int mod = 1000000007;
int n, ans, a[MAXN], sum[MAXN];

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum[i] = (1ll * sum[i - 1] + 1ll * a[i]) % mod;
	}
	for (int i = 1; i < n; ++i) {
		ans = (ans + 1ll * a[i] * ((sum[n] - sum[i] + mod) % mod) % mod) % mod;
	}
	std::cout << ans << '\n';
	return 0;
}