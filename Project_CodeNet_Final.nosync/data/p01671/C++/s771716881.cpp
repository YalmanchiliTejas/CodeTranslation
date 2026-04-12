#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <unordered_map>
#include <iterator>
#include <functional>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct HLDecomp{
	struct NodeInfo{
		int idx, pos, cnt, par, heavy, depth;
	};
	int n;
	vector<NodeInfo> V;
	vector<vi> e;
	HLDecomp(const vector<vi> &g, int root = 0):n(g.size()), V(n){
		stack<int> st;
		st.push(root);
		V[root].depth = 0;
		V[root].par = -1;
		while(!st.empty()){
			int v = st.top(); st.pop();
			if(v<0){
				v = ~v;
				if(v != root) V[V[v].par].cnt += V[v].cnt;
				V[v].heavy = -1;
				int mc = 0;
				FOR(u, g[v])if(*u!=V[v].par && chmax(mc, V[*u].cnt)) V[v].heavy = *u;
			}else{
				V[v].cnt = 1;
				st.push(~v);
				FOR(u, g[v])if(*u!=V[v].par){
					V[*u].par = v;
					V[*u].depth = V[v].depth+1;
					st.push(*u);
				}
			}
		}
		st.push(root);
		while(!st.empty()){
			vi d;
			int v = st.top();st.pop();
			int p = V[v].par;
			for(;v>=0;v=V[v].heavy){
				FOR(u, g[v])if(*u!=V[v].par && *u!=V[v].heavy) st.push(*u);
				V[v].idx = e.size();
				V[v].pos = d.size();
				V[v].par = p;
				d.pb(v);
			}
			e.pb(d);
		}
//		cout << e << endl;
	}
	size_t size(){return e.size();}
	const vi &operator[](int i) const{return e[i];}
	pii getPos(int v){return pii(V[v].idx, V[v].pos);}
	struct Path{
		int idx, s, t;
		Path(int idx, int s, int t):idx(idx), s(s), t(t){}
	};
	vector<tuple<int, int, int>> path(int u, int v, int onlyEdge=0){
		vector<tuple<int, int, int>> res, rev;
		while(V[u].idx!=V[v].idx){
			int pu = V[u].par;
			int pv = V[v].par;
			if((pu==-1 ? -1 : V[pu].depth) > (pv == -1 ? -1 : V[pv].depth)){
				res.eb(V[u].idx, V[u].pos, 0);
				u = V[u].par;
			}else{
				rev.eb(V[v].idx  ,0 ,V[v].pos);
				v = V[v].par;
			}
		}
		int c = abs(V[u].pos - V[v].pos);
		if(!onlyEdge) res.eb(V[u].idx, V[u].pos, V[v].pos);
		else if(V[u].depth > V[v].depth) res.eb(V[u].idx, V[u].pos, V[v].pos + (V[v].pos < V[u].pos ? 1 : -1));
		else if(V[u].depth < V[v].depth) res.eb(V[u].idx, V[u].pos + (V[u].pos < V[v].pos ? 1 : -1), V[v].pos);
//		if(onlyEdge && V[u].depth != V[v].depth && c-1 != abs(V[u].pos - V[v].pos)) cerr << "!" << V[u].pos << ", " << V[v].pos << endl;
		res.insert(res.end(), RALL(rev));
		return res;
	}
	int getDepth(int v){
		return V[v].depth;
	}
};
struct handler{
	typedef int val_t;
	typedef int opr_t;
	handler(){}
	static val_t def_val(){ return INF; }
	static opr_t def_lazy(){ return INF; }
	static val_t resolve(const val_t &x, const opr_t &y, int l, int r){
		return min(x, y);
	}
	static opr_t push(const opr_t &x, const opr_t &y){
		return min(x, y);
	}
	static val_t merge(const val_t &x, const val_t &y){
		return min(x, y);
	}
};

template<typename Handler>
struct SegTreeLazy{
	typedef typename Handler::val_t val_t;
	typedef typename Handler::opr_t opr_t;
	vector<val_t> val;
	vector<opr_t> lazy;
	Handler hdl;
	int n;
	
	SegTreeLazy(int size):hdl(){
		n=1;
		while(n<size) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		lazy=vector<opr_t>(2*n, hdl.def_lazy());
	}
	
