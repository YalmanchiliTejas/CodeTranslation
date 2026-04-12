#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define fs first
#define sc second
#define N 100010
#define M 200010
#define ll long long
using namespace std;
const int mod=1000000007;
int n,m,S,T,dl[20000010],u[M],v[M],w[M]; 
bool vis[N];
ll diss[N],dist[N],g[N],h[N],ans;
pair<ll,int> os[N],ot[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
struct edge
{
	int t;ll w;
	edge *next;
}*con[N];
void ins(int x,int y,int w)
{
	edge *p=new edge;
	p->t=y;
	p->w=w;
	p->next=con[x];
	con[x]=p;
}
void spfa(ll *dis,int s)
{
	dis[s]=0;dl[1]=s;//a[s]=1;
	for(int hd=1,tl=1,v=s;hd<=tl;vis[v]=0,v=dl[++hd])
		for(edge *p=con[v];p;p=p->next)
			if(dis[p->t]>dis[v]+p->w)
			{
				dis[p->t]=dis[v]+p->w;
				if(!vis[p->t]) dl[++tl]=p->t,vis[p->t]=1;
			}
			//else if(dis[p->t]==dis[v]+p->w) a[p->t]+=a[v];
}
void work(pair<ll,int> *o,ll *dis,ll *a)
{
	for(int i=1;i<=n;i++)
	{
		int v=o[i].sc;
		//cout<<v<<endl;
		for(edge *p=con[v];p;p=p->next)
			if(dis[v]+p->w==dis[p->t]) a[p->t]=(a[p->t]+a[v])%mod;
	}
}
int main()
{
	n=read();m=read();S=read();T=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		ins(u[i],v[i],w[i]);
		ins(v[i],u[i],w[i]);
	}
	memset(diss,0x3f,sizeof(diss));
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	spfa(diss,S);
	
	for(int i=1;i<=n;i++)
		os[i]=make_pair(diss[i],i);
	memset(vis,0,sizeof(vis));
	spfa(dist,T);
	for(int i=1;i<=n;i++)
		ot[i]=make_pair(dist[i],i);
	sort(os+1,os+n+1);
	sort(ot+1,ot+n+1);
	g[S]=1;h[T]=1;
//	cout<<"S:"<<endl;
	work(os,diss,g);
//	cout<<"T:"<<endl;
	work(ot,dist,h);
//	puts("diss:");
//	for(int i=1;i<=n;i++)
//		cout<<diss[i]<<' ';
//	puts("");
//	puts("dist:");
//	for(int i=1;i<=n;i++)
//		cout<<dist[i]<<' ';
//	puts("");	
//	puts("g:");
//	for(int i=1;i<=n;i++)
//		cout<<g[i]<<' ';
//	puts("");
//	puts("h:");
//	for(int i=1;i<=n;i++)
//		cout<<h[i]<<' ';
//	puts("");
	for(int i=1;i<=n;i++)
	{
		for(edge *p=con[i];p;p=p->next)
			if(diss[i]+dist[p->t]+p->w==diss[T]&&abs(diss[i]-dist[p->t])<p->w) ans=(ans+g[i]*g[i]%mod*h[p->t]%mod*h[p->t]%mod)%mod;
		if(diss[i]==dist[i]) ans=(ans+g[i]*g[i]%mod*h[i]%mod*h[i]%mod)%mod;
	}
	//cout<<g[T]*h[S]<<' '<<ans<<endl;
	ans=(g[T]*h[S]%mod-ans+mod)%mod;
	printf("%lld",ans);		
	return 0;
}
/*4 5
1 4 
1 2 1
2 3 1
3 4 1
1 3 2
2 4 2*/