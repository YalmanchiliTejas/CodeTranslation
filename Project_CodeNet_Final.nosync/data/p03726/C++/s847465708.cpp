#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int n, fa[maxn];
vector<int> g[maxn];
int ans;

bool dfs(int x){
	// printf("%d\n", x);
	int ret=0;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i]; if(v==fa[x]) continue;
		fa[v]=x; 
		ret+=dfs(v);
	}
	if(ret>1) ans=1;
	return !ret;
}

int main(){

	scanf("%d",&n);
	int x, y;
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y), g[x].push_back(y), g[y].push_back(x);
	ans=n&1;
	dfs(1);
	printf("%s\n", ans ? "First" : "Second");
	return 0;
}