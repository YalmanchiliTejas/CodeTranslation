#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 1 << 14, P = 998244353;
int n, m, fac[N], ifac[N], f[2][N], coef[N];

int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1LL * a * a % P)
		if (x & 1) ans = 1LL * ans * a % P;
	return ans;
}

int w[N];
void init(int n) {
	w[n / 2] = 1;
	int pr = power(3, (P - 1) / n);
	for (int i = 1; i < n / 2; ++i)
		w[n / 2 + i] = 1ll * w[n / 2 + i - 1] * pr % P;
	for (int i = n / 2 - 1; i >= 1; --i)
		w[i] = w[i << 1];
}
void dft(int *_a, int n) {
	static ull a[N];
	for (int i = 0; i < n; ++i) a[i] = (_a[i] % P + P) % P;
	for (int i = 0, j = 0; i < n; ++i) {
		if (i > j) swap(a[i], a[j]);
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}
	for (int d = 1; d < n; d <<= 1)
		for (int i = 0; i < n; i += d << 1)
			for (int j = 0; j < d; ++j) {
				ull tmp = a[i + d + j] * w[d + j] % P;
				a[i + d + j] = a[i + j] + P - tmp, a[i + j] += tmp;
			}
	for (int i = 0; i < n; ++i)
		_a[i] = a[i] % P;
}
void idft(int *a, int n) {
	reverse(a + 1, a + n);
	dft(a, n);
	for (int i = 0, t = power(n, P - 2); i < n; ++i)
		a[i] = 1ll * a[i] * t % P;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = fac[0] = 1; i <= n + 2; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n + 2] = power(fac[n + 2], P - 2);
	for (int i = n + 2; i; --i) ifac[i - 1] = 1ll * ifac[i] * i % P;
	f[0][0] = 1;
	for (int j = 1; j <= n; ++j) coef[j] = ifac[j + 2];
	int len = 1;
	while (len <= n + n) len <<= 1;
	init(len);
	dft(coef, len);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i & 1][j] = 1ll * f[i - 1 & 1][j] * (j * (j + 1) / 2 + 1) % P;
			f[i - 1 & 1][j] = 1ll * f[i - 1 & 1][j] * ifac[j] % P;
		}
		dft(f[i - 1 & 1], len);
		for (int j = 0; j < len; ++j)
			f[i - 1 & 1][j] = 1ll * f[i - 1 & 1][j] * coef[j] % P;
		idft(f[i - 1 & 1], len);
		for (int j = 0; j <= n; ++j)
			f[i & 1][j] = (f[i & 1][j] + 1ll * f[i - 1 & 1][j] * fac[j + 2]) % P;
		fill(f[i & 1] + n + 1, f[i & 1] + len, 0);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = (ans + 1ll * f[m & 1][i] * ifac[i] % P * ifac[n - i]) % P;
	ans = 1ll * ans * fac[n] % P;
	printf("%d\n", ans);
	return 0;
}
