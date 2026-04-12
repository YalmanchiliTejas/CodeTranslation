#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 14, maxm = 200, mod = 998244353;
int n, m, lim, k, fact[maxn + 3], finv[maxn + 3], f[maxn + 3], g[maxn + 3];
int rev[maxn + 3], a[maxn + 3], b[maxn + 3];

int func(int x) {
	return x < mod ? x : x - mod;
}

int qpow(int a, int b) {
	if (b < 0) b += mod - 1;
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

void prework(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
	}
	finv[n] = qpow(fact[n], mod - 2);
	for (int i = n; i; i--) {
		finv[i - 1] = 1ll * finv[i] * i % mod;
	}
}

void dft(int a[], int n, int type) {
	for (int i = 0; i < n; i++) if (i < rev[i]) {
		swap(a[i], a[rev[i]]);
	}
	for (int k = 1; k < n; k <<= 1) {
		int x = qpow(3, (mod - 1) / (k << 1) * type);
		for (int i = 0; i < n; i += k << 1) {
			int y = 1;
			for (int j = i; j < i + k; j++, y = 1ll * x * y % mod) {
				int p = a[j], q = 1ll * a[j + k] * y % mod;
				a[j] = func(p + q), a[j + k] = func(p - q + mod);
			}
		}
	}
	if (type == -1) {
		int x = qpow(n, mod - 2);
		for (int i = 0; i < n; i++) {
			a[i] = 1ll * a[i] * x % mod;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	prework(n + 2);
	for (lim = 1, k = 0; lim <= n * 2; lim <<= 1) k++;
	for (int i = 1; i < lim; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	}
	f[0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			a[j] = 1ll * f[j] * finv[j] % mod;
		}
		b[0] = 0;
		for (int j = 1; j <= n; j++) {
			b[j] = finv[j + 2];
		}
		fill(a + n + 1, a + lim, 0);
		fill(b + n + 1, b + lim, 0);
		dft(a, lim, 1), dft(b, lim, 1);
		for (int j = 0; j < lim; j++) {
			g[j] = 1ll * a[j] * b[j] % mod;
		}
		dft(g, lim, -1);
		for (int j = 0; j <= n; j++) {
			g[j] = (1ll * g[j] * fact[j + 2] + 1ll * f[j] * (j * (j + 1) / 2 + 1)) % mod;
		}
		for (int j = 0; j <= n; j++) {
			f[j] = g[j];
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = (ans + 1ll * finv[i] * finv[n - i] % mod * f[i]) % mod;
	}
	ans = 1ll * ans * fact[n] % mod;
	printf("%d\n", ans);
	return 0;
}