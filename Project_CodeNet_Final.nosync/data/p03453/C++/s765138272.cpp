/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a)
{ int sz = a.size(); for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/*
 * Modint struct
 * library author : @snuke
 * */
const int mod = 1e9 + 7;
struct mint {
  long long x; // typedef long long ll;
  mint(long long x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) { if((x+=a.x)>=mod)x-=mod;return *this;}
  mint& operator-=(const mint a) { if((x+=mod-a.x)>=mod)x-=mod; return *this;}
  mint& operator*=(const mint a) { (x *=a.x)%=mod; return *this;}
  mint operator+(const mint a) const { mint res(*this);return res+=a;}
  mint operator-(const mint a) const { mint res(*this);return res-=a;}
  mint operator*(const mint a) const { mint res(*this);return res*=a;}
  mint pow(ll t) const {
    if (!t) return 1;mint a = pow(t>>1);a*=a;
    if (t&1) a *= *this;return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return (*this) *= a.inv();}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
namespace ModintUtil{
    mint mod_pow(long long p,long long q){mint res = p;return res.pow(q);}
    mint frac(long long p,long long q){ mint P = (mint)p; P /= (mint)q; return P; } // p/q
    mint frac(mint p,mint q){ p /= q; return p; }
    vector<mint> make_facl(long long N){ 
        vector<mint> ret(N+1);
        for(int i = 0;i <= N;i++){ if(i == 0)ret[i] = (mint)1; else ret[i] = ret[i-1] * (mint)i; }
        return ret;
    }
}
using namespace ModintUtil;
/////////////////////////////////////////////////////////////////////////////
/*
  modの値は1e9 + 7か998244353か任意modか、要チェック！！
*/


template<class T> struct Edge{

	int to;
	T cost;

	Edge(int t = 0,T c = 1):to(t),cost(c){}

};
template<class T> struct Graph{
	
	int N,M = 0;
	vector<vector<Edge<T> > > g;

	Graph(int N):N(N),g(N,vector<Edge<T> >(0)){}

	void add_edge(int a,int b,T c = 1){
		g[a].emplace_back(b,c);
		M++;
	}

};
template<class T> struct Dijkstra{
		
	Graph<T> G;
	vector<T> d;
	vector<int> p;

	Dijkstra(Graph<T>& G):G(G),d(G.N,LONG_MAX){}

	void solve(int s){
		d.assign(G.N,LONG_MAX);
		p.assign(G.N,-1);	

		d[s] = 0;
		using P = pair<T,int>;
		priority_queue<P,vector<P>,greater<P> > q;
		q.push({0,s});
		while(!q.empty()){
			int v = q.top().second;
			T d_v = q.top().first;
			q.pop();
			if(d_v != d[v])continue;

			for(auto edge : G.g[v]){
				if(d[v] + edge.cost < d[edge.to]){
					d[edge.to] = d[v] + edge.cost;
					p[edge.to] = v;
					q.push({d[edge.to],edge.to});
				}
			}
		}
	}

	vector<int> get_path(int s,int t){
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = p[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        return res;
    }

    void print_path(int s,int t){
    	auto path = get_path(s,t);
    	int len = path.size();
    	for(int i=0;i<len;i++)cout << path[i] << (i < len-1 ? ' ' : '\n');
    }

};

/**
 * how many shortest pathes are there from s to t ?
 * last checked : 2020.5.10 
 */
template<class T,class U> struct MinPathCounter{
	
	Graph<T> G;
	Dijkstra<T> D,D2;

	vector<pair<T,int> > dist;
	vector<pair<T,int> > dist2;
	vector<vector<U> > dp;

	int s,t;

	MinPathCounter(Graph<T>& G,int s,int t):
	s(s),t(t),G(G),D(G),D2(G),dist(G.N),dist2(G.N),dp(2,vector<U>(G.N,0))
	{
		D.solve(s);
		D2.solve(t);
		dp[0][s] = 1;
		dp[1][t] = 1;
	}

	void solve(){
		for(int i = 0;i < G.N;i++){
			dist[i] = make_pair(D.d[i],i);
		}

		sort(dist.begin(),dist.end());

		for(int i = 0;i < G.N;i++){
			for(auto e : G.g[dist[i].second]){
				if(D.d[e.to] == D.d[dist[i].second] + e.cost){
					dp[0][e.to] += dp[0][dist[i].second];
				}
			}
		}

		for(int i = 0;i < G.N;i++){
			dist2[i] = make_pair(D2.d[i],i);
		}

		sort(dist2.begin(),dist2.end());

		for(int i = 0;i < G.N;i++){
			for(auto e : G.g[dist2[i].second]){
				if(D2.d[e.to] == D2.d[dist2[i].second] + e.cost){
					dp[1][e.to] += dp[1][dist2[i].second];
				}
			}
		}
	}
};

	
int main(void){
	ioboost();

	int n,m;cin >> n >> m;
	Graph<long long> G(n);

	int s,t;cin >> s >> t;
	s--,t--;
	rep(i,m){
		int u,v;
		ll d;
		cin >> u >> v >> d;
		u--,v--;
		G.add_edge(u,v,d);
		G.add_edge(v,u,d);
	}

	MinPathCounter<ll,mint> MPC(G,s,t);
	MPC.solve();

	assert(MPC.dp[0][t].x == MPC.dp[1][s].x);

	ll len = MPC.D.d[t];

	mint all_ = MPC.dp[0][t]*MPC.dp[0][t];

	mint dis1 = 0;
	{
		for(int i = 0;i < n;i++){
			if(MPC.D.d[i] * 2 == len){
				dis1 += MPC.dp[0][i]*MPC.dp[1][i]*MPC.dp[0][i]*MPC.dp[1][i];;
			}
		}
	}
	mint dis2 = 0;
	{
		for(int i = 0;i < n;i++){
			for(auto e : MPC.G.g[i]){
				if(MPC.D.d[e.to] * 2 > len && MPC.D.d[i] * 2 < len && MPC.D.d[e.to] == MPC.D.d[i] + e.cost){
					if(MPC.D.d[i] + e.cost + MPC.D2.d[e.to] == len)dis2 += MPC.dp[0][i] * MPC.dp[1][e.to]*MPC.dp[0][i] * MPC.dp[1][e.to];
				}
			}
		}
	}
	cout << all_ - (dis1 + dis2) << '\n';
}

