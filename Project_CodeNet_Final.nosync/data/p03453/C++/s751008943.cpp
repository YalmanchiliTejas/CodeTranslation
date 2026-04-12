#include <bits/stdc++.h>
#define Maxn 400007
#define modp 1000000007
#define inf 200000000000007LL
using namespace std;
int n,m,s,t;
int cnt=0,last[Maxn],pre[Maxn],other[Maxn],val[Maxn];
int cnt1=0,last1[Maxn],pre1[Maxn],other1[Maxn];
int cnt2=0,last2[Maxn],pre2[Maxn],other2[Maxn];
bool vis[Maxn];
long long f[Maxn],f1[Maxn];
int w[Maxn],w1[Maxn],d[Maxn],d1[Maxn];
int que[Maxn];
priority_queue<pair<long long,int> > pq,pq1;
void insert(int u,int v,int t)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
	val[cnt]=t;
}
void insert1(int u,int v)
{
	other1[++cnt1]=v,pre1[cnt1]=last1[u],last1[u]=cnt1;
	++d[v];
}
void insert2(int u,int v)
{
	other2[++cnt2]=v,pre2[cnt2]=last2[u],last2[u]=cnt2;
	++d1[v];
}
void tryit1()
{
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
		f[i]=inf;
	f[s]=0;
	pq.push(make_pair(0,s));
	while (!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (int q=last[u];q;q=pre[q])
		{
			int v=other[q];
			if (f[u]+val[q]<f[v])
			{
				f[v]=f[u]+val[q];
				pq.push(make_pair(-f[v],v));
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int q=last[i];q;q=pre[q])
		{
			int v=other[q];
			if (f[i]==f[v]+val[q]) insert1(v,i);
		}
	}
	w[s]=1;
	int lx=0,rx=0;
	que[++rx]=s;
	while (lx<rx)
	{
		int u=que[++lx];
		for (int q=last1[u];q;q=pre1[q])
		{
			int v=other1[q];
			w[v]=(w[v]+w[u])%modp;
			--d[v];
			if (d[v]==0) que[++rx]=v;
		}
	}
}
void tryit2()
{
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
		f1[i]=inf;
	f1[t]=0;
	pq1.push(make_pair(0,t));
	while (!pq1.empty())
	{
		int u=pq1.top().second;
		pq1.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (int q=last[u];q;q=pre[q])
		{
			int v=other[q];
			if (f1[u]+val[q]<f1[v])
			{
				f1[v]=f1[u]+val[q];
				pq1.push(make_pair(-f1[v],v));
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int q=last[i];q;q=pre[q])
		{
			int v=other[q];
			if (f1[i]==f1[v]+val[q]) insert2(v,i);
		}
	}
	w1[t]=1;
	int lx=0,rx=0;
	que[++rx]=t;
	while (lx<rx)
	{
		int u=que[++lx];
		for (int q=last2[u];q;q=pre2[q])
		{
			int v=other2[q];
			w1[v]=(w1[v]+w1[u])%modp;
			--d1[v];
			if (d1[v]==0) que[++rx]=v;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for (int i=1;i<=m;i++)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		insert(u,v,t);
		insert(v,u,t);
	}
	tryit1();
	tryit2();
	int ans=(1LL*w[t]*w1[s]%modp)%modp;
	for (int i=1;i<=n;i++)
		if (2LL*f[i]==f[t]&&f[i]==f1[i]) 
		{
			int del=(1LL*w[i]*w1[i])%modp;
			ans=(ans+modp-(1LL*del*del%modp)%modp)%modp;
		}
	for (int i=1;i<=n;i++)
		for (int q=last[i];q;q=pre[q])
		{
			int v=other[q];
			if (2LL*f[i]<f[t]&&2LL*f[v]>f[t]&&f[i]+f1[v]+val[q]==f[t])
			{
				int del=(1LL*w[i]*w1[v])%modp;
				ans=(ans+modp-(1LL*del*del%modp)%modp)%modp;
			}
		}
	printf("%d\n",ans);
	return 0;
}
