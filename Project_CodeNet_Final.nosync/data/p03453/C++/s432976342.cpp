#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
const int MOD=1e9+7;
int n,m,S,T;
struct edge
{
	int v,w;
	edge *next,*rev;
}*h[233333],pool[555555];
int top;
inline void addedge(int u,int v,int w)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->w=w;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->w=w;pmt->next=h[v];h[v]=pmt;
	tmp->rev=pmt;pmt->rev=tmp;
}
long long dis[233333],dp[233333],dp2[233333];
#define mp make_pair
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int ord[233333],pot;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c*2);
	}
	memset(dis,0x3f,sizeof(dis));
	q.push(mp(0ll,S));dis[S]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		if(dis[u]!=q.top().first)
		{
			q.pop();
			continue;
		}
		ord[++pot]=u;
		q.pop();
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(dis[tmp->v]>dis[u]+tmp->w)
			{
				dis[tmp->v]=dis[u]+tmp->w;
				q.push(mp(dis[tmp->v],tmp->v));
			}
		}
	}
	//for(int i=1;i<=n;i++)cout<<ord[i]<<' ';cout<<endl;
	dp[S]=1;
	for(int i=1;i<=n;i++)
	{
		int u=ord[i];
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(dis[tmp->v]==dis[u]+tmp->w)
			{
				dp[tmp->v]+=dp[u];
				dp[tmp->v]%=MOD;
			}
		}
	}
	long long half=dis[T]/2,ans=dp[T]*dp[T]%MOD;
//	cout<<"half: "<<half<<endl;
//	cout<<"ans: "<<ans<<endl;
	dp2[T]=1;
	for(int i=n;i>=1;i--)
	{
		int u=ord[i];
		if(dis[u]==half)
		{
			//cout<<"subtracted point "<<u<<','<<dp[u]*dp2[u]<<' '<<dp[u]*dp2[u]%MOD<<endl;
			ans-=dp[u]*dp[u]%MOD*dp2[u]%MOD*dp2[u]%MOD;
			ans%=MOD;
			if(ans<0)ans+=MOD;
		}
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(dis[u]==dis[tmp->v]+tmp->w)
			{
				//cout<<u<<' '<<tmp->v<<' '<<dis[u]<<' '<<dis[tmp->v]<<endl;
				if(dis[u]>half&&dis[tmp->v]<half)
				{
					//cout<<"subtracted "<<u<<" to "<<tmp->v<<endl;
					ans-=dp[tmp->v]*dp[tmp->v]%MOD*dp2[u]%MOD*dp2[u]%MOD;
					ans%=MOD;
					if(ans<=0)ans+=MOD;
				}
				dp2[tmp->v]+=dp2[u];
				dp2[tmp->v]%=MOD;
			}
		}
	}
	//for(int i=1;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	//for(int i=1;i<=n;i++)cout<<dp2[i]<<' ';cout<<endl;
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}