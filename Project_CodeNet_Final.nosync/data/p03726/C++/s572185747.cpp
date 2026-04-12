#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[N],to[N*2],nxt[N*2],fst[N],l,ans;
void link(int x,int y)
{
	to[++l]=y;nxt[l]=fst[x];fst[x]=l;
	to[++l]=x;nxt[l]=fst[y];fst[y]=l;
}
void dfs(int x,int f)
{
	for (int i=fst[x];i;i=nxt[i])
		if (to[i]!=f)
		{
			dfs(to[i],x);
			if (!a[to[i]])
				ans|=a[x],a[x]=a[to[i]]=1;
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	dfs(1,0);ans|=a[1]==0;
	puts(ans?"First":"Second");
}