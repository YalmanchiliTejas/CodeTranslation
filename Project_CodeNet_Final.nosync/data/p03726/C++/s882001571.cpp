#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;

int n,deg[maxn];
int tote,FIR[maxn],TO[maxn],NEXT[maxn];
bool vis[maxn];
queue<int> q;

void addedge(int u,int v)
{
	TO[++tote]=v;
	NEXT[tote]=FIR[u];
	FIR[u]=tote;
}

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i,u,v;
	scanf("%d",&n);
	if (n&1) {puts("First"); return 0;}
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		deg[u]++; deg[v]++;
	}
	for (i=1;i<=n;i++)
		if (deg[i]==1) q.push(i);
	vis[0]=1;
	for (i=1;i<=n>>1;i++)
	{
		u=v=0;
		while (vis[u]) u=q.front(),q.pop();
		for (int p=FIR[u];p;p=NEXT[p])
		{
			v=TO[p];
			if (!vis[v]) break;
		}
		if (vis[v]) {puts("First"); return 0;}
		vis[u]=vis[v]=1;
		for (int p=FIR[v];p;p=NEXT[p])
		{
			u=TO[p];
			if (!vis[u]&&(--deg[u])==1) q.push(u);
		}
	}
	puts("Second");
}
