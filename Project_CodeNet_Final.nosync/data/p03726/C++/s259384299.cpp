#include<bits/stdc++.h>
#define now edge[i].v
#define go(x) for(int i=head[x];i;i=edge[i].nxt)
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int sz=1e5+7;
int n;
int u,v,cnt;
bool flag;
bool vis[sz];
int head[sz];
struct Edge{
	int v,nxt;
}edge[sz<<1];
void add(int u,int v){
	edge[++cnt]=(Edge){v,head[u]};head[u]=cnt;
	edge[++cnt]=(Edge){u,head[v]};head[v]=cnt;
}
void dfs(int x,int fa){
	go(x) if(now!=fa){
		dfs(now,x);
		if(!vis[x]&&!vis[now]) vis[x]=vis[now]=1;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dfs(1,0);
	rep(i,1,n) flag|=!vis[i];
	if(flag) printf("First\n");
	else printf("Second\n");
} 