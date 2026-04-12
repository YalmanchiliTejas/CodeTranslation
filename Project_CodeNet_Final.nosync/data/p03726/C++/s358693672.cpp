#include<iostream>
#include<cstdio>
using namespace std;
int h[101000],nxt[201000],K=0,to[201000];int fa[101000];
bool used[101000];int in[101000];
int q[1010000],H=0,T=0;
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=h[x];i;i=nxt[i])if(to[i]!=f)dfs(to[i],x);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	dfs(1,0);used[0]=1;
	for(int i=1;i<=n;i++)in[fa[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)q[T++]=i;
	}
	bool ok=0;
	while(H<T)
	{
		int u=q[H++];if(used[u])continue;used[u]=1;
		if(used[fa[u]]){ok=1;break;}
		used[fa[u]]=1;in[fa[fa[u]]]--;
		if(!used[fa[fa[u]]]&&in[fa[fa[u]]]==0)q[T++]=fa[fa[u]];
	}
	if(ok)puts("First");else puts("Second");
	return 0;
}