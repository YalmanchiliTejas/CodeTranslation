#include <bits/stdc++.h>

#define For(i, l, r) for (register int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for (register int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Rep(i, r) for (register int i = (0), i##end = (int)(r); i < i##end; ++i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl

using namespace std;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
	int x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
#ifdef zjp_shadow
	freopen ("E.in", "r", stdin);
	freopen ("E.out", "w", stdout);
#endif
}

const int N = 1e3 + 1e2, Mod = 1e9 + 7;

inline int fpm(int x, int power) {
	int res = 1;
	for (; power; power >>= 1, x = 1ll * x * x % Mod)
		if (power & 1) res = 1ll * res * x % Mod;
	return res;
}

int f[N][N], fac[N], ifac[N], Pow[N];

void Fac_Init(int maxn) {
	fac[0] = ifac[0] = 1;
	For (i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2);
	Fordown (i, maxn - 1, 1) ifac[i] = ifac[i + 1] * (i + 1ll) % Mod;
}

int main () {

	File();

	int n = read(), a = read(), b = read(), c = read(), d = read();

	Fac_Init(n);

	f[a - 1][0] = 1;
	For (i, a, b) {
		For (j, 0, n) f[i][j] = f[i - 1][j];
		Pow[0] = 1;
		For (j, 1, n) Pow[j] = 1ll * Pow[j - 1] * ifac[i] % Mod;

		For (j, c * i, n) For (k, c, min(d, j / i))
			f[i][j] = (f[i][j] + 1ll * f[i - 1][j - i * k] * Pow[k] % Mod * ifac[k]) % Mod;
	}
	printf ("%lld\n", 1ll * f[b][n] * fac[n] % Mod);

	return 0;

}