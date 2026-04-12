#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,k,w[100005],u,head[100005],adj[200005],nxt[200005],d[100005],size[100005],sz[100005];
void dfs(int x,int dad)
{
	sz[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			sz[x]+=sz[adj[y]];
		}
	if(sz[x]>2)
		u=1;
	else if(sz[x]==2)
		sz[x]=0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		++d[j],++d[k];
	}
	dfs(1,-1);
	if(sz[1])
		u=1;
	if(u)
		printf("First");
	else
		printf("Second");
	return 0;
}
