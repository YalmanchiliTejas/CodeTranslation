#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 10005;

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
	const int MOD = 998244353;
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
	inline int Ksm(int x, int k) {
		int ret = 1;
		for (; k; k >>= 1) {
			if (k & 1) ret = Mul(ret, x);
			x = Mul(x, x);
		}
		return ret;
	}
	inline int Inv(int x) {
		return Ksm(x, MOD - 2);
	}
} 
using namespace ModCalculator;

char a[MAXN], b[MAXN];
int n, A, B;
int fac[MAXN], finv[MAXN], dp[MAXN][MAXN];

inline int C(int x, int y) {
	return Mul(fac[x], Mul(finv[y], finv[x - y]));
}

void init() {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	for (int i = 1; i <= n; ++i) {
		if (a[i] == '1') {
			(b[i] == '1'? A : B) += 1;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = Mul(fac[i - 1], i);
	}
	finv[n] = Inv(fac[n]);
	for (int i = n; i >= 1; --i) {
		finv[i - 1] = Mul(finv[i], i);
	}
}

void solve() {
	dp[0][0] = 1;
	for (int i = 0; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			Inc(dp[i][j], Mul(dp[i][j - 1], j * j));
			if (i > 0) {
				Inc(dp[i][j], Mul(dp[i - 1][j], i * j));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= A; ++i) {
		Inc(ans, Mul(dp[A - i][B], Mul(Mul(fac[i], fac[i]), Mul(C(A, i), C(A + B, i)))));
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
