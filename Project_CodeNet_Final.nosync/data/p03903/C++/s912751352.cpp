#include <bits/stdc++.h>
using namespace std;
const int maxn = 4040;
int uf[maxn];
int find(int x){
	if(x == uf[x]) return x;
	return uf[x] = find(uf[x]);
}
vector<pair<int,int> > e[maxn];
int dep[maxn], par[maxn], cost[maxn];
void dfs(int u){
	for(auto to : e[u]){
		if(to.first == par[u]) continue;
		dep[to.first] = dep[u] + 1;
		cost[to.first] = to.second;
		par[to.first] = u;
		dfs(to.first);
	}
}
int main(){
	iota(uf, uf + maxn, 0);
	int n, m; cin >> n >> m;
	vector<tuple<int,int,int> > eds;
	for(int i = 0; i < m; i++){
		int u, v, w; cin >> u >> v >> w;
		eds.push_back(make_tuple(w, u, v));
	}
	sort(eds.begin(), eds.end());
	long long mst = 0;
	for(int i = 0; i < m; i++){
		int u, v, w; tie(w, u, v) = eds[i];
		if(find(u) != find(v)){
			e[u].push_back({v, w});
			e[v].push_back({u, w});
			mst += w;
			uf[find(u)] = find(v);
		}
	}
	dfs(1);
	int q; scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int s, t; cin >> s >> t;
		int big = 0;
		while(s != t){
			if(dep[s] < dep[t]) swap(s, t);
			big = max(big, cost[s]);
			s = par[s];
		}
		printf("%lld\n", mst - big);
	}
	return 0;
}
