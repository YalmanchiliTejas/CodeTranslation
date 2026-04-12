#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
	is >> p.first >> p.second;
	return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
	os << p.first << " " << p.second;
	return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}
/*
typedef __int128_t Int;
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
std::ostream::sentry s(dest);
  if (s) {
	__uint128_t tmp = value < 0 ? -value : value;
	char buffer[128];
	char *d = std::end(buffer);
	do {
	  --d;
	  *d = "0123456789"[tmp % 10];
	  tmp /= 10;
	} while (tmp != 0);
	if (value < 0) {
	  --d;
	  *d = '-';
	}
	int len = std::end(buffer) - d;
	if (dest.rdbuf()->sputn(d, len) != len) {
	  dest.setstate(std::ios_base::badbit);
	}
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
	if ('0' <= s[i] && s[i] <= '9')
	  ret = 10 * ret + s[i] - '0';
  return ret;
}
*/

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T> bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> bool chmin(T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
struct DisjointSet {
	// ２つのグループを１つにまとめる　と　2つの要素が同じグループに所属しているかどうかを判定する
	vector<int> rank, p, S; // p->parent  S[findSet(v)] ->連結成分の大きさ
	DisjointSet() {}
	DisjointSet(int size) {
		S.resize(size, 1);
		rank.resize(size, 0);
		p.resize(size, 0);
		rep(i, 0, size) makeSet(i);
	}
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y) { // 判定する
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) { // 連結するときにはこれを使う
		if (same(x, y))
			return;
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}

		S[x] = S[y] = S[x] + S[y];
	}
	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]); // path compression
		}
		return p[x];
	}
	int connectedComponentSize(int x) { return S[findSet(x)]; }
};




using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

vector<Edge> kruskal(int N, vector<Edge> &edges) {
	int totalCost = 0;
	sort(all(edges));
	DisjointSet dset(N);
	vector<Edge>mst;
	rep(i, 0, edges.size()) {
		Edge e = edges[i];
		if (!dset.same(e.s, e.d)) {
			mst.push_back(e);
			totalCost += e.w;
			dset.unite(e.s, e.d);
		}
	}
	return mst;
}

struct Tree { // rooted tree
	vector<vector<int>>parent,weight;
	Graph g;
	int root, V, log2_n;
	vector<int> depth;
	int get_depth(int x) { return depth[x]; }
	void dfs(int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		rep(i, 0, g[v].size()) {
			if (g[v][i].d != p) {
				weight[0][g[v][i].d] = g[v][i].w;
				dfs(g[v][i].d, v, d + 1);
			}
		}
	}
	Tree(Graph G, int root)
		: root(root), V(G.size()), g(G), depth(V), log2_n(1 + (int)log2(V)) {
		parent.resize(log2_n, vector<int>(V));
		weight.resize(log2_n, vector<int>(V));
		dfs(root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < V; v++) {
				if (parent[k][v] < 0) {
					parent[k + 1][v] = -1;
					weight[k + 1][v] = weight[k][v];
				}
				else {
					parent[k + 1][v] = parent[k][parent[k][v]];
					weight[k + 1][v] = max(weight[k][parent[k][v]], weight[k][v]);
				}
			}
		}
	}
	int lca(int u, int v) {
		int w = -1;
		if (depth[u] > depth[v])
			swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				chmax(w, weight[k][v]);
				v = parent[k][v];
			}
		}
		if (u == v)
			return w;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				chmax(w, weight[k][u]);
				chmax(w, weight[k][v]);
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		chmax(w, weight[0][u]);
		chmax(w, weight[0][v]);
		return w;
	}
};
signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, M; cin >> N >> M;
	vector<Edge>edges;
	rep(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		edges.eb(a, b, c);
	}
	auto mst = kruskal(N,edges);
	int sum = 0;
	Graph g(N);
	for (auto &e : mst) {
		addEdge(g, e.s, e.d, e.w);
		sum += e.w;
	}
	Tree tree(g, 0);

	int Q; cin >> Q;
	loop(Q) {
		int s, t; cin >> s >> t;
		s--, t--;
		int u = tree.lca(s, t);
		cout << sum - u << endl;
	}

	return 0;
}
