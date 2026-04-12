#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, s, t, d;
vector<edge> G[100005];
llint distS[100005], distT[100005];
llint dpS[100005], dpT[100005];
vector<int> topo;
bool used[100005];

void dijkstra(vector<edge> G[], llint S, llint dist[])
{
	for(int i = 0; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	priority_queue< P, vector<P>, greater<P> > Q;
	Q.push( make_pair(0, S) );
	
	llint v, d;
	while(Q.size()){
		d = Q.top().first;
		v = Q.top().second;
		Q.pop();
		if(dist[v] < d) continue;
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i].to] > d + G[v][i].cost){
				dist[G[v][i].to] = d + G[v][i].cost;
				Q.push( make_pair(dist[G[v][i].to], G[v][i].to) );
			}
		}
	}
}

vector<llint> g[100005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++){
		if(!used[g[v][i]]) tpsort(g[v][i]);
	}
	topo.push_back(v);
}

void calc(llint S, llint distS[], llint distT[], llint dp[])
{
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			llint u = G[i][j].to;
			if(distS[i] + G[i][j].cost == distS[u] && distS[i] + distT[u] + G[i][j].cost == d) g[i].push_back(u);
		}
	}
	topo.clear();
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	for(int i = 1; i <= n; i++) dp[i] = 0;
	dp[S] = 1;
	for(int i = 0; i < topo.size(); i++){
		llint v = topo[i];
		for(int j = 0; j < g[v].size(); j++) (dp[g[v][j]] += dp[v]) %= mod;
	}
}

int main(void)
{
	cin >> n >> m >> s >> t;
	llint u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	dijkstra(G, s, distS);
	dijkstra(G, t, distT);
	d = distS[t];
	
	calc(s, distS, distT, dpS);
	calc(t, distT, distS, dpT);
	
	llint ans = dpS[t]*dpS[t]%mod;
	for(int i = 1; i <= n; i++){
		if(d%2 == 0 && distS[i] == d/2 && distT[i] == d/2){
			llint tmp = dpS[i]*dpT[i]%mod;
			ans += mod - tmp*tmp%mod, ans %= mod;
		}
		for(int j = 0; j < G[i].size(); j++){
			llint u = G[i][j].to;
			if(distS[i] < d/2 && distT[u] < d/2 && distS[i] + G[i][j].cost == distS[u] && distS[i] + distT[u] + G[i][j].cost == d){
				llint tmp = dpS[i]*dpT[u]%mod;
				ans += mod - tmp*tmp%mod, ans %= mod;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
