#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#ifdef ilyes
	#define dump(x ...) cerr  <<  "|dumping| "  <<  # x  <<  "  =  ", _dump(x) 
#else
	#define dump(...) 1998
#endif
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define pii pair<int,int>
const int INF = 1e9; const LL INFLL = 1e18L;
const int N = 1e5;

namespace Mm{
	const int _MOD = 1e9 + 7;
	inline int _mul(const LL &x, const LL &y) { return (x*y)%_MOD; }
	inline int _add(const LL &x, const LL &y) { LL z=x+y; return (z>=_MOD+_MOD)?z%_MOD:((z>=_MOD)?z-_MOD:((z<0)?z+_MOD:z)); }
} using namespace Mm;

int n, m;
int src, sink;
vector<pii> adj[N+3];
vector<tuple<int,int,int>> edg;
LL distSrc[N+3], distSink[N+3];
LL dpSrc[N+3], dpSink[N+3];
LL optimalDist;
int ans;

void dijkst(int _src, LL _dist[]){
	for(int i=1; i<=n; ++i) _dist[i] = INFLL;
	_dist[_src] = 0;
	set<pii> _sss;
	for(int i=1; i<=n; ++i) _sss.insert({_dist[i], i});
	while(!_sss.empty()){
		LL d; int u;
		tie(d, u) = *_sss.begin();
		_sss.erase(_sss.begin());
		for(auto el: adj[u]){
			int v, w; tie(v, w) = el;
			if(_dist[v] > _dist[u] + w){
				_sss.erase({_dist[v], v});
				_dist[v] = _dist[u] + w;
				_sss.insert({_dist[v], v});
			}
		}
	}
}

void computeDP(int _src, LL _dp[], LL _dist[]){
	vector<int> vect;
	for(int u=1; u<=n; ++u){
		vect.emplace_back(u);
	}
	sort(all(vect), [&](int &_ff, int &_ss){ return _dist[_ff] < _dist[_ss]; });

	assert(vect.front() == _src);

	_dp[vect.front()] = 1;

	for(int i=1; i<=size(vect)-1; ++i){
		int u = vect[i];

		_dp[u] = 0;
		if(distSrc[u] + distSink[u] == optimalDist){
			for(auto el: adj[u]){
				int v, w; tie(v, w) = el;
				if(_dist[v] + w == _dist[u]){
					_dp[u] = _add(_dp[u], _dp[v]);
				}
			}
		}
	}
}

int main(){ FAST
	cin >> n >> m;
	cin >> src >> sink;
	for(int e=1; e<=m; ++e){
		int u,v,w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edg.emplace_back(u, v, w);
	}

	dijkst(src, distSrc);
	dijkst(sink, distSink);

	optimalDist = distSrc[sink];
	assert(distSrc[sink] == distSink[src]);

	computeDP(src, dpSrc, distSrc);
	computeDP(sink, dpSink, distSink);

	ans = _mul(dpSrc[sink], dpSrc[sink]);
	assert(dpSrc[sink] == dpSink[src]);
	
	for(int u=1; u<=n; ++u){
		if(distSrc[u] + distSink[u] == optimalDist && distSrc[u] == distSink[u]){
			int extra = _mul(dpSrc[u], dpSink[u]);
			extra = _mul(extra, extra);
			ans = _add(ans, _MOD - extra);
		}
	}

	for(auto el: edg){
		int u, v, w; tie(u, v, w) = el;
		int x = u, y = v;
		if(!(distSrc[x] < distSrc[y])) swap(x,y);

		if(distSrc[x] + w + distSink[y] == optimalDist && abs(distSrc[x] - distSink[y]) < w){
			int extra = _mul(dpSrc[x], dpSink[y]);
			extra = _mul(extra, extra);
			ans = _add(ans, _MOD - extra);
		}
	}

	cout << ans << ln;
}