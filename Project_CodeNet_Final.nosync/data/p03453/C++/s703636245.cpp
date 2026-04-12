#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,ll> PPI;
typedef pair<ll,P> PIP;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vp;
#define PQ(T) priority_queue<T,vector<T>,greater<T>>
#define PQ2(T) priority_queue<T>
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<59;
const ll mod = 1e9+7;
#define REP(i,a,b) for(ll (i)=a;(i)<(ll)(b);++(i))
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(x,y) ((x)=min((x),(y)))
#define chmax(x,y) ((x)=max((x),(y)))
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
#define DEBUG(x) cerr<<"line ("<<__LINE__<<")  "<<#x<<": "<<x<<endl;
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define N 100010

ll d[2][N], wg[2][N];
ll n, m, s, t;
vp g[N];

void dijk(int u, ll d[N], ll wg[N]){
	fill(d, d+N, INF);
	fill(wg, wg+N, 0);
	d[u] = 0; wg[u] = 1;
	PQ(P) q;
	q.push(P(0, u));
	while(!q.empty()){
		P p = q.top(); q.pop();
		ll v = p.snd, ttt = p.fst;
		if(d[v]<ttt) continue;
		for(auto &&x: g[v]){
			ll w = x.fst, tt = ttt+x.snd;
			if(d[w]>tt){
				d[w] = tt;
				wg[w] = wg[v];
				q.push(P(d[w], w));
			} else if(d[w]==tt) (wg[w]+=wg[v])%=mod;
		}
	}
}

int main(){
	cin>>n>>m>>s>>t; s--; t--;
	rep(i, m){
		ll u, v, l;
		cin>>u>>v>>l; u--; v--;
		g[u].pb(P(v, l));
		g[v].pb(P(u, l));
	}
	dijk(s, d[0], wg[0]);
	dijk(t, d[1], wg[1]);
	ll len = d[0][t];
	ll res = wg[0][t]*wg[0][t]%mod;
	cerr<<res<<endl;
	rep(i, n){
		for(auto &&x: g[i]){
			ll j = x.fst, l = x.snd;
			if(d[0][i]+d[1][j]+l!=len) continue;
			if(d[0][i]>=(len+1)/2||d[1][j]>=(len+1)/2) continue;
			(res-=wg[0][i]*wg[1][j]%mod*wg[1][j]%mod*wg[0][i]%mod)%=mod;
			//cerr<<"edge "<<i<<" "<<j<<" "<<wg[0][i]<<" "<<wg[1][j]<<endl;
		}
		if(d[0][i]+d[1][i]!=len||d[0][i]!=d[1][i]) continue;
		(res-=wg[0][i]*wg[1][i]%mod*wg[1][i]%mod*wg[0][i]%mod)%+mod;
		//cerr<<"vertex "<<i<<" "<<wg[0][i]<<" "<<wg[1][i]<<endl;
	}
	res+=mod;
	res%=mod;
	cout<<res<<endl;
	//rep(i, n) cerr<<wg[0][i]<<endl;
	//rep(i, n) cerr<<d[0][i]<<endl;
	return 0;
}
