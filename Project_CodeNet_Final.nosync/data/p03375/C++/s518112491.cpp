#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 3005;

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

int n, mod;
int c[MAXN][MAXN], s[MAXN][MAXN];

inline void Inc(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}

inline void Dec(int &x, int y) {
	x -= y; if (x < 0) x += mod;
}

inline int Mul(int x, int y, int md) {
	return 1LL * x * y % md;
}

inline int ksm(int x, int k, int md) {
	int ret = 1;
	while (k) {
		if (k & 1) ret = Mul(ret, x, md);
		x = Mul(x, x, md);
		k >>= 1;
	}
	return ret;
}

void init() {
	read(n); read(mod);
	c[0][0] = s[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		c[i][0] = s[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j];
			Inc(c[i][j], c[i - 1][j - 1]);
			s[i][j] = Mul(s[i - 1][j], j + 1, mod);
			Inc(s[i][j], s[i - 1][j - 1]);
		}
	}
}

void solve() {
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int res = 0;
		int a = ksm(2, n - i, mod), b = ksm(2, ksm(2, n - i, mod - 1), mod);
		for (int j = 0; j <= i; ++j) {
			Inc(res, Mul(s[i][j], b, mod));
			b = Mul(b, a, mod);
		}
		res = Mul(res, c[n][i], mod);
		(i & 1)? Dec(ans, res) : Inc(ans, res);
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
