#include <bits/stdc++.h>
using namespace std;

struct edge{int s,t,n;}e[200010];
int n,h[100010],ans;

bool dfs(int x,int f)
{
	bool p=0;
	for (int i=h[x],y; y=e[i].t,i; i=e[i].n)
		if ((y!=f)&&(dfs(y,x)))
			ans+=!p,p=1;
	return !p;
}

void work()
{
	scanf("%d",&n);
	for (int i=1,u,v,tot=0; i<n; i++)
		{
			scanf("%d %d",&u,&v);
			e[++tot]=(edge){u,v,h[u]},h[u]=tot;
			e[++tot]=(edge){v,u,h[v]},h[v]=tot;
		}
	dfs(1,0);
	puts(2*ans==n?"Second":"First");
}

int main()
{
	work();
	return 0;
}
