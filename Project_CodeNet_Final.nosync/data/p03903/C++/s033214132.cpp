#include<bits/stdc++.h>
#define FOR(i, n, m) for(int i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	REP(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}

/*
template<typename T>
struct Treap {
	double drand() { // random number in [0, 1]
		static random_device rd;
		static mt19937 mt(rd());
		return (unsigned)mt() / (double)numeric_limits<unsigned>::max();
	}
	T v;
	double p;
	int cnt;
	Treap* lch;
	Treap* rch;
	Treap(T v) : v(v), p(drand()), cnt(1), lch(NULL), rch(NULL) { }
	Treap* update() {
		this->size = size(this->lch) + size(this->rch) + 1;
		return this;
	}
	static int size(Treap* t) {
		if(!t) return 0;
		else return t->cnt;
	}
	static Treap* merge(Treap* l, Treap* r) {
		if(!l || !r) {
			if(!l) return r;
			else return l;
		}
		if(l->p >= r->p) {
			l->rch = merge(l->rch, r);
			return l->update();
		} else {
			r->lch = merge(r->lch, l);
			return r->update();
		}
	}
	static pair<Treap*, Treap*> split(Treap* t, int k) {
		// split [0, k) and [k, n)
		if(k == 0) return {NULL, t};
		if(!(t->l)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else if(!(t->r)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else {

		}
	}
	Treap* insert() {
	}
	Treap* erase() {
	}
	T operator[](int k) {
	}
};
*/

class union_find {
public:
	union_find(int n)
	: par_(n, -1)
	{}
	void init(int n) {
		par_.assign(n, -1);
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if(x == y) {
			return false;
		} else {
			if(par_[x] < par_[y]) {
				par_[x] += par_[y];
				par_[y] = x;
			} else {
				par_[y] += par_[x];
				par_[x] = y;
			}
			return true;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return -par_[root(x)];
	}

private:
	std::vector<int> par_;
};

void dfs(int v, int par, int c, vector<vector<P>>& g, vector<P>& p, vector<int>& d, int dpt) {
	p[v] = {par, c};
	d[v] = dpt;
	for(auto adj: g[v]) {
		if(adj.first == par) continue;
		dfs(adj.first, v, adj.second, g, p, d, dpt + 1);
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<P>> g(n);
	vector<pair<ll, P>> e(m);
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
		e[i] = {c, {a, b}};
	}
	sort(ALL(e));
	union_find uf(n);
	vector<vector<P>> mst(n);
	ll sum = 0;
	for(auto edge: e) {
		if(uf.same(edge.second.first, edge.second.second)) continue;
		uf.unite(edge.second.first, edge.second.second);
		sum += edge.first;
		mst[edge.second.first].pb({edge.second.second, edge.first});
		mst[edge.second.second].pb({edge.second.first, edge.first});
	}
	vector<P> p(n, {-1, 0});
	vector<int> d(n, 0);
	dfs(0, -1, 0, mst, p, d, 0);
	int q;
	cin >> q;
	REP(i, q) {
		ll mx = 0;
		int s, t;
		cin >> s >> t;
		s--; t--;
		while(s != t) {
			if(d[s] >= d[t]) {
				mx = max(mx, p[s].second);
				s = p[s].first;
			} else {
				mx = max(mx, p[t].second);
				t = p[t].first;
			}
		}
		cout << sum - mx << endl;
	}
	return 0;
}
// ---------------------------------------
