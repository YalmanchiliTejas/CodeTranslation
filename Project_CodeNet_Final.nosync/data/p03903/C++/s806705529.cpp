#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}

using ll = long long;
using R = long double;
const R EPS = 1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r) {return (r > EPS) - (r < -EPS);}
inline R sq(R x) {return sqrt(max(x, 0.0L));}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// Problem Specific Parameter:

// Description: 素集合を管理するデータ構造
// TimeComplexity: 初期化$\mathcal{O}(n)$ 更新$\mathcal{O}(\log n)$
// Verifyed: AOJ DSL_1_A

struct Union_find {
	Union_find(int n) {par.resize(n), iota(_all(par), 0);}
	int find(int x) {return (par[x] == x) ? x : par[x] = find(par[x]);}
	void unite(int a, int b) {a = find(a), b = find(b); par[a] = b;}
	bool same(int a, int b) {return find(a) == find(b);}
	vector<int> par;
};

using edge = struct {int to; ll cost;};
using G = vector<vector<edge>>;
G graph;

const int limit = 4010;
ll dist[limit][limit];

void dfs(int v, int p, int s, ll c) {
	chmax(dist[s][v], c);
	for (auto &e : graph[v]) {
		if (e.to == p) continue;
		dfs(e.to, v, s, max(c, e.cost));
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	using edge = tuple < ll, ll, ll>;
	vector<edge> edges;

	rep(i, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.push_back(edge(c, a, b));
	}

	sort(begin(edges), end(edges));
	Union_find uf(n);

	ll res = 0LL;
	graph = G(n);

	for (auto &e : edges) {
		ll c, a, b;
		tie(c, a, b) = e;
		if (uf.same(a, b)) continue;
		uf.unite(a, b);
		res += c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	rep(v, n) dfs(v, -1, v, 0LL);

	int q;
	cin >> q;
	rep(loop, q) {
		int s, t;
		cin >> s >> t;
		s--, t--;
		cout << res - dist[s][t] << endl;
	}
	return 0;
}