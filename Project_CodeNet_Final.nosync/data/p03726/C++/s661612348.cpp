#include<bits/stdc++.h>
#define N 100010
#define p_b push_back

using namespace std;

bool ans;
int n;
vector<int> e[N];
int f[N],sz[N];

void dfs(int u,int fa){
	int i,v;
	f[u]=1;
	for(i=0;i<e[u].size();i++)
	if(e[u][i]!=fa){
		dfs(e[u][i],u);
		if(f[e[u][i]]){f[u]=0; sz[u]++;}
	}
}

void dfs2(int u,int fa,int t){
	int i;
	sz[u]+=t; if(sz[u]) f[u]=0; else f[u]=1;
	if(!sz[u] || sz[u]>=2) ans=1;
	
	for(i=0;i<e[u].size();i++)
	if(e[u][i]!=fa){
		if(sz[u]-f[e[u][i]]<=0) dfs2(e[u][i],u,1); else dfs2(e[u][i],u,0);
	}
}

int main(){
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].p_b(y); e[y].p_b(x);
	}
	dfs(1,0);
	dfs2(1,0,0);
	if(ans) puts("First"); else puts("Second");
	return 0;
}