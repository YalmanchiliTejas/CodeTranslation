#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 1000005
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,m,s,t,tot;
ll val[maxn];
int head[maxn],nex[maxn],to[maxn],id[maxn];
void add(int x,int y,int z)
{
	to[++tot]=y; val[tot]=z; nex[tot]=head[x]; head[x]=tot;
}
queue<int> q;
ll dp1[maxn],dp2[maxn],dis1[maxn],dis2[maxn],vis[maxn],dis3[maxn];
int cmp(int i,int j)
{
	return dis3[i]<dis3[j];
}
void spfa(int start,ll *dp,ll *dis)
{
	for(int i=0;i<=n;i++)
		dis[i]=12345678912331231ll,id[i]=i;

	dis[start]=0; dp[start]=1;
	q.push(start);
	while(!q.empty())
	{
		int now=q.front(); q.pop(); vis[now]=0;
		for(int i=head[now];i;i=nex[i])
		{
			if(dis[to[i]]>dis[now]+val[i])
			{
				dis[to[i]]=dis[now]+val[i];
				if(!vis[to[i]])
				{
					vis[to[i]]=1;
					q.push(to[i]);
				}
			}
		}
	}

	memcpy(dis3,dis,sizeof(ll)*maxn);

	sort(id+1,id+1+n,cmp);

	for(int i=1;i<=n;i++)
	{
		int now=id[i];
//		cerr<<dis2[i]<<endl;
//		cerr<<id[i]<<endl;
		for(int j=head[now];j;j=nex[j])
		{
			if(dis[to[j]]==dis[now]+val[j])
			{
				dp[to[j]]+=dp[now];
				dp[to[j]]%=mod;
			}
		}
	}

}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	spfa(s,dp1,dis1);
	spfa(t,dp2,dis2);
	ll d=dis1[t];
//	cerr<<d<<endl;
  	ll ans=(dp1[t]*dp1[t])%mod;
//	cerr<<"its "<<dp1[t]<<" "<<dp2[s]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(dis1[i]*2==d && dis2[i]*2==d)
		{
			ans-=((dp1[i]*dp2[i])%mod*((dp1[i]*dp2[i])%mod)%mod);
//			cerr<<"its "<<i<<" "<<dp1[i]<<" "<<dp2[i]<<endl;
			ans=(ans%mod+mod)%mod;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=nex[j])
		{
//			cerr<<i<<" "<<to[j]<<" "<<dis1[i]<<" "<<val[j]<<" "
			if(dis1[i]*2<d && dis2[to[j]]*2<d && dis1[i]+dis2[to[j]]+val[j]==d)
			{
//				cerr<<"+1"<<endl;
				ans-=(dp1[i]*dp2[to[j]])%mod*((dp1[i]*dp2[to[j]])%mod)%mod;
				ans=(ans%mod+mod)%mod;
			}
		}
	}

	printf("%lld\n",ans);
}
