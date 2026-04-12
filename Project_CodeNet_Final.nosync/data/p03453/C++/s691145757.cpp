#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
const int mod=1000000007;
int n,m;
int s,t;
int box[100005],las[400005],edv[400005],edw[400005],cnt=0;
void adde(int u,int v,int w)
{
	las[++cnt]=box[u];
	box[u]=cnt;
	edv[cnt]=v;
	edw[cnt]=w;
}
long long dis1[100005],cnt1[100005],dis2[100005],cnt2[100005],diss[100005];
bool vis[100005];
queue<int>q;
int id[100005];
void spfa(int s,long long* dis,long long* cnt)
{
	memset(dis,23,8*n+8);
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int now=q.front();
		vis[now]=0;
		q.pop();
		for(int i=box[now];i;i=las[i])
		{
			int v=edv[i];
			if(dis[v]>dis[now]+edw[i])
			{
				dis[v]=dis[now]+edw[i];
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		id[i]=i;
		diss[i]=dis[i];
	}
	sort(id+1,id+1+n,([](int a,int b){return diss[a]<diss[b];}));
	cnt[s]=1;
	for(int j=1;j<=n;j++)
		for(int i=box[id[j]];i;i=las[i])
			if(dis[edv[i]]==dis[id[j]]+edw[i])
				cnt[edv[i]]=(cnt[edv[i]]+cnt[id[j]])%mod;
}
int main()
{
	read(n);
	read(m);
	read(s);
	read(t);
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		read(a);
		read(b);
		read(c);
		adde(a,b,c);
		adde(b,a,c);
	}
	spfa(s,dis1,cnt1);//cout<<"EM"<<endl;
//	for(int i=1;i<=n;i++)	cout<<i<<' '<<cnt1[i]<<endl;
	spfa(t,dis2,cnt2);
	long long gg=dis1[t];
	long long ans=(cnt1[t]*cnt1[t])%mod;//cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(dis1[i]==dis2[i] && dis1[i]+dis2[i]==gg)
			ans=(ans-((cnt1[i]*cnt2[i])%mod)*((cnt1[i]*cnt2[i])%mod))%mod;
		for(int j=box[i];j;j=las[j])
		{
			int v=edv[j];//cout<<dis1[i]<<' '<<dis2[v]<<' '<<edw[j]<<endl;
			if(dis1[i]+dis2[v]+edw[j]==gg && 2*dis1[i]<gg && 2*dis2[v]<gg)
				ans=(ans-((cnt1[i]*cnt2[v])%mod)*((cnt1[i]*cnt2[v])%mod))%mod;
		}
	}
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}