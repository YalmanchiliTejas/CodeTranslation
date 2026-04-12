#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
int n, m, s, t;
std::vector<std::vector<std::pair<int, int>>> g;
std::vector<long long> dist;
std::vector<long long> a, b, c, dp1, dp2;

void solve(){
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> qu;
	dist[s] = 0; qu.push({0, s});
	
	while(!qu.empty()){
		auto p = qu.top(); qu.pop();
		
		for(auto e : g[p.second]){
			if(p.first + e.second >= dist[e.first]) continue;
			dist[e.first] = p.first + e.second;
			qu.push({dist[e.first], e.first});
		}
	}
	
	std::vector<std::pair<long long, int>> vec; dp1[s] = 1; dp2[t] = 1;
	for(int i = 0; i < n; i++) vec.push_back({dist[i], i});
	sort(begin(vec), end(vec));
	
	for(int i = 0; i < n; i++){
		for(auto e : g[vec[i].second]){
			if(vec[i].first + e.second == dist[e.first]){
				(dp1[e.first] += dp1[vec[i].second]) %= MOD;
			}
		}
	}
	
	for(int i = n - 1; i >= 0; i--){
		for(auto e : g[vec[i].second]){
			if(dist[e.first] + e.second == vec[i].first){
				(dp2[e.first] += dp2[vec[i].second]) %= MOD;
			}
		}
	}
}

int main(){
	std::cin >> n >> m >> s >> t; g.resize(n); s--; t--;
	a.resize(m); b.resize(m); c.resize(m);
	for(int i = 0; i < m; i++){
		std::cin >> a[i] >> b[i] >> c[i]; a[i]--; b[i]--;
		
		g[a[i]].push_back({b[i], c[i]});
		g[b[i]].push_back({a[i], c[i]});
	}
	
	dist.resize(n, 1e18); dp1.resize(n, 0); dp2.resize(n, 0); solve();
	
	long long ans = dp1[t] * dp1[t] % MOD;
	for(int i = 0; i < n; i++){
		if(dist[i] * 2 != dist[t]) continue;
		ans = (ans - dp1[i] * dp1[i] % MOD * dp2[i] % MOD * dp2[i] % MOD + MOD) % MOD;
	}
	
	for(int i = 0; i < m; i++){
		if(dist[a[i]] + c[i] == dist[b[i]] and dist[a[i]] * 2 < dist[t] and dist[t] < dist[b[i]] * 2){
			ans = (ans - dp1[a[i]] * dp1[a[i]] % MOD * dp2[b[i]] % MOD * dp2[b[i]] % MOD + MOD) % MOD;
		}else if(dist[b[i]] + c[i] == dist[a[i]] and dist[b[i]] * 2 < dist[t] and dist[t] < dist[a[i]] * 2){
			ans = (ans - dp1[b[i]] * dp1[b[i]] % MOD * dp2[a[i]] % MOD * dp2[a[i]] % MOD + MOD) % MOD;
		}
	}
	
	std::cout << ans << std::endl;
	return 0;
}
