#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define fore(e, u, v) for (int p = e(u), v = e[p].y; p; v = e[p = e[p].nxt].y)
#define ri rd<int>
using namespace std;
const int maxN = 1e5 + 7;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

inline void TAK() { puts("First"); exit(0); }
inline void NIE() { puts("Second"); exit(0); }

int n;
int deg[maxN], sz[maxN];

struct vec {
	static const int maxE = maxN;
	int g[maxN], te;
	struct edge {int y, nxt;} e[maxE << 1];
	inline void push(int x, int y) {e[++te] = (edge){y, g[x]}; g[x] = te;}
	inline void link(int x, int y) {push(x, y), push(y, x); ++deg[x], ++deg[y];}
	inline int& operator () (int x) {return g[x];}
	inline edge& operator [] (int x) {return e[x];}
}e;

void dfs(int x, int fa) {
	sz[x] = 1;
	int f = 0;
	fore (e, x, y) if (y != fa) {
		dfs(y, x);
		sz[x] += sz[y];
		if (sz[y] & 1) ++ f;
	}
	if (f > 1) TAK();
}

int main() {

	n = ri();
	For (i, 1, n) e.link(ri(), ri());
	if (n & 1) TAK();
	if (n == 2) NIE();
	rep (i, 1, n) if (deg[i] > 1) {
		dfs(i, 0);
		break;
	}

	NIE();
	return 0;
}