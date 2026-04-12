#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, string s = "\n") { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ") 
{ if (!v.size()) puts(""); rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

struct UnionFind {
	vector<int> p, r;

	UnionFind() {}
	UnionFind(int size) { init(size); }

	void init(int size) {
		p.resize(size);
		r.resize(size);
		for (int i = 0; i < size; ++i) {
			p[i] = i; r[i] = 1;
		}
	}

	int root(int x) {
		if (p[x] == x) return x;
		else return p[x] = root(p[x]);
	}

	void unite(int x, int y) {
		x = root(x); y = root(y);

		if (x == y) return;

		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		p[y] = x;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}
};

struct edge {
	int from, to, cost;
	edge () {}
	edge (int from, int to, int cost) :from(from), to(to), cost(cost) {}
	bool operator<(const edge& e) const{
		return cost<e.cost;
	}
};

int kruskal(int V, vector<edge> &edges) {
	int res = 0;
	sort(edges.begin(), edges.end());
	UnionFind uf(V + 1);
	for (int i = 0; i < (int)edges.size(); ++i) {
		edge e = edges[i];
		if (!uf.same(e.from, e.to)) {
			res += e.cost;
			uf.unite(e.from, e.to);
		}
	}

	return res;
}

signed main() {
	int n = in();
	vector<pii> x, y;
	rep(i, n) {
		int a = in(), b = in();
		x.pb(mp(a, i));
		y.pb(mp(b, i));
	}

	sort(all(x));
	sort(all(y));

	vector<edge> e;
	for (int i = 1; i < n; ++i) {
		e.pb(edge(x[i].sc, x[i - 1].sc, x[i].fs - x[i - 1].fs));
		e.pb(edge(y[i].sc, y[i - 1].sc, y[i].fs - y[i - 1].fs));
	}

	cout << kruskal(n, e) << endl;
}
