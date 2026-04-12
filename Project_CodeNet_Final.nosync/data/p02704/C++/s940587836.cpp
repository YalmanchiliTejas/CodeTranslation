#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct max_flow {
	static const int maxn = 1111, maxm = 9999999;
	int n, dis[maxn], que[maxn], ql, qr, cur[maxn], S, T;
	struct E {
		int to, lim, rev;
		E(int a, int b, int c): to(a), lim(b), rev(c) {}
	};
	vector <E> g[maxn];
	void init(int _n) {
		n = _n + 2;
		S = _n; T = _n + 1;
		rep(i, n) g[i].clear();
	}
	void _add_edge(int u, int v, int w) {
		g[u].pb(E(v, w, g[v].size()));
		g[v].pb(E(u, 0, g[u].size() - 1));
	}
	void add_edge(int u, int v, int lw, int hw) {
		_add_edge(S, v, lw);
		_add_edge(u, T, lw);
		_add_edge(u, v, hw - lw);
	}
	bool bfs(int S, int T) {
		ql = qr = 0; que[qr ++] = S;
		rep(i, n) dis[i] = -1;
		dis[S] = 0;
		while (ql ^ qr) {
			int u = que[ql ++];
			rep(i, g[u].size()) {
				int v = g[u][i].to, w = g[u][i].lim;
				if (w && !~dis[v]) {
					dis[v] = dis[u] + 1;
					que[qr ++] = v;
				}
			}
		}
		return ~dis[T];
	}
	int dfs(int u, int T, int f) {
		if (u == T) return f;
		int flow = 0;
		for (; cur[u] < int(g[u].size()); ++ cur[u]) {
			int v = g[u][cur[u]].to, w = g[u][cur[u]].lim;
			if (w && dis[v] == dis[u] + 1) {
				int d = dfs(v, T, min(f, w));
				if (!d) continue;
				g[u][cur[u]].lim -= d;
				g[v][g[u][cur[u]].rev].lim += d;
				flow += d; f -= d;
				if (!f) break;
			}
		}
		return flow;
	}
	void solve() {
		while (bfs(S, T)) {
			rep(i, n) cur[i] = 0;
			while (dfs(S, T, 0x3f3f3f3f));
		}
	}
} mf;

const int maxn = 505;

int n;
int s[maxn], t[maxn];
unsigned ll u[maxn], v[maxn];
unsigned ll ans[maxn][maxn];

bool chk() {
	rep(i, n) if (s[i]) {
		unsigned ll x = 0;
		rep(j, n) x |= ans[i][j];
		if (x != u[i]) return 0;
	}
	rep(i, n) if (!s[i]) {
		unsigned ll x = -1;
		rep(j, n) x &= ans[i][j];
		if (x != u[i]) return 0;
	}
	rep(i, n) if (t[i]) {
		unsigned ll x = 0;
		rep(j, n) x |= ans[j][i];
		if (x != v[i]) return 0;
	}
	rep(i, n) if (!t[i]) {
		unsigned ll x = -1;
		rep(j, n) x &= ans[j][i];
		if (x != v[i]) return 0;
	}
	return 1;
}

int main() {
//	freopen("in", "r", stdin);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &s[i]);
	rep(i, n) scanf("%d", &t[i]);
	rep(i, n) scanf("%llu", &u[i]);
	rep(i, n) scanf("%llu", &v[i]);
	rep(i, 64) {
		int S = n * 2, T = S + 1;
		mf.init(n * 2 + 2);
		rep(j, n) {
			if (!s[j]) {
				if (u[j] >> i & 1)
					mf.add_edge(S, j, n, n);
				else
					mf._add_edge(S, j, n - 1);
			} else {
				if (u[j] >> i & 1)
					mf.add_edge(S, j, 1, n);
				else
					mf._add_edge(S, j, 0);
			}
		}
		rep(j, n) {
			if (!t[j]) {
				if (v[j] >> i & 1)
					mf.add_edge(j + n, T, n, n);
				else
					mf._add_edge(j + n, T, n - 1);
			} else {
				if (v[j] >> i & 1)
					mf.add_edge(j + n, T, 1, n);
				else
					mf._add_edge(j + n, T, 0);
			}
		}
		rep(j, n) rep(k, n) mf._add_edge(j, k + n, 1);
		mf._add_edge(T, S, 0x3f3f3f3f);
		mf.solve();
		rep(j, n) rep(k, mf.g[j].size()) {
			if (mf.g[j][k].to - n < n && mf.g[j][k].to - n >= 0) {
				ans[j][mf.g[j][k].to - n] |= 
					(1ull - mf.g[j][k].lim) << i;
			}
		}
	}
	if (!chk()) puts("-1");
	else rep(i, n) rep(j, n) {
		printf("%llu", ans[i][j]);
		putchar(j + 1 == n ? '\n' : ' ');
	}
	return 0;
}
