#include <bits/stdc++.h>
#define lg2 std::__lg

typedef long long ll;
const int N = 16400, mod = 998244353, root = 31;
typedef int vec[N], *pvec;

vec fact, finv;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

namespace Poly {
	int l, n;
	vec rev, x, y;

	void NTT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		ll g = PowerMod(root, 1 << (23 - l));
		*x = 1, *rev = 0;
		for (int i = 1; i < n; ++i)
			x[i] = x[i - 1] * g % mod, rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DNTT(int *d, int *t) {
		int i, *j, *k, len = 1, delta = n, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = (ll)y[k - j] * k[len] % mod,
					k[len] = (*k - R < 0 ? *k - R + mod : *k - R),
					*k = (*k + R >= mod ? *k + R - mod : *k + R);
			len <<= 1;
		}
	}

	vec B1;

	void Mul(int deg, pvec a, pvec b, pvec c) {
		if (!deg) {*c = (ll)*a * *b % mod; return;}
		NTT_init(lg2(deg) + 1);
		int i; ll iv = mod - (mod - 1) / n;
		DNTT(a, c), DNTT(b, B1);
		for (i = 0; i < n; ++i) B1[i] = (ll)B1[i] * c[i] % mod;
		DNTT(B1, c), std::reverse(c + 1, c + n);
		for (i = 0; i < n; ++i) c[i] = c[i] * iv % mod;
	}
}

int R, C;
vec f, g, h;
vec tr, tr_ntt;

int main() {
	int i, j, ans = 0; ll iv; init();
	scanf("%d%d", &R, &C), *f = 1;
	if (R == 1) return printf("%d\n", (int)PowerMod(2, C)), 0;
	for (i = 0; i < R; ++i) tr[i] = finv[i + 3];
	Poly::NTT_init(lg2(R - 1) + 2), iv = mod - (mod - 1) / Poly::n;
	Poly::DNTT(tr, tr_ntt);
	for (j = 0; j < C; ++j) {
		Poly::DNTT(f, g);
		for (i = 0; i < Poly::n; ++i) g[i] = g[i] * (ll)tr_ntt[i] % mod;
		Poly::DNTT(g, h), std::reverse(h + 1, h + Poly::n);
		for (i = 0; i < R; ++i) h[i] = h[i] * iv % mod;
		for (i = 1; i <= R; ++i)
			f[i] = ((i * (i + 1ll) + 2ll) / 2 * f[i] + (i + 1ll) * (i + 2ll) * h[i - 1]) % mod;
	}
	for (i = 0; i <= R; ++i) ans = (ans + (ll)f[i] * finv[R - i]) % mod;
	printf("%d\n", int((ll)ans * fact[R] % mod));
	return 0;
}