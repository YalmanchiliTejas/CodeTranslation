// template {{{
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define GET_MACRO(a, b, c, d, NAME, ...) NAME
#define REP2(i, n) REP3(i, 0, n)
#define REP3(i, a, b) REP4(i, a, b, 1)
#define REP4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += s)
#define RREP2(i, n) RREP3(i, 0, n)
#define RREP3(i, a, b) for (ll i = (b) - 1; i >= (ll)(a); i--)

#define rep(...) GET_MACRO(__VA_ARGS__, REP4, REP3, REP2)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__,, RREP3, RREP2)(__VA_ARGS__)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define pf pop_front
#define all(c) begin(c), end(c)
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define popcnt __builtin_popcountll

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;

template<typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
inline T sq(T x){
	return x * x;
}

template<typename T, typename U>
inline bool chmax(T &x, U y){
	if (x >= y) return false;
	x = y;
	return true;
}

template<typename T, typename U>
inline bool chmin(T &x, U y){
	if (x <= y) return false;
	x = y;
	return true;
}

template<typename T>
inline T& sort(T &c){
	sort(all(c));
	return c;
}

template<typename T>
inline T& reverse(T &c){
	reverse(all(c));
	return c;
}

template<typename T>
inline T& unique(T &c){
	sort(all(c));
	c.erase(unique(all(c)), end(c));
	return c;
}

template<typename T>
inline T sorted(const T &c){
	T d = c;
	return sort(d);
}

template<typename T>
inline T reversed(const T &c){
	T d = c;
	return reverse(d);
}

template<typename T>
inline T uniqued(const T &c){
	T d = c;
	return unique(d);
}
// }}}
// union find {{{
struct UnionFind {
	UnionFind(size_t n = 0): cnt(n), par(n, -1){}
	
	int root(int x){
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}
	
	bool same(int x, int y){
		return root(x) == root(y);
	}
	
	int size(){
		return cnt;
	}

	int size(int x){
		return -par[root(x)];
	}

	bool unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		cnt--;
		return true;
	}

private:
	int cnt;
	vector<int> par;
};
// }}}

int n, m;
vector<tuple<int, int, int, int>> es;
vector<tuple<int, int, int, int>> tr[100000];
minheap<tuple<int, int, int, int>> re[100000];
tuple<int, int, int, int> rtr[100000];
bool used[200000];
ll res[200000];

void dfs(int v, int p, vector<int> &ord)
{
	for (auto e : tr[v]){
		int w, a, b, id;
		tie(w, a, b, id) = e;
		if (b != p){
			rtr[b] = mt(w, b, v, id);
			dfs(b, v, ord);
		}
	}
	if (p != -1) ord.eb(v);
}

int main()
{
	scanf("%d %d", &n, &m);
	rep(i, m){
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		es.eb(w, --a, --b, i);
	}
	
	UnionFind uf(n);
	sort(es);
	ll s = 0;
	for (auto e : es){
		int w, a, b, id;
		tie(w, a, b, id) = e;
		if (uf.unite(a, b)){
			s += w;
			used[id] = true;
		}
	}
	
	if (uf.size() > 1){
		rep(i, m) puts("-1");
		return 0;
	}

	memset(res, -1, sizeof(res));
	for (auto e : es){
		int w, a, b, id;
		tie(w, a, b, id) = e;
		if (used[id]){
			tr[a].eb(w, a, b, id);
			tr[b].eb(w, b, a, id);
		}
		else {
			re[a].emplace(w, a, b, id);
			re[b].emplace(w, b, a, id);
			res[id] = s;
		}
	}
	
	vector<int> ord;
	dfs(0, -1, ord);
	uf = UnionFind(n);
	for (int v : ord){
		int tw, ta, tb, tid;
		tie(tw, ta, tb, tid) = rtr[v];
		while (re[v].size()){
			int w, a, b, id;
			tie(w, a, b, id) = re[v].top();
			if (uf.same(v, b)) re[v].pop();
			else {
				res[tid] = s - tw + w;
				break;
			}
		}
		auto &h1 = re[tb];
		auto &h2 = re[v];
		if (h1.size() < h2.size()) swap(h1, h2);
		while (h2.size()){
			h1.push(h2.top());
			h2.pop();
		}
		uf.unite(v, tb);
	}

	rep(i, m) printf("%lld\n", res[i]);
}