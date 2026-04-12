#include "bits/stdc++.h"
using namespace std;

#define ll long long 
#define ii pair<ll,ll>
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7, INF = 1e18;

int n, m, s, t;
ii fromS[MAXN], fromT[MAXN];
vector<ii> adj[MAXN];
ll ans;

ll add(ll a, ll b){ return (a+b+MOD)%MOD; }
ll mul(ll a, ll b){ return (a*b)%MOD; }

void dijkstra(ii d[], int start){
	for(int i = 1; i <= n; ++i){
		d[i] = ii(INF, 0);
	}
	priority_queue<ii> pq;
	pq.push(ii(0, start));
	while(!pq.empty()){
		ii top = pq.top(); pq.pop();
		ll curDist = -top.first, pos = top.second;
		if(d[pos].first <= curDist)
			continue;
		d[pos] = ii(curDist, 0);
		for(ii i : adj[pos]){
			pq.push(ii(-d[pos].first-i.second, i.first));
		}
	}

	vector<int> dist = {};
	for(int i = 1; i <= n; ++i) dist.push_back(i);
	sort(dist.begin(), dist.end(), [d](int a, int b){ return d[a].first < d[b].first; });
	d[start].second = 1;
	for(int i = 1; i < n; ++i){
		int pos = dist[i];
		for(ii j : adj[pos]){
			if(d[j.first].first+j.second == d[pos].first){
				d[pos].second = add(d[pos].second, d[j.first].second);
			}
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 0; i < m; ++i){
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}

	dijkstra(fromS, s);
	dijkstra(fromT, t);
	assert(fromS[t].second == fromT[s].second && fromS[t].first == fromT[s].first);

	// Get all paths
	ll ans = mul(fromS[t].second, fromS[t].second);
	// Minus meet at vertex
	for(int i = 1; i <= n; ++i){
		// printf("(%lld, %lld) (%lld, %lld)\n", fromS[i].first, fromS[i].second, fromT[i].first, fromT[i].second);
		if(fromS[i].first == fromT[i].first)
		if(fromS[i].first+fromT[i].first == fromS[t].first){
			ll tmp = mul(fromS[i].second, fromT[i].second);
			tmp = mul(tmp, tmp);
			// printf("Del %lld %d\n", tmp, i);
			ans = add(ans, -tmp);
		}
	}
	// Minus meet at edge
	for(int i = 1; i <= n; ++i){
		for(ii j : adj[i]){
			if(fromS[i].first != fromT[i].first && fromS[j.first].first != fromT[j.first].first)
			if(fromS[i].first + fromT[j.first].first + j.second == fromS[t].first)
			if(2*fromS[i].first < fromS[t].first && 2*fromS[j.first].first > fromS[t].first){
				ll tmp = mul(fromS[i].second, fromT[j.first].second);
				tmp = mul(tmp, tmp);
				ans = add(ans, -tmp);
			}
		}
	}
	printf("%lld\n", ans);
}