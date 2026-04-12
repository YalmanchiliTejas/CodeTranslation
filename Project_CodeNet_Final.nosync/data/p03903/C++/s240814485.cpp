#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
const int M = 400005;

int n, m, q;
int lab[N];
vector < pair<int, int> > g[N];
int par[N][13], wei[N][13], dep[N];
long long tot;

struct edge {
	int u; int v; int w;
	bool operator < (const edge &other) const {
		return w < other.w;
	}
} ed[M];

int anc(int p) { return p == lab[p] ? p : lab[p] = anc(lab[p]); }
void join(int p, int q) { lab[p] = q; } // p = anc(p), q = anc(q)

void dfs(int u) {
	for (auto &e : g[u]) {
		int v = e.second, w = e.first;
		if (v == par[u][0]) continue;

		dep[v] = dep[u] + 1;
		par[v][0] = u;
		wei[v][0] = w;
		dfs(v);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 12; i >= 0; --i) if (dep[par[u][i]] >= dep[v]) u = par[u][i];
	for (int i = 12; i >= 0; --i) if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
	return u == v ? u : par[u][0];
}

int get_max(int u, int x) {
	int ret = 0;
	for (int i = 12; i >= 0; --i) {
		if (dep[par[u][i]] >= dep[x]) {
			ret = max(ret, wei[u][i]);
			u = par[u][i];
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	sort(ed, ed + m);

	for (int i = 1; i <= n; ++i) lab[i] = i;

	for (int i = 0; i < m; ++i) {
		int u = anc(ed[i].u);
		int v = anc(ed[i].v);
		if (u == v) continue;

		join(u, v);
		g[ed[i].u].push_back(make_pair(ed[i].w, ed[i].v));
		g[ed[i].v].push_back(make_pair(ed[i].w, ed[i].u));
		tot += ed[i].w;
	}

	par[1][0] = 1;
	dfs(1);
	for (int j = 1; j <= 12; ++j) {
		for (int i = 1; i <= n; ++i) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			wei[i][j] = max(wei[i][j - 1], wei[par[i][j - 1]][j - 1]);
		}
	}

	cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;
		int x = lca(u, v);

		int mx = max(get_max(u, x), get_max(v, x));

		printf("%lld\n", tot - mx);
	}
}