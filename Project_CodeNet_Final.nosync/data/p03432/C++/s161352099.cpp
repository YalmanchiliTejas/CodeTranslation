#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, mod = 998244353;
int n, m, ans;
int inv[maxn + 10], fac[maxn + 10], ifac[maxn + 10];

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) { 
	return 1ll * x * y % mod;
}
inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

void init() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		inv[i] = i == 1 ? 1 : dec(0, mul(mod / i, inv[mod % i]));
		fac[i] = mul(fac[i - 1], i);
		ifac[i] = mul(ifac[i - 1], inv[i]);
	}
}

int comb(int x, int y) {
	return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

namespace fft {

	int rev[maxn + 10], l, lgl;

	void init(int n) {
		for (l = 1, lgl = -1; l <= n; l <<= 1) ++lgl;
		for (int i = 0; i < l; ++i)
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << lgl;
	}

	void dft(int *a) {
		for (int i = 0; i < l; ++i)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < l; i <<= 1) {
			int wn = fpow(3, (mod - 1) / (i << 1));
			for (int j = 0; j < l; j += i << 1)
				for (int k = 0, w = 1; k < i; ++k, w = mul(w, wn)) {
					int x = a[j + k], y = mul(w, a[i + j + k]);
					a[j + k] = add(x, y); a[i + j + k] = dec(x, y);
				}
		}
	}

	void idft(int *a) {
		reverse(a + 1, a + l); dft(a);
		int invl = fpow(l, mod - 2);
		for (int i = 0; i < l; ++i) a[i] = mul(a[i], invl);
	}

}
int a[maxn + 10], b[maxn + 10], c[maxn + 10];

int main() {
	init();
	scanf("%d%d", &n, &m);
	fft::init(n * 2);
	a[0] = 1;
	for (int i = 1; i <= n; ++i) c[i] = ifac[i + 2];
	fft::dft(c);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			b[j] = mul(a[j], j * (j + 1) / 2 + 1);
			a[j] = mul(a[j], ifac[j]);
		}
		fft::dft(a);
		for (int j = 0; j < fft::l; ++j) a[j] = mul(a[j], c[j]);
		fft::idft(a);
		for (int j = 1; j <= n; ++j) a[j] = add(b[j], mul(a[j], fac[j + 2]));
		a[0] = 1;
		for (int j = n + 1; j < fft::l; ++j) a[j] = 0;
	}
	for (int i = 0; i <= n; ++i)
		ans = add(ans, mul(comb(n, i), a[i]));
	printf("%d", ans);
}
