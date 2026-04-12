//「何らかの全域木からS--Tパス上の辺を取り除いたもの」を考えればよく、実は「MST - (S--Tパス上の最大コストの辺)」が答えになりそう。
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

struct UF {
	int par[4000];
	UF() { for (int i = 0; i < 4000; i++) par[i] = i; }
	int root(int x) { if (par[x] == x) return x; return par[x] = root(par[x]); }
	void unit(int x, int y) { x = root(x); y = root(y); par[x] = y; }
	bool isSame(int x, int y) { return root(x) == root(y); }
};

struct Edge {
	int from, to, cost;
	Edge(int from, int to, int cost) { this->from = from; this->to = to; this->cost = cost; }
	Edge() {}
	bool operator<(const Edge &r) const { return cost < r.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int n, m, q;
Edges edges;
UF uf;
Graph mst;
int parents[20][4000];
int depth[4000];
int maxScores[20][4000];

void dfs(int p, int v, int ecost, int dep) {
	parents[0][v] = p;
	depth[v] = dep;
	maxScores[0][v] = ecost;
	
	for (int i = 0; i < mst[v].size(); i++) {
		int nv = mst[v][i].to;
		if (nv == p) continue;
		dfs(v, nv, mst[v][i].cost, dep + 1);
	}
}

int maxPath(int u, int v) {
	int ret = 0, i;
	
	if (depth[u] > depth[v]) swap(u, v);
	if (depth[v] > depth[u]) {
		int d = depth[v] - depth[u];
		for (i = 0; i < 20; i++) {
			if ((d >> i) & 1) {
				ret = max(ret, maxScores[i][v]);
				v = parents[i][v];
			}
		}
	}
	if (u == v) { return ret; }
	if (parents[0][u] == parents[0][v]) {
		int res = max(maxScores[0][u], maxScores[0][v]);
		return max(ret, res);
	}
	
	for (i = 19; i > 0; i--) {
		if (parents[i][u] != parents[i][v]) break;
	}
	int res1 = maxPath(parents[i][u], parents[i][v]);
	int res2 = max(maxScores[i][u], maxScores[i][v]);
	int res = max(res1, res2);
	return max(ret, res);
}

signed main() {
	int i, j;
	
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges.push_back(Edge(a, b, c));
	}
	sort(edges.begin(), edges.end());
	
	int mstCost = 0;
	mst.resize(n);
	for (i = 0; i < edges.size(); i++) {
		int u = edges[i].from;
		int v = edges[i].to;
		
		if (!uf.isSame(u, v)) {
			uf.unit(u, v);
			mstCost += edges[i].cost;
			mst[u].push_back(Edge(u, v, edges[i].cost));
			mst[v].push_back(Edge(v, u, edges[i].cost));
		}
	}
	
	dfs(0, 0, 0, 0);
	for (i = 1; i < 20; i++) {
		for (j = 0; j < n; j++) {
			parents[i][j] = parents[i - 1][parents[i - 1][j]];
			maxScores[i][j] = max(maxScores[i - 1][j], maxScores[i - 1][parents[i - 1][j]]);
		}
	}
	
	cin >> q;
	for (i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t; s--; t--;
		if (n <= 2) { cout << 0 << endl; continue; }
		int res = maxPath(s, t);
		cout << mstCost - res << endl;
	}
	return 0;
}