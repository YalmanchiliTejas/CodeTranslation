#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define ri rd<int>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
using namespace std;
typedef long long LL;
const int O = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 107;

template<class T> T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

template<class T> inline void apadd(int &x, T y) { x = (x + y) % O; }
inline void apmax(int &x, int y) { if (x < y) x = y; }
inline void apmin(int &x, int y) { if (x > y) x = y; }

int pwr(int x, int t) {
	int res = 1;
	for (; t; t >>= 1, x = 1LL * x * x % O)
		if (t & 1) res = 1LL * res * x % O;
	return res;
}

struct Node {
	int f[2][2][2][2];
	Node() { memset(f, 0, sizeof f); }

	Node flow(int t) const {
		if (t == 0) return *this;
		Node res;
		int tmp = pwr(2, t-1);
		rep (l, 0, 1) rep (r, 0, 1) rep (a, 0, 1) rep (b, 0, 1) {
			if (a || b) {
				if (t & 1) apadd(res.f[l^1][r^1][b][a], f[l][r][a][b]);
				else apadd(res.f[l][r][a][b], f[l][r][a][b]);
			}
			else {
				apadd(res.f[l^1][r^1][0][0], 1LL * f[l][r][0][0] * tmp);
				apadd(res.f[l][r][0][0], 1LL * f[l][r][0][0] * tmp);
			}
		}
		return res;
	}

	Node operator + (const Node &v) const {
		Node res;
		rep (l, 0, 1) rep (r, 0, 1) rep (a, 0, 1) rep (b, 0, 1) 
		rep (ll, 0, 1) rep (rr, 0, 1) rep (aa, 0, 1) rep (bb, 0, 1) 
			apadd(res.f[l][rr][a || aa || (r==0&&ll==0)][b || bb || (r==1&&ll==1)], 1LL * f[l][r][a][b] * v.f[ll][rr][aa][bb]);
		return res;
	}
}a[maxN];

int n;
int h[maxN];

Node solve(int l, int r, int dw) {
	int m1 = INF;
	rep (i, l, r) apmin(m1, h[i]);
	Node res;
	for (int i = l, j = i; i <= r; i = j + 1, j = i) {
		if (h[i] == m1) {
			Node tmp; tmp.f[0][0][0][0] = tmp.f[1][1][0][0] = 1;
			if (i == l) res = tmp;
			else res = res + tmp;
		}
		else {
			for (; j <= r && h[j] > m1; ++j); --j;
			Node tmp = solve(i, j, m1);
			if (i == l) res = tmp;
			else res = res + tmp;
		}
	}
	return res.flow(m1 - dw);
}

int main() {

	n = ri();
	rep (i, 1, n) h[i] = ri();
	
	Node res = solve(1, n, 1);
	LL ans = 0;
	rep (l, 0, 1) rep (r, 0, 1) rep (a, 0, 1) rep (b, 0, 1) ans += res.f[l][r][a][b];
	printf("%lld\n", (ans % O + O) % O);

	return 0;
}
