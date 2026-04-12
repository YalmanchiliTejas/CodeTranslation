#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000LL * 1000 * 1000 + 7)
#define maxn 200111

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

vector<pll> adj[maxn];
ll dps[maxn], dpt[maxn], froms[maxn], fromt[maxn];
ll n, m, s, t;

void dijkstra(ll start, ll d[], ll dp[]){
	for(int i = 1; i <= n; i++){
		d[i] = INF;
		dp[i] = 0;
	}

	priority_queue<pll> pq;
	d[start] = 0;
	dp[start] = 1;
	pq.push(mp(0, start));
	while(!pq.empty()){
		ll x = pq.top().se;
		ll val = -pq.top().fi;
		pq.pop();

		if(val > d[x])
			continue;

		for(auto i : adj[x]){
			ll v = i.fi;
			ll cost = i.se;

			if(d[v] > d[x] + cost){
				d[v] = d[x] + cost;
				dp[v] = dp[x];
				pq.push(mp(-d[v], v));
				continue;
			}
			if(d[v] == d[x] + cost)
				dp[v] = (dp[v] + dp[x]) % MOD;
		}
	}

}

int main(){
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
	for(int i = 0; i < m; i++){
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		adj[a].pb(mp(b, c));
		adj[b].pb(mp(a, c));
	}

	dijkstra(s, froms, dps);
	dijkstra(t, fromt, dpt);


	ll shortest_path = froms[t];
	ll all = (dps[t] * dps[t]) % MOD; // number of all shortest paths
	ll snode = 0;	// shortest paths that intersect at node
	ll sedge = 0; 	// shortest paths that intersect at edge
	
	for(ll i = 1LL; i <= n; i++){
		if(froms[i] == fromt[i] && froms[i] + fromt[i] == shortest_path)
			snode = (snode + dps[i] * dps[i] % MOD * dpt[i] % MOD * dpt[i] % MOD) % MOD;

		for(auto j : adj[i]){
			ll v = j.fi;
			ll cost = j.se;

			if(2 * froms[i] < shortest_path && 2 * fromt[v] < shortest_path && froms[i] + fromt[v] + cost == shortest_path)
				sedge = (sedge + dps[i] * dps[i] % MOD * dpt[v] % MOD * dpt[v] % MOD) % MOD;
		}
	}

	printf("%lld\n", (all - snode - sedge + 3 * MOD) % MOD);	
	return 0;
}