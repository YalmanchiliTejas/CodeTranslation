#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,s,t;
vector<P>edge[1000005];
ll dist[1000005];
ll dist2[1000005];
ll way[1000005];
ll way2[1000005];

int main(){
	cin>>n>>m;
	cin>>s>>t;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
	fill(dist,dist+n+5,1e18);
	dist[s] = 0; way[s] = 1;
	que.push(mp(0,s));
	while(!que.empty()){
		pair<ll,int>p = que.top(); que.pop();
		if(dist[p.sc] != p.fi) continue;
		for(int i=0;i<edge[p.sc].size();i++){
			int to = edge[p.sc][i].fi;
			ll cs = edge[p.sc][i].sc;
			if(dist[to] > dist[p.sc]+cs){
				dist[to] = dist[p.sc]+cs;
				way[to]  = way[p.sc];
				que.push(mp(dist[to],to));
			}
			else if(dist[to] == dist[p.sc]+cs){
				way[to] += way[p.sc];
				way[to] %= mod;
			}
		}
	}
	fill(dist2,dist2+n+5,1e18);
	dist2[t] = 0; way2[t] = 1;
	que.push(mp(0,t));
	while(!que.empty()){
		pair<ll,int>p = que.top(); que.pop();
		if(dist2[p.sc] != p.fi) continue;
		for(int i=0;i<edge[p.sc].size();i++){
			int to = edge[p.sc][i].fi;
			ll cs = edge[p.sc][i].sc;
			if(dist2[to] > dist2[p.sc]+cs){
				dist2[to] = dist2[p.sc]+cs;
				way2[to] = way2[p.sc];
				que.push(mp(dist2[to],to));
			}
			else if(dist2[to] == dist2[p.sc]+cs){
				way2[to] = (way2[to]+way2[p.sc])%mod;
			}
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
	    if(dist[i] == dist2[i] && dist[i] + dist2[i] == dist[t]){
	        ans += way[i] % mod * way[i] % mod * way2[i] % mod * way2[i] % mod;
	        ans %= mod;
	    }
		for(int j=0;j<edge[i].size();j++){
			if(dist[i]+edge[i][j].sc+dist2[edge[i][j].fi] == dist[t]){
				ll L1 = dist[i],R1 = dist[edge[i][j].fi];
				ll L2 = dist2[edge[i][j].fi],R2 = dist2[i];
				if(L1 < R2 && L2 < R1){
					ans += way[i] % mod * way[i] % mod * way2[edge[i][j].fi] % mod * way2[edge[i][j].fi] % mod;
					ans %= mod; 
				}
			}
		}
	}
	assert(way2[s] == way[t]);
	assert(dist[t] == dist2[s]);
	way[t] %= mod;
	ans = way[t] * way[t] % mod - ans;
	ans = (ans%mod+mod)%mod;
	cout << ans << endl;
}