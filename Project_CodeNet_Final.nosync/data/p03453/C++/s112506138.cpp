#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define fi first
#define se second

const int N = 1e5+1, mod = 1e9+7;

int n,m,s,t;

vector<pii> g[N];
int dist[2][N], num[2][N];

void dijkstra(int mode, int x){
	fill(dist[mode], dist[mode]+N, (int)1e18);
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,x});
	dist[mode][x] = 0;
	num[mode][x] = 1;

	while(!pq.empty()){
		int d,u;
		tie(d,u) = pq.top();
		pq.pop();
		if(d==dist[mode][u]){
			for(auto nxt:g[u]){
				int v,w;
				tie(v,w) = nxt;
				if(dist[mode][v] >= dist[mode][u] + w){
					if(dist[mode][v]==dist[mode][u] + w){
						(num[mode][v] += num[mode][u]) %= mod;	
					}else{
						dist[mode][v] = dist[mode][u] + w;
						num[mode][v] = num[mode][u];
						pq.push({dist[mode][v],v});
					}
				}
			}
		}
	}
}

vector<pair<pii,int>> edge;

int sqr(int x){
	return (x%mod)*(x%mod)%mod;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> s >> t;	
	for(int i=0;i<m;++i){
		int u,v,c;
		cin >> u >> v >> c;
		edge.push_back({{u,v},c});
		g[u].push_back({v,c}), g[v].push_back({u,c});
	}
	dijkstra(0,s), dijkstra(1,t);
	int fin = dist[0][t], ans = num[0][t]*num[1][s]%mod;
	
	for(int i=1;i<=n;++i){
		if(fin%2==0 && dist[0][i]==fin/2 && dist[1][i]==fin/2){
			ans = (ans - sqr(num[0][i]*num[1][i]) + mod*mod)%mod;
		}
	}
	
	for(auto e:edge){
		if(dist[0][e.fi.fi] < fin/2 && dist[1][e.fi.se] < fin/2 && dist[0][e.fi.fi] + dist[1][e.fi.se] + e.se == fin){
			ans = (ans - sqr(num[0][e.fi.fi]*num[1][e.fi.se]) + mod*mod)%mod;
		}
		if(dist[0][e.fi.se] < fin/2 && dist[1][e.fi.fi] < fin/2 && dist[0][e.fi.se] + dist[1][e.fi.fi] + e.se == fin){
			ans = (ans - sqr(num[0][e.fi.se]*num[1][e.fi.fi]) + mod*mod)%mod;
		}
	}	
	cout << ans;
}