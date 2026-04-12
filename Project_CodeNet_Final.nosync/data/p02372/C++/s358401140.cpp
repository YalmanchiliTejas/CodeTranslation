#include  <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pb push_back
using namespace std;

typedef long long ll;

const int vmax=100010;
struct node{ll to,cost;};

vector<node> graph[vmax];

ll dist[vmax],cmax[vmax];

void tree_height(int n){
	function<void(int,int,ll)> dfs=[&dfs](int v,int p,ll c){
		dist[v]=c;
		for(auto &e:graph[v]) if(e.to!=p) dfs(e.to,v,c+e.cost);
	};
	dfs(0,-1,0LL);
	int u=0; rep(i,n) if(dist[i]>dist[u]) u=i;
	dfs(u,-1,0LL);
	int v=0; rep(i,n) if(dist[i]>dist[v]) v=i;
	function<void(int,int,ll,int)> dfs2=[&dfs2](int v,int p,ll c,int s){
		cmax[v]=max(cmax[v],c);
		for(auto &e:graph[v]) if(e.to!=p) dfs2(e.to,v,c+e.cost,s);
	};
	dfs2(u,-1,0LL,u);
	dfs2(v,-1,0LL,v);
}

int main(void){
	int n;
	cin >> n;
	rep(i,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].pb({b,c});
		graph[b].pb({a,c});
	}
	tree_height(n);
	rep(i,n) cout << cmax[i] << endl;
	return 0;
}