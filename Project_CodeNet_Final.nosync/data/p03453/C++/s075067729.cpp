#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

constexpr int MOD = 1e9+7;
struct mint
{
	int v;
	mint():v(0){}
	mint(int v):v((v+MOD)%MOD){}
	mint operator-()const{ return mint(0) - *this; }
	mint& operator+=(const mint& a){ if((v+=a.v)>=MOD) v-=MOD; return *this; }
	mint& operator-=(const mint& a){ if((v+=MOD-a.v)>=MOD) v-=MOD; return *this; }
	mint& operator*=(const mint& a){ (v*=a.v)%=MOD; return *this; }
	mint& operator/=(const mint& a){ (*this) *= a.inv(); return *this; }
	mint operator+(const mint& a)const{ return mint(*this) += a; }
	mint operator-(const mint& a)const{ return mint(*this) -= a; }
	mint operator*(const mint& a)const{ return mint(*this) *= a; }
	mint operator/(const mint& a)const{ return mint(*this) /= a; }
	bool operator<(const mint& a)const{ return v < a.v; }
	bool operator==(const mint& a)const{ return v == a.v; }
	mint pow(int k)const{ mint r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }
	mint inv()const{ return pow(MOD-2); }
	static mint comb(int n, int k) {
		if(n-k<k) k=n-k;
		mint num(1), dom(1);
		for(int i=0;i<k;i++) { num*=n-i; dom*=i+1; }
		return num/dom;
	}
};
std::istream& operator>>(std::istream&i,mint&a){ int t; i>>t; a=mint(t); return i; }
std::ostream& operator<<(std::ostream&o,const mint&a){ o<<a.v; return o; }


template <typename T>
std::vector<T> dijkstra(std::vector<std::vector<std::pair<int,T> > > & G, int s) {
	const T INF = std::numeric_limits<T>::max();
	int n = G.size();
	using n_node = std::pair<T,int>;
	std::vector<T> dist(n,INF);
	std::priority_queue<n_node,std::vector<n_node>,std::greater<n_node> > next;
	next.emplace(0,s);
	while(!next.empty()) {
		n_node t = next.top(); next.pop();
		int i = t.second; T cost = t.first;
		if(dist[i]!=INF) continue;
		dist[i] = cost;
		for(auto e:G[i]) {
			next.emplace(cost+e.second,e.first);
		}
	}
	return dist;
}

struct E
{
	int a,b,c;
	E(int a, int b, int c) : a(a),b(b),c(c) {}
};

signed main() {
	int n,m;
	std::cin >> n >> m;
	int s,t;
	std::cin >> s >> t;
	s--;t--;
	std::vector<std::vector<std::pair<int,int> > > g(n);
	std::vector<E> edges;
	rep(i,m) {
		int a,b,c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].emplace_back(b,c);
		g[b].emplace_back(a,c);
		edges.emplace_back(a,b,c);
	}
	auto st=dijkstra<int>(g,s);
	auto ts=dijkstra<int>(g,t);
	int dist = st[t];
	std::vector<mint> dpst(n,0); dpst[s]=1;
	std::vector<mint> dpts(n,0); dpts[t]=1;
	{
		std::vector<std::pair<int,int> > use;
		rep(i,m) {
			int x=edges[i].a,y=edges[i].b;
			if(st[x]>st[y]) std::swap(x,y);
			if(st[x]+ts[y]+edges[i].c==dist) {
				use.emplace_back(st[x],i);
			}
		}
		std::sort(all(use));
		for(auto e:use) {
			int x=edges[e.second].a,y=edges[e.second].b;
			if(st[x]>st[y]) std::swap(x,y);
			dpst[y]+=dpst[x];
		}
	}
	{
		std::vector<std::pair<int,int> > use;
		rep(i,m) {
			int x=edges[i].a,y=edges[i].b;
			if(ts[x]>ts[y]) std::swap(x,y);
			if(ts[x]+st[y]+edges[i].c==dist) {
				use.emplace_back(ts[x],i);
			}
		}
		std::sort(all(use));
		for(auto e:use) {
			int x=edges[e.second].a,y=edges[e.second].b;
			if(ts[x]>ts[y]) std::swap(x,y);
			dpts[y]+=dpts[x];
		}
	}
	mint routes=dpst[t];
	routes*=routes;
	debug(routes);
	{
		rep(i,m) {
			int x=edges[i].a,y=edges[i].b;
			if(st[x]>st[y]) std::swap(x,y);
			if(st[x]+ts[y]+edges[i].c==dist) {
				if(st[y]>ts[y] && st[x]-edges[i].c<ts[y]) {
					routes-=(dpts[y]*dpst[x]).pow(2);
				}
			}
		}
	}
	rep(i,n) {
		if(st[i]*2==st[t]) {
			routes-=(dpst[i]*dpts[i]).pow(2);
		}
	}
	print(routes);

	return 0;
}
