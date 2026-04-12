#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge{ int from,to,cost; };

int par[4010],rnk[4010];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rnk[x] < rnk[y]) par[x] = y;
	else{
		par[y] = x;
		if(rnk[x] == rnk[y]) rnk[x]++;
	}
}

bool same(int a,int b){
	return find(a) == find(b);
}

int ma[4000][4000];
vector<edge> G[4000],vec;

void dfs(int v,int par,int r){
	for(edge e : G[v]){
		if(e.to != par){
			ma[e.to][r] = max(ma[v][r],e.cost);
			dfs(e.to,v,r);
		}
	}
}

signed main(){
	int n,m,q,sum = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		rnk[i] = 0;
		par[i] = i;
	}
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c; a--;b--;
		vec.push_back({a,b,c});
	}
	sort(vec.begin(),vec.end(),[](const edge a,const edge b){ return a.cost < b.cost; });
	for(edge e : vec){
		if(!same(e.from,e.to)){
			unite(e.from,e.to);
			sum += e.cost;
			G[e.from].push_back(e);
			G[e.to].push_back({e.to,e.from,e.cost});
		}
	}
	for(int i = 0;i < n;i++) dfs(i,-1,i);
	cin >> q;
	for(int i = 0;i < q;i++){
		int s,t;
		cin >> s >> t; s--;t--;
		cout << sum - ma[s][t] << endl;
	}
	return 0;
}