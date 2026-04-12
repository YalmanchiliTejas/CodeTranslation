#include <bits/stdc++.h>
using namespace std;
int N, M, Q; 
long long sum;
pair<long long, pair<int, int>> E[400010]; 
vector<pair<int, long long>> G[4010]; 
int par[4010]; 
int depth[4010]; 
int sz[4010]; 
void init(){
	for(int i = 0; i < N; i++){
		par[i] = i; depth[i] = 0; sz[i] = 1; 
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}
	else{
		return par[x] = find(par[x]); 
	}
}
void unite(int x, int y){
	x = find(x); 
	y = find(y); 
	if(x == y) return;
	else if(depth[x] < depth[y]){
		par[x] = y; 
		sz[y] += sz[x]; 
	}else{
		par[y] = x; 
		sz[x] += sz[y];  
		if(depth[x] == depth[y]) depth[x] ++; 
	}
}
bool same(int x, int y){
	return find(x) == find(y); 
}
int siz(int x){
	return sz[find(x)]; 
}
long long mx[4010][4010]; 
void dfs(int r, int v, int p, long long m){
	mx[r][v] = m; 
	for(auto a : G[v]){
		if(a.first == p) continue; 
		long long tmp = m; 
		dfs(r, a.first, v, max(m, a.second)); 
		m = tmp; 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> N >> M; 	
	for(int i = 0; i < M; i++){
		cin >> E[i].second.first >> E[i].second.second >> E[i].first; 
		E[i].second.first --; E[i].second.second --; 
	}
	sort(E, E+M); 
	init();  
	for(int i = 0; i < M; i++){
		int a = E[i].second.first; int b = E[i].second.second; 
		if(same(a, b)) continue; 
		unite(a, b); 
		G[a].emplace_back(b, E[i].first); 
		G[b].emplace_back(a, E[i].first); 
		sum += E[i].first; 
	}
	for(int i = 0; i < N; i++) dfs(i, i, -1, 0);
	cin >> Q; 
	while(Q--){
		int S, T; cin >> S >> T; 
		S--; T--; 
		cout << sum - mx[S][T] << "\n"; 
	}
}