#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,ll> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

typedef pair<ll,int> edge;

struct S {
	int a,b;ll c;
	S(int x,int y,ll z):a(x),b(y),c(z) {}
};

int n,m,s,t;
vector<P> g[100000];
vector<S> LIST;
ll d[2][100000],dp[2][100000];
const int MOD=1e9+7;

void dijkstra(int type,int start) {
	priority_queue<edge,vector<edge>,greater<edge> > pq;
	REP(i,n) d[type][i]=LINF;
	dp[type][start]=1;
	d[type][start]=0;
	pq.push(P(0,start));
	while(!pq.empty()) {
		edge p=pq.top();pq.pop();
		int v=p.se;
		if(d[type][v]<p.fi) continue;
		for(auto e:g[v]) {
			if(d[type][e.fi]<d[type][v]+e.se) continue;
			if(d[type][e.fi]==d[type][v]+e.se) (dp[type][e.fi]+=dp[type][v])%=MOD;
			else {
				dp[type][e.fi]=dp[type][v];
				d[type][e.fi]=d[type][v]+e.se;
				pq.push(edge(d[type][e.fi],e.fi));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>m>>s>>t;
	s--,t--;
	REP(i,m) {
		int v,u;ll D;cin>>v>>u>>D;
		v--,u--;
		g[u].pb(P(v,D));g[v].pb(P(u,D));
		LIST.pb(S(u,v,D));
	}

	dijkstra(0,s);
	dijkstra(1,t);

	ll dif=0;

	REP(i,m) {
		int u=LIST[i].a,v=LIST[i].b;ll D=LIST[i].c;
		if(d[0][u]>d[0][v]) swap(u,v);
		if(d[0][u]+D!=d[0][v]) continue;
		if(d[0][u]*2<d[0][t]&&d[0][v]*2>d[0][t]&&d[0][u]+d[1][v]+D==d[0][t]) {
			ll num=(dp[0][u]*dp[1][v])%MOD;
			(dif+=num*num)%=MOD;
		}
	}
	REP(i,n) {
		if(d[0][i]+d[1][i]==d[0][t]&&d[0][i]==d[1][i]) {
			ll num=(dp[0][i]*dp[1][i])%MOD;
			(dif+=num*num)%=MOD;
		}
	}
	cout<<(dp[0][t]*dp[1][s]-dif+MOD)%MOD<<endl;

	//REP(i,n) cout<<dp[0][i]<<' '<<dp[1][i]<<endl;

	return 0;
}
