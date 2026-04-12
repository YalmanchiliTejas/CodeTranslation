#include<cstdio>
int a[10][10],ans=0,vis[10],n;
void dfs(int k)
{
	vis[k]=1;
	int f=1;
	for(int i=1;i<=n;i++)
	if(!vis[i]) f=0;
	if(f) {ans++;return;}
	for(int i=1;i<=n;i++)
	if(!vis[i]&&a[k][i])
	{
		dfs(i);
		vis[i]=0;
	}
}
int main()
{
	int m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}