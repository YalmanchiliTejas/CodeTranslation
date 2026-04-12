#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define llint long long
#define inf 1000000000000000
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, V, D;
llint s, t;
vector<edge> G[300005];
llint dist[300005];
llint numS[300005], numT[300005], num[300005];
bool valid[300005];
bool used[300005];
vector<int> topo;

void dijkstra(llint S, llint dist[])
{
	for(int i = 1; i <= V; i++) dist[i] = inf;
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

void tpsort(int v)
{
	used[v] = true;
	if(!valid[v]){
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to;
			if(used[u]) continue;
			if(dist[u] > D || dist[u] == D && !valid[u]) continue;
			if(dist[v] + G[v][i].cost == dist[u]) tpsort(u);
		}
	}
	topo.push_back(v);
}

llint calc(llint S, llint num[])
{
	dijkstra(S, dist);
	for(int i = 1; i <= V; i++) used[i] = false;
	topo.clear(), tpsort(S);
	reverse(topo.begin(), topo.end());
	
	for(int i = 1; i <= V; i++) num[i] = 0;
	num[S] = 1;
	for(int i = 0; i < topo.size(); i++){
		int v = topo[i];
		if(valid[v]) continue;
		for(int j = 0; j < G[v].size(); j++){
			int u = G[v][j].to;
			if(dist[u] > D || dist[u] == D && !valid[u]) continue;
			if(dist[v] + G[v][j].cost == dist[u]) (num[u] += num[v]) %= mod;
		}
	}
}

int main(void)
{
	cin >> n >> m;
	cin >> s >> t;
	llint u, v, d;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> d;
		d *= 2;
		G[u].push_back(edge(v, d));
		G[v].push_back(edge(u, d));
	}
	
	V = n;
	dijkstra(s, dist);
	D = dist[t]/2;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			int u = G[i][j].to;
			if(dist[i] + G[i][j].cost != dist[u]) continue;
			if(dist[i] < D && dist[u] > D){
				V++;
				G[i].push_back(edge(V, D-dist[i]));
				G[V].push_back(edge(i, D-dist[i]));
				G[u].push_back(edge(V, dist[u]-D));
				G[V].push_back(edge(u, dist[u]-D));
			}
		}
	}
	
	for(int i = 1; i <= V; i++) valid[i] = true;
	dijkstra(s, dist);
	for(int i = 1; i <= V; i++) if(dist[i] != D) valid[i] = false;
	dijkstra(t, dist);
	for(int i = 1; i <= V; i++) if(dist[i] != D) valid[i] = false;
	
	calc(s, numS);
	calc(t, numT);
	
	for(int i = 1; i <= V; i++) num[i] = numS[i]*numT[i]%mod;
	llint sum = 0;
	for(int i = 1; i <= V; i++){
		if(!valid[i]) continue;
		sum += num[i], sum %= mod;
	}
	llint ans = sum*sum%mod;
	for(int i = 1; i <= V; i++){
		if(!valid[i]) continue;
		ans += mod - num[i]*num[i]%mod;
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}