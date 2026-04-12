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
	freopen ("D.in", "r", stdin);
	freopen ("D.out", "w", stdout);
#endif
}

const int N = 1e5 + 1e3;

struct edge {
	int u, v, w;
	edge(int u_ = 0, int v_ = 0, int w_ = 0): u(u_), v(v_), w(w_) {};
} E[N << 1];

int n, m, p[N], x[N], y[N], fa[N];

int find(int x) { 
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

int main() {

	File();

	n = read();
	For (i, 1, n)
		x[i] = read(), y[i] = read(), fa[i] = p[i] = i;

	sort(p + 1, p + n + 1, [&](int a, int b) { return x[a] < x[b]; });
	For (i, 1, n - 1) E[++ m] = edge(p[i], p[i + 1], x[p[i + 1]] - x[p[i]]);

	sort(p + 1, p + n + 1, [&](int a, int b) { return y[a] < y[b]; });
	For (i, 1, n - 1) E[++ m] = edge(p[i], p[i + 1], y[p[i + 1]] - y[p[i]]);

	long long ans = 0;
	sort(E + 1, E + m + 1, [&](edge a, edge b) { return a.w < b.w; } );
	For (i, 1, m) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (find(u) != find(v))
			fa[find(u)] = find(v), ans += w;
	}
	printf ("%lld\n", ans);

	return 0;

}