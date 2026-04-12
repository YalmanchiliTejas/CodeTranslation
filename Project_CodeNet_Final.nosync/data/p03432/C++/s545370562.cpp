#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = (1 << 14) + 5;
const int MOD = 998244353;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

namespace ModCalculator {
	inline void Inc(int &x, int y) {
		x += y; if (x >= MOD) x -= MOD;
	}
	inline void Dec(int &x, int y) {
		x -= y; if (x < 0) x += MOD;
	}
	inline int Add(int x, int y) {
		Inc(x, y); return x;
	}
	inline int Sub(int x, int y) {
		Dec(x, y); return x;
	}
	inline int Mul(int x, int y) {
		return 1LL * x * y % MOD;
	}
}
using namespace ModCalculator;

inline int ksm(int x, int k) {
	int ret = 1;
	for (; k; k >>= 1) {
		if (k & 1) ret = Mul(ret, x);
		x = Mul(x, x);
	}
	return ret;
}

int n, m;
int fac[MAXN], finv[MAXN];
int len, lenv, rev[MAXN], w1[MAXN], w2[MAXN];
int dp[2][MAXN], F[MAXN], G[MAXN];

inline int C(int x, int y) {
	if (x < y) return 0;
	return Mul(fac[x], Mul(finv[y], finv[x - y]));
}

void NTT_init(int m) {
	int bit = -1;
	for (len = 1; len <= m; len <<= 1, ++bit);
	lenv = ksm(len, MOD - 2);
	for (int i = 0; i < len; ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit);
	}
	int Gi = 3, Gv = ksm(Gi, MOD - 2);
	for (int i = 1; i < len; i <<= 1) {
		int wn1 = ksm(Gi, (MOD - 1) / (i << 1)), wk1 = 1;
		int wn2 = ksm(Gv, (MOD - 1) / (i << 1)), wk2 = 1;
		for (int k = 0; k < i; ++k) {
			w1[i + k] = wk1;
			wk1 = Mul(wk1, wn1);
			w2[i + k] = wk2;
			wk2 = Mul(wk2, wn2);
		}
	}
}

void NTT(int *a, int type) {
	int *w = (type == 1? w1 : w2);
	for (int i = 0; i < len; ++i) {
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);
		}
	}
	for (int i = 1; i < len; i <<= 1) {
		for (int j = 0; j < len; j += (i << 1)) {
			for (int k = 0; k < i; ++k) {
				int x = a[j + k], y = Mul(w[i + k], a[j + k + i]);
				a[j + k] = Add(x, y);
				a[j + k + i] = Sub(x, y);
			}
		}
	}
	if (type == 1) return;
	for (int i = 0; i < len; ++i) {
		a[i] = Mul(a[i], lenv);
	}
}

void init() {
	read(n); read(m);
	fac[0] = 1;
	for (int i = 1; i <= n + 2; ++i) {
		fac[i] = Mul(fac[i - 1], i);
	}
	finv[n + 2] = ksm(fac[n + 2], MOD - 2);
	for (int i = n + 2; i >= 1; --i) {
		finv[i - 1] = Mul(finv[i], i);
	}
	NTT_init(n + n);
}

void solve() {
	G[0] = 0;
	for (int i = 1; i <= n; ++i) {
		G[i] = finv[i + 2];
	}
	NTT(G, 1);
	int pre = 0, cur = 1;
	dp[pre][0] = 1;
	for (int j = 1; j <= m; ++j) {
		for (int i = 0; i <= n; ++i) {
			dp[cur][i] = Mul(dp[pre][i], C(i + 1, 2) + 1);
			F[i] = Mul(dp[pre][i], finv[i]);
		}
		for (int i = n + 1; i < len; ++i) {
			F[i] = 0;
		}
		NTT(F, 1);
		for (int i = 0; i < len; ++i) {
			F[i] = Mul(F[i], G[i]);
		}
		NTT(F, -1);
		for (int i = 1; i <= n; ++i) {
			Inc(dp[cur][i], Mul(F[i], fac[i + 2]));
		}
		swap(pre, cur);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		Inc(ans, Mul(C(n, i), dp[pre][i]));
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}

