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
	freopen ("x.in", "r", stdin);
	freopen ("x.out", "w", stdout);
}

const int N = 1e5 + 1e3, Mod = 998244353;

namespace Computation {

	inline void add(int &a, int b) { if ((a += b) >= Mod) a -= Mod; }
	inline void sub(int &a, int b) { if ((a -= b) < 0) a += Mod; }
#define plus Plus
	inline int plus(int a, int b) { return (a += b) >= Mod ? a - Mod : a; }
	inline int dec(int a, int b) { return (a -= b) < 0 ? a + Mod : a; }
	inline int mul(int a, int b) { return 1ll * a * b % Mod; }
	inline int fpm(int x, int power) {
		int res = 1;
		for (; power; power >>= 1, x = mul(x, x))
			if (power & 1) res = mul(res, x);
		return res;
	}
	inline void div(int &a, int b) { a = mul(a, fpm(b, Mod - 2)); }

	int fac[N], ifac[N];
	void Fac_Init(int maxn) {
		fac[0] = ifac[0] = 1;
		For (i, 1, maxn) fac[i] = mul(fac[i - 1], i);
		ifac[maxn] = fpm(fac[maxn], Mod - 2);
		Fordown (i, maxn - 1, 1) ifac[i] = mul(ifac[i + 1], i + 1);
	}

	inline int comb(int n, int m) {
		return mul(mul(fac[n], ifac[m]), ifac[n - m]);
	}

};

using namespace Computation;

namespace Poly {

	const int Maxn = 1 << 20, g = 3;

	int powg[Maxn], invpowg[Maxn];

	void NTT_Init() {
		for (int i = 2; i < Maxn; i <<= 1)
			invpowg[i] = fpm(powg[i] = fpm(g, (Mod - 1) / i), Mod - 2);
	}

	int len, rev[Maxn];

	void NTT(int *P, int opt) {
		Rep (i, len) if (i < rev[i]) swap(P[i], P[rev[i]]);
		for (int i = 2, p = 1; i <= len; p = i, i <<= 1) {
			int Wi = opt == 1 ? powg[i] : invpowg[i];
			for (int j = 0; j < len; j += i)
				for (int k = 0, x = 1; k < p; ++ k) {
					int u = P[j + k], v = mul(x, P[j + k + p]);
					P[j + k] = (u + v) % Mod; 
					P[j + k + p] = (u - v + Mod) % Mod; 
					x = mul(x, Wi);
				}
		}
		if (!~opt) {
			int inv = fpm(len, Mod - 2);
			Rep (i, len) P[i] = mul(P[i], inv);
		}
	}

	int A[Maxn], B[Maxn], C[Maxn];
	void Mult(int *a, int *b, int *c, int na, int nb) {
		int nc = na + nb, bit = 0;
		for (len = 1; len <= nc; len <<= 1) ++ bit;
		Rep (i, len) A[i] = i <= na ? a[i] : 0;
		Rep (i, len) B[i] = i <= nb ? b[i] : 0;
		Rep (i, len) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
		NTT(A, 1); NTT(B, 1);
		Rep (i, len) C[i] = mul(A[i], B[i]);
		NTT(C, -1);
		For (i, 0, nc) c[i] = C[i];
	}

}

int n, m, a[N], b[N], c[N];

#define lowbit(x) (x & -x)

template<int Maxn>
struct Fenwick_Tree {

	int sumv[Maxn];

	inline void update(int pos, int uv) {
		for (pos = n - pos + 1; pos <= n; pos += lowbit(pos))
			sumv[pos] += uv;
	}

	inline int query(int pos) {
		int res = 0;
		for (pos = n - pos + 1; pos; pos -= lowbit(pos))
			res += sumv[pos];
		return res;
	}

};

Fenwick_Tree<N> T;

vector<int> V[N];

int f[210][8010];

int Min[N], Max[N], id[N];

int A[N], B[N], C[N];

int main () {

	int opt = 2;

	n = read(); m = read(); Fac_Init(n + 2);

	if (opt < 2) For (i, 1, n) a[i] = read();
	if (opt < 1) For (i, 1, m) b[i] = read();

	if (!opt) {
		int ans = 1;
		For (i, 1, n) V[a[i]].push_back(i);
		For (i, 1, m) {
			int cur = b[i];
			for (int v : V[i])
				chkmax(cur, v), T.update(v, 1);
			if (cur > n) continue;
			ans = mul(ans, T.query(cur));
		}
		printf ("%d\n", ans);
	}

	if (opt == 1) {
		For (i, 1, m) Min[i] = n + 1, id[i] = i;
		For (i, 1, n)
			chkmax(Max[a[i]], i), chkmin(Min[a[i]], i);
		sort(id + 1, id + n + 1, [&](int lhs, int rhs) { return a[lhs] < a[rhs]; });

		int j = 1, ans = 1;
		For (i, 1, m) {
			for (; j <= n && a[id[j]] <= i; ++ j) T.update(id[j], 1);
			if (Min[i] == n + 1) ans = mul(ans, plus(comb(j, 2), 1));
			else ans = mul(ans, mul(T.query(Max[i]), j - T.query(Min[i])));
		}
		printf ("%d\n", ans);
	}

	if (opt == 2) {

		Poly :: NTT_Init();

		f[0][0] = 1;
		Rep (j, m) {
			For (i, 0, n) A[i] = mul(f[j][i], ifac[i]);
			For (i, 1, n) B[i] = ifac[i + 2];
			Poly :: Mult(A, B, C, n, n);
			For (i, 0, n) {
				f[j + 1][i] = mul(C[i], fac[i + 2]);
				add(f[j + 1][i], mul(f[j][i], plus(1, comb(i + 1, 2))));
			}
		}

		int ans = 0;
		For (i, 0, n) {
			add(ans, mul(comb(n, i), f[m][i]));
		}
		printf ("%d\n", ans);

	}

	return 0;

}