	SegTreeLazy(const vector<val_t> &in):hdl(){
		n=1;
		while(n<in.size()) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		lazy=vector<opr_t>(2*n, hdl.def_lazy());
		for(int i=n-1 + in.size()-1;i>=0;i--){
			if(n-1 <= i) val[i] = in[i - (n-1)];
			else val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	val_t update(int a,int b,opr_t x, int k,int l,int r){
		if(r<=a||b<=l) return hdl.resolve(val[k], lazy[k], l, r);
		if(a<=l&&r<=b){
			lazy[k] = hdl.push(lazy[k], x);
			return hdl.resolve(val[k], lazy[k], l, r);
		}
		lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
		lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
		lazy[k] = hdl.def_lazy();
		return val[k] = hdl.merge(update(a, b, x, k*2+1, l, (l+r)/2),
								  update(a, b, x, k*2+2, (l+r)/2, r));
	}
	val_t query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return hdl.def_val();
		if(a<=l&&r<=b) return hdl.resolve(val[k], lazy[k], l, r);
		val[k] = hdl.resolve(val[k], lazy[k], l, r);
		lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
		lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
		lazy[k] = hdl.def_lazy();
		return hdl.merge(query(a, b, k*2+1, l, (l+r)/2),
						 query(a, b, k*2+2, (l+r)/2, r));
	}
	val_t update(int a, int b, opr_t x){return update(a, b, x, 0, 0, n);}
	val_t query(int a, int b){return query(a, b, 0, 0, n);}
	val_t operator[](size_t i){return query(i, i+1);}
	friend ostream& operator<<(ostream &os, SegTreeLazy<Handler> &t){
		REP(i, t.n) os << (i ? ", " : "[") << t.query(i, i+1);
		return os << "]";
	}
};

template<class H, class S>
struct SegTreeOnHLDecomp{
	typedef typename H::val_t val_t;
	typedef typename H::opr_t opr_t;
	vector<S> seg;
	HLDecomp hld;
	SegTreeOnHLDecomp(const vector<vi> &g, const vector<val_t> &val, int root=0)
		:hld(g, root){
		REP(i, hld.size()){
			vector<val_t> d;
			const vi& nodes = hld[i];
			FOR(v, nodes) d.pb(val[*v]);
			seg.eb(d);
			reverse(ALL(d));
			seg.eb(d);
		}
	}
	void update(int u, int v, const opr_t &x, int onlyEdge=1){
		auto paths = hld.path(u, v, onlyEdge);
		FOR(p, paths){
			int i, s, t;tie(i, s, t) = *p;
			if(s > t) swap(s, t);
			seg[2*i].update(s, t+1, x);
			seg[2*i+1].update(hld[i].size() - t - 1, hld[i].size() - s, x);
		}
	}
	val_t query(int u, int v){
		auto res = H::def_val();
		auto paths = hld.path(u, v);
		FOR(p, paths){
			int i, s, t; tie(i, s, t) = *p;
			if(s <= t) res = H::merge(res, seg[2*i].query(s, t+1));
			else res = H::merge(res, seg[2*i+1].query(hld[i].size()-1-s, hld[i].size()-t));
		}
		return res;
	}
	val_t query(int v){
		auto t = hld.getPos(v);
		return seg[2*t.first].query(t.second, t.second+1);
	}
	friend ostream& operator<<(ostream &os, SegTreeOnHLDecomp<H, S> &shld){
		REP(i, shld.hld.n) os << (i ? ", " : "[") << shld.query(i, i);
		return os << "]";
	}
};

int n, m;

int main(int argc, char *argv[]){
	scanf("%d%d", &n, &m);
	vector<pair<pii, pii>> e;
	REP(i, m){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w); u--, v--;
		e.eb(pii(w, i), pii(u, v));
	}
	sort(ALL(e));
	vector<vi> g(n);
	UnionFind uf(n);
	vi used(m);
	ll base = 0;
	REP(i, m){
		const int u = e[i].second.first;
		const int v = e[i].second.second;
		const int w = e[i].first.first;
		if(used[i] = uf.unionSet(u, v)){
			g[u].pb(v);
			g[v].pb(u);
			base += w;
		}
	}
	vector<ll> ans(m, 1ll<<55);
	SegTreeOnHLDecomp<handler, SegTreeLazy<handler>> treeseg(g, vi(n, INF));
	REP(i, m)if(!used[i]){
		const int u = e[i].second.first;
		const int v = e[i].second.second;
		const int w = e[i].first.first;
		ans[e[i].first.second] = base;
		treeseg.update(u, v, w, 1);
	}
	REP(i, m)if(used[i]){
		const int u = e[i].second.first;
		const int v = e[i].second.second;
		const int w = e[i].first.first;
		int t = (treeseg.hld.getDepth(u) < treeseg.hld.getDepth(v)) ? v : u;
		t = treeseg.query(t);
		ans[e[i].first.second] = (t == INF) ? -1 : base - w + t;
	}
	if(accumulate(ALL(used), 1) < n) fill(ALL(ans), -1ll);
	REP(i, m) printf("%lld\n", ans[i]);
	return 0;
}