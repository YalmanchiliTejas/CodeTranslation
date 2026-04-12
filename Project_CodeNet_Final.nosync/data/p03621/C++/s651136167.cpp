#include <cstdio>
using namespace std;

typedef long long LL;
const int M = 20;
const int N = 32770;
const int Mod = 998244353;
int n, m, s[N], t[N], x[N], r[N], fac[N], inv[N];

inline void swap(int &a, int &b) {int t = a; a = b, b = t;}
inline void red(int &ls, int *a) {
	ls = 0; char ch = getchar();
	for (; ch<'0' || ch>'1';) ch = getchar();
	for (; ch>='0' && ch<='1';) a[++ls] = ch-'0', ch = getchar();
}

namespace FFT {
	int n, L, R[N], wn[N];
	inline int Qow(int A, int B) {
		int S = 1;
		for (; B; B >>= 1, A = 1LL * A * A % Mod)
			if (B & 1) S = 1LL * S * A % Mod;
		return S;
	}
	inline void init(int len) {
		for (n = 1, L = 0; n < len; n <<= 1, ++L);
		for (int i = 1; i < n; ++i)
			R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
		wn[0] = Qow(3, Mod - 1 >> L);
		for (int i = 1; i < L; ++i)
			wn[i] = 1LL * wn[i - 1] * wn[i - 1] % Mod;
	}
	inline void init_inv() {
		wn[0] = Qow(wn[0], Mod - 2);
		for (int i = 1; i < L; ++i)
			wn[i] = 1LL * wn[i - 1] * wn[i - 1] % Mod;
	}
	inline void Cpy(int *x, int n, int *y, int m) {
		for (int i = 0; i < n; ++i) y[i] = x[i];
		for (int i = n; i < m; ++i) y[i] = 0;
	}
	inline void FFT(int *x) {
		for (int i = 0; i < n; ++i) if (i < R[i]) swap(x[i], x[R[i]]);
		for (int i = 1, l = L - 1; i < n; i <<= 1, --l)
			for (int j = 0; j < n; j += i << 1)
				for (int u, v, k = 0, w = 1; k < i; ++k, w = 1LL * w * wn[l] % Mod)
					u = x[j + k], v = 1LL * w * x[i + j + k] % Mod,
					x[j + k] = (u + v) % Mod, x[i + j + k] = (u + Mod - v) % Mod;
	}
	inline void Mul(int *a, int n, int *b, int m, int *ret) {
		static int x[N], y[N];
		init(n + m - 1);
		Cpy(a, n, x, FFT::n), Cpy(b, m, y, FFT::n);
		FFT(x), FFT(y);
		for (int i = 0; i < FFT::n; ++i)
			x[i] = 1LL * x[i] * y[i] % Mod;
		init_inv(), FFT(x);
		int v = Qow(FFT::n, Mod - 2);
		for (int i = 0; i < FFT::n; ++i)
			ret[i] = 1LL * v * x[i] % Mod;
	}
}

int main() {
	int ls, ret = 0; red(ls, s), red(ls, t);
	for (int i = 1; i <= ls; ++i)
		if (s[i] && t[i]) ++n;
		else if (s[i] && !t[i]) ++m;
	
	r[0] = fac[0] = inv[0] = inv[1] = fac[1] = 1;
	for (int i = 2; i <= n + m + 1; ++i) fac[i] = 1LL * fac[i-1] * i % Mod;
	for (int i = 2; i <= n + m + 1; ++i) inv[i] = 1LL * (Mod - Mod/i) * inv[Mod%i] % Mod;
	for (int i = 2; i <= n + m + 1; ++i) inv[i] = 1LL * inv[i] * inv[i - 1] % Mod;
	for (int i = 0; i <= n; ++i) x[i] = inv[i + 1];
	
	for (int t = m; t; t >>= 1, FFT :: Mul(x, n + 1, x, n + 1, x))
		if (t & 1) FFT :: Mul(x, n + 1, r, n + 1, r);
	for (int i = 0; i <= n; ++i) ret = (ret + r[i]) % Mod;
	
	return printf("%lld\n", 1LL * ret * fac[n] % Mod * fac[m] % Mod * fac[n+m] % Mod), 0;
}