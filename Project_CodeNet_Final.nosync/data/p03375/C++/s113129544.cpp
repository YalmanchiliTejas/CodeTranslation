#include <iostream>

using i64 = long long;

const int N = 3000 + 7;

int n;
i64 p, ans;

i64 binom[N][N], stirl[N][N];
i64 power(i64 a, i64 k, i64 p) {
	i64 t = 1;
	for (; k; a = a * a % p, k >>= 1)
		if (k & 1) t = t * a % p;
	return t;
}

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d%lld", &n, &p);
	for (int i = 0; i <= n + 1; ++i)
		for (int j = binom[i][0] = 1; j <= i; ++j)
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % p;
	stirl[0][0] = 1;
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 1; j <= i; ++j)
			stirl[i][j] = (stirl[i - 1][j - 1] + stirl[i - 1][j] * j) % p;
	for (int i = 0; i <= n; ++i) {
		i64 res = 0;
		for (int j = 0; j <= i; ++j)
			( res += stirl[i + 1][j + 1] * power(2, 1ll * (n - i) * j, p) ) %= p;
		( ans += (i & 1 ? -1 : 1) * binom[n][i] * power(2, power(2, n - i, p - 1), p) % p * res ) %= p;
	}
	printf("%lld", (ans + p) % p);

	return 0;
}
