#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

class HLDecomposition{
private:
	vector<vector<int32>> G;
	vector<int32> vid, inv, dep, hvy, par, typ, sub, head;
	int32 n, pos;
public:
	HLDecomposition(){}
	HLDecomposition(int32 n):
		n(n), pos(0), G(n), vid(n), inv(n), dep(n, -1),
		hvy(n, -1), par(n), typ(n), sub(n, 1), head(n){}

	void add_edge(int32 u, int32 v){
		G[u].push_back(v);
		G[v].push_back(u);
	}

	void build(){
		int32 type = 0;
		for(int32 i = 0;i < n;i++){
			if(dep[i] == -1){
				dfs(i);
				bfs(i, type++);
			}
		}
	}

	void dfs(int32 v){
		using T = pair<int32, int32>;
		dep[v] = 0;
		par[v] = -1;
		stack<T> st;
		st.emplace(v, 0);
		while(st.size()){
			v = st.top().first;
			int32 &i = st.top().second;
			if(i<G[v].size()){
				int32 u = G[v][i++];
				if(u == par[v]) continue;
				par[u] = v;
				dep[u] = dep[v]+1;
				st.emplace(u, 0);
			}else{
				st.pop();
				for(int32 u : G[v]){
					if(u == par[v]) continue;
					sub[v] += sub[u];
					if(hvy[v] == -1 || sub[u] > sub[hvy[v]]) hvy[v] = u;
				}
			}
		}
	}

	void bfs(int32 v, int32 t){
		queue<int32> q({v});
		while(q.size()){
			v = q.front(); q.pop();
			for(int32 i = v;i != -1;i=hvy[i]){
				typ[i] = t;
				vid[i] = pos++;
				inv[vid[i]] = i;
				head[i] = v;
				for(int32 u : G[i])
					if(u != par[i] && u != hvy[i]) q.push(u);
			}
		}
	}

	void for_each(int32 u, int32 v, const function<void(int32, int32)>& f){
		while(1){
			if(vid[u] > vid[v]) swap(u, v);
			f(max(vid[head[v]], vid[u]), vid[v]);
			if(head[u] != head[v]) v=par[head[v]];
			else break;
		}
	}

	void for_each_edge(int32 u, int32 v, const function<void(int32, int32)>& f){
		while(1){
			if(vid[u] > vid[v]) swap(u, v);
			if(head[u] != head[v]){
				f(vid[head[v]], vid[v]);
				v = par[head[v]];
			}else{
				if(u!=v) f(vid[u]+1, vid[v]);
				break;
			}
		}
	}

	int32 lca(int32 u, int32 v){
		while(1){
			if(vid[u] > vid[v]) swap(u, v);
			if(head[u] != head[v]) v = par[head[v]];
			else return u;
		}
	}

	int32 distance(int32 u, int32 v){
		return dep[u]+dep[v]-2*dep[lca(u, v)];
	}

	int32 getvid(int32 v){
		return vid[v];
	}
};

template<typename T, typename E>
class LazySegTree{
private:
	using F = function<T(T, T)>;
	using G = function<T(T, E)>;
	using H = function<E(E, E)>;
	using P = function<E(E, int64)>;
	int32 n;
	vector<T> node;
	vector<E> lazy;
	F f;
	G g;
	H h;
	P p;
	T ti;
	E ei;
public:
	LazySegTree(){}
	LazySegTree(int32 _n, F f, G g, H h, T ti, E ei, P p = [](E a, int32 b){return a;}):f(f), g(g), h(h), p(p), ti(ti), ei(ei){
		init(_n);
	}

	LazySegTree(vector<T> v, F f, G g, H h, T ti, E ei, P p = [](E a, int32 b){return a;}):f(f), g(g), h(h), p(p), ti(ti), ei(ei){
		init(v.size());
		for(int32 i = 0;i < v.size();i++) node[i+n-1] = v[i];
		for(int32 i = n-2;i >= 0;i--) node[i] = merge(node[i*2+1], node[i*2+2]);
	}

	void init(int32 _n){
		n = 1;
		while(n < _n) n*=2;
		node.resize(2*n-1, ti);
		lazy.resize(2*n-1, ei);
	}

	inline T merge(T lhs, T rhs){
		if(lhs == ti) return rhs;
		else if(rhs == ti) return lhs;
		return f(lhs, rhs);
	}

	inline void eval(int32 k, int32 l, int32 r){
		if(lazy[k] == ei) return;
		node[k] = g(node[k], p(lazy[k], r-l));
		if(r-l > 1){
			lazy[k*2+1] = h(lazy[k*2+1], lazy[k]);
			lazy[k*2+2] = h(lazy[k*2+2], lazy[k]);
		}
		lazy[k] = ei;
	}

	T update(int32 a, int32 b, E x, int32 k=0, int32 l=0, int32 r=-1){
		if(r<0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return node[k];
		if(a <= l && r <= b){
			lazy[k] = h(lazy[k], x);
			return g(node[k], p(lazy[k], r-l));
	}
		return node[k] = merge(update(a, b, x, k*2+1, l, (l+r)/2), update(a, b, x, k*2+2, (l+r)/2, r));
	}

	T query(int32 a, int32 b, int32 k=0, int32 l=0, int32 r=-1){
		if(r<0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return ti;
		if(a <= l && r <= b) return node[k];
		return merge(query(a, b, k*2+1, l, (l+r)/2), query(a, b, k*2+2, (l+r)/2, r));
	}
};
class UnionFind{
private:
	vector<int32> par;
	int32 n;

public:
	UnionFind(){}
	UnionFind(int32 n):n(n){
		par.resize(n, -1);
	}

	int32 find(int32 x){
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}

	int32 size(int32 x){
		return -par[find(x)];
	}

	void unite(int32 x, int32 y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(size(x) < size(y)) swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}

	bool same(int32 x, int32 y){
		return find(x) == find(y);
	}
};

int32 n, m;
using T = tuple<int64, int64, int64, int64>;
vector<T> e, e2;
vector<bool> used;
vector<int64> res;

int main(void){
	cin >> n >> m;
	UnionFind uf(n);
	used.resize(m, 0);
	REP(i, m){
		int64 a, b, w;
		cin >> a >> b >> w; a--; b--;
		e.push_back(T(w, a, b, i));
	}
	e2 = e;
	HLDecomposition hld(n);
	LazySegTree<int64, int64> lsg(n,
		[](int64 a, int64 b){return min(a, b);},
		[](int64 a, int64 b){return min(a, b);},
		[](int64 a, int64 b){return min(a, b);},
		INF_LL, INF_LL);
	sort(all(e));
	int64 sum = 0;
	REP(i, e.size()){
		int64 w, u, v, id;
		tie(w, u, v, id) = e[i];
		if(uf.same(u, v)) continue;
		uf.unite(u, v);
		hld.add_edge(u, v);
		used[id] = 1;
		sum += w;
	}
	hld.build();
	res.resize(m, sum);
	REP(i, e.size()){
		int64 w, u, v, id;
		tie(w, u, v, id) = e[i];
		if(!used[id]){
			hld.for_each_edge(u, v, [&](int32 l, int32 r){lsg.update(l, r+1, w);});
		}
	}
	REP(i, e.size()){
		int64 w, u, v, id;
		tie(w, u, v, id) = e[i];
		if(!used[id]) continue;
		res[id] -= w;
		res[id] += lsg.query(max(hld.getvid(u), hld.getvid(v)), max(hld.getvid(u), hld.getvid(v))+1);
		if(res[id] >= INF_LL) res[id] = -1;
	}
	REP(i, m) cout << res[i] << endl;
}
