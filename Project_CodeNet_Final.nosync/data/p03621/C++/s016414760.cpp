#include <bits/stdc++.h>
#define N 140000
#define lg2(x) (31 - __builtin_clz(x))
using std::reverse;

typedef long long ll;
const ll mod = 998244353, root = 31;

int A, B, n;
char scx[2][N], *p, *q;
int z[N], y[N], buf1[N], buf2[N];
int fact[N], finv[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(){
	int i;
	for(*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i; finv[i] = PowerMod(fact[i], mod - 2);
	for(; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

namespace Poly {
	int l, n; ll iv;
	int x[N], y[N], buf[N];
	int rev[N];

	void NTT_init(int length) {
		n = 1 << (l = length); iv = PowerMod(n, mod - 2);
		ll g = PowerMod(root, 1 << 23 - l);
		x[0] = 1; rev[0] = 0;
		for (int i = 1; i < n; ++i) {
			x[i] = (ll)x[i - 1] * g % mod;
			rev[i] = (i & 1 ? rev[i - 1] | 1 << (l - 1) : rev[i >> 1] >> 1);
		}
	}

	void DNTT(int *d, int *t){
		int i, *j, *k, len = 1, delta = n, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k){
					R = (ll)y[k - j] * k[len] % mod;
					k[len] = (*k - R < 0 ? *k - R + mod : *k - R);
					*k = (*k + R >= mod ? *k + R - mod : *k + R);
				}
			len <<= 1;
		}
	}
}

using Poly::DNTT;

void PolyPowerMod(int n, int k) {
	Poly::NTT_init(lg2(k) + 2); int n0 = Poly::n, i;
	for (; n; n >>= 1) {
		if (n & 1) {
			DNTT(y, buf1); DNTT(z, buf2);
			for (i = 0; i < n0; ++i) buf1[i] = (ll)buf1[i] * buf2[i] % mod;
			DNTT(buf1, y); reverse(y + 1, y + n0);
			for (i = 0; i <= k; ++i) y[i] = y[i] * Poly::iv % mod;
			for (; i < n0; ++i) y[i] = 0;
		}
		DNTT(z, buf1);
		for (i = 0; i < n0; ++i) buf1[i] = (ll)buf1[i] * buf1[i] % mod;
		DNTT(buf1, z); reverse(z + 1, z + n0);
		for (i = 0; i <= k; ++i) z[i] = z[i] * Poly::iv % mod;
		for (; i < n0; ++i) z[i] = 0;
	}
}

int main() {
	int i; ll ans = 0;
	scanf("%s%s", scx[0], scx[1]);
	for (p = scx[0], q = scx[1]; *p; ++p, ++q) A += *p & *q & 1, B += *p & ~*q & 1;
	n = A + B; init();
	for (i = 0; i <= A; ++i) z[i] = finv[i + 1];
	*y = 1; PolyPowerMod(B, A);
	for (i = 0; i <= A; ++i) ans += y[i];
	ans = ans % mod * fact[A] % mod * fact[B] % mod * fact[A + B] % mod;
	printf("%lld\n", ans);
	return 0;
}