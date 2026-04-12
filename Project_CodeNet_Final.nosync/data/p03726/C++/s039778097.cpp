
#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;
int tot=0,head[maxn],n,x,y,siz[maxn],f[maxn];
struct line{int to,next;}e[maxn*2];
void pushline(int x,int y)
{
	e[++tot].to=y;e[tot].next=head[x],head[x]=tot;
}
bool dfs(int x,int fa)
{
	siz[x]=1;
	int cnt=0;
	for(int i=head[x];int v=e[i].to;i=e[i].next)
	{
		if(v==fa)continue;
		if(dfs(v,x))return 1;
		if(siz[v])
		{
			cnt++,siz[x]=0;
			if(cnt==2)return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		pushline(x,y);pushline(y,x);
	}
	printf(dfs(1,0)||siz[1]?"First":"Second");
}
/*
先手如果摁了叶子的爸爸，那么后手必定跟着染叶子，这样非常赚。然后这两个点就可以滚了，因为爸爸已经被叶子标记掉了。
不断这样处理即可。
*/