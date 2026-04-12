#include<cstdio>
using namespace std;
int x[10][10],ans=0,vis[10];
int n,m;
void dfs(int v,int u){
	//printf("v:%d u%d\n",v,u);
	if(u==n) {ans++;return;}
	for(int i=1;i<=10;i++){
		if(!x[v][i])continue;
		if(vis[i])continue;
		vis[i]=1;
		dfs(i,u+1);
		vis[i]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int a,b,i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		x[a][b]=1;x[b][a]=1;
	}
	vis[1]=1;
	dfs(1,1);
	printf("%d",ans);
}