#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

using Weight = int;
struct Edge {
	int s, d; Weight w;
	Edge() {};
	Edge(int s, int d, Weight w) : s(s), d(d), w(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w == e2.w ? (e1.s == e2.s ? e1.d < e2.d : e1.s < e2.s) : e1.w < e2.w; }
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

struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
};

// 最小全域木
// Kruskal法
// 非連結グラフでは最小全域森
// 計算量: O(E log E)
// 引数: グラフ
// 戻り値: (総コスト, 辺集合, 木かどうか)
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235604
tuple<Weight, Edges, bool> kruskal(const Graph &g) {
	int n = g.size();
	UnionFind uf(n);
	Edges es;
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			es.push_back(e);
	sort(es.begin(), es.end());
	Weight total = 0;
	Edges mst;
	for (auto &e : es)
		if (!uf.same(e.s, e.d)) {
			uf.unite(e.s, e.d);
			mst.push_back(e);
			total += e.w;
		}
	return make_tuple(total, mst, uf.size == 1);
}

// 無向木を anti-arborescence に変換
// 連結無向グラフから変換することも可能
// (親, weight) の配列を返す
vector<pair<int, Weight>> antiArborescence(const Graph &g, int root = 0) {
	int n = g.size();
	vector<bool> vis(n);
	queue<int> q; q.emplace(root);
	vector<pair<int, Weight>> ret(n); ret[root] = make_pair(-1, 0);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u])continue;
		vis[u] = true;
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			ret[e.d] = make_pair(u, e.w);
			q.emplace(e.d);
		}
	}
	return ret;
}

// Leftist Heap (min)
template<class T>
struct LeftistHeap {
	struct Node {
		Node *l, *r;
		int d;
		T val;
		Node(const T &val) :l(NULL), r(NULL), d(0), val(val) {}
	};
	Node *root;
	int sz;
	LeftistHeap() :root(NULL), sz(0) {}

	Node *meld(Node *a, Node *b) {
		if (!a)return b;
		if (!b)return a;
		// a < b にして a.r (> a) と b (> a) を meld
		if (a->val > b->val)swap(a, b);
		a->r = meld(a->r, b);
		// 左の子の最も近い葉までの距離 > 右の子の最も近い葉までの距離 にする
		if (!a->l || a->l->d < a->r->d)swap(a->l, a->r);
		a->d = (a->r ? a->r->d : 0) + 1;
		return a;
	}
	void meld(LeftistHeap &h) {
		root = meld(root, h.root);
		sz += h.size();
		h.root = NULL;
		h.sz = 0;
	}
	void push(const T &x) {
		root = meld(new Node(x), root);
		sz++;
	}
	void pop() {
		root = meld(root->l, root->r);
		sz--;
	}
	T top() {
		assert(root);
		return root->val;
	}
	int size()const {
		return sz;
	}
};


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	Graph g(n);
	vector<int> a(m), b(m), w(m); rep(i, 0, m) {
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		addEdge(g, a[i], b[i], w[i]);
	}
	Weight cost; Edges mst; bool istree;
	tie(cost, mst, istree) = kruskal(g);
	if (!istree) {
		rep(i, 0, m) {
			cout << -1 << endl;
		}
		return 0;
	}
	set<Edge> st;
	Graph t(n);
	for (auto e : mst) {
		addEdge(t, e.s, e.d, e.w);
		st.emplace(e.s, e.d, e.w);
		st.emplace(e.d, e.s, e.w);
	}
	auto aa = antiArborescence(t);
	vector<int> in(n);
	for (auto r : aa) {
		if (r.first >= 0)
			in[r.first]++;
	}
	queue<int> q;
	rep(i, 0, n)
		if (in[i] == 0)
			q.push(i);
	vector<LeftistHeap<Edge>> lhs(n);
	rep(i, 0, m) {
		lhs[a[i]].push(Edge(a[i], b[i], w[i]));
		lhs[b[i]].push(Edge(b[i], a[i], w[i]));
	}
	vector<Weight> ans(n, -1);
	UnionFind uf(n);
	while (q.size()) {
		//dump(q);
		int u = q.front(); q.pop();
		if (aa[u].first == -1)continue;
		while (true) {
			if (lhs[u].size()) {
				auto e = lhs[u].top();
				if ((e.s == u && e.d == aa[u].first && e.w == aa[u].second) || uf.same(u, e.d)) {
					lhs[u].pop();
					continue;
				}
				ans[u] = cost - aa[u].second + e.w;
			}
			int v = aa[u].first;
			uf.unite(u, v);
			lhs[v].meld(lhs[u]);
			in[v]--;
			if (in[v] == 0)
				q.push(v);
			break;
		}
	}

	rep(i, 0, m) {
		if (!st.count(Edge(a[i], b[i], w[i]))) {
			cout << cost << endl;
		}
		else {
			if (aa[a[i]].first == b[i]) {
				cout << ans[a[i]] << endl;
			}
			else {
				cout << ans[b[i]] << endl;
			}
		}
	}

	return 0;
}
