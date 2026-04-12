#include <bits/stdc++.h>
#define fore(x,a,b) for(int x=a, qwert=b; x<qwert; x++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) ((int)(a).size())
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<ll,int> O;
const int N=1e5+5;
const ll INF=1e18, MOD=1e9+7LL;
ll dp[2][N];
vector<ll> dist[2];
vector<pair<int,ll> > g[N];
int n, m, st, fn;

void dijkstra(int s, vector<ll>&dist){
	dist.assign(n,INF);dist[s]=0;
	priority_queue<O,vector<O>,greater<O> > pq;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().snd;
		ll d=pq.top().fst; pq.pop();
		if(dist[u]<d)continue;
		for(auto e : g[u]){
			int v=e.fst;
			if(dist[v]>d+e.snd){
				dist[v]=d+e.snd;
				pq.push({dist[v],v});
			}
		}
	}
}

ll solve(int b, int u){
	ll &r=dp[b][u];
	if(r!=-1)return r;
	if((b==0 && u==fn) || (b==1 && u==st))return r=1;
	r=0;
	for(auto e : g[u]){
		int v=e.fst;
		if(dist[b][u]+e.snd+dist[!b][v]==dist[0][fn])
			r=(r+solve(b,v))%MOD;
	}
	return r;
}
struct Edge { int u, v; ll c; };
ll mod(ll v){return ((v%MOD)+MOD)%MOD;}
int main(){
	memset(dp,-1,sizeof(dp));
	cin >> n >> m >> st >> fn; st--; fn--;
	vector<Edge> edges;
	fore(x,0,m){
		int u, v, c; cin >> u >> v >> c; u--; v--;
		g[u].pb({v,c});g[v].pb({u,c});edges.pb(Edge{u,v,c});
	}
	dijkstra(st,dist[0]);
	dijkstra(fn,dist[1]);

	ll ans = (solve(0,st)*solve(1,fn))%MOD;
	fore(x,0,n)if(dist[0][x]==dist[1][x]){
		ll tmp=(solve(0,x)*solve(1,x))%MOD;
		tmp=(tmp*tmp)%MOD;
		ans = mod(ans-tmp);
	}
	fore(x,0,m){
		ll a1=dist[0][edges[x].u],a2=dist[0][edges[x].v];
		ll b1=dist[1][edges[x].u],b2=dist[1][edges[x].v];
		if(min(a1,a2)*2LL<dist[0][fn] && min(b1,b2)*2LL<dist[0][fn] &&min(b1,b2)+min(a1,a2)+edges[x].c==dist[0][fn]){
			if(min(a1,a2)==a1){
				ll tmp = (solve(0,edges[x].v)*solve(1,edges[x].u))%MOD;
				tmp=(tmp*tmp)%MOD;
				ans = mod(ans - tmp);
			}else{
				ll tmp = (solve(0,edges[x].u)*solve(1,edges[x].v))%MOD;
				tmp=(tmp*tmp)%MOD;
				ans = mod(ans - tmp);
			}
		}
	}
	cout << ans << "\n";	
}