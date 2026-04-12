#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n,m,cnt;bool vis[maxn];
vector<int>g[maxn];
void dfs(int u,map<int,bool>m){
	bool flag = 0;
	for(register int i=g[u].size()-1;i>=0;i--){
		int v = g[u][i];
		if(!vis[v]){
			flag=1;
			m[v]=1;
			vis[v]=1;
			dfs(v,m);
			m.erase(v);//cnmb rnm cnm STL ++!
			vis[v]=0;
		}
	}
	if(!flag){
		if(m.size()==n){
			++cnt;
		}
	}
}
void addE(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
int main(){
	scanf("%d%d",&n,&m);
	int a,b;
	for(register int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		addE(a,b);
	}
	map<int,bool>m;vis[1]=1;m[1]=1;
	dfs(1,m);printf("%d",cnt);
}