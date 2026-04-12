#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,op,ed,x,y,z,vis[100010],g[100010][2],dis[100010][2],id,first[100010],Next[400010],to[400010],w[400010],index_,ans,U[200010],V[200010],W[200010];
void add(int a,int b,int c)
{
	Next[++index_]=first[a];
	first[a]=index_;
	to[index_]=b;
	w[index_]=c;
}
int Read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
void dij(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i][id]=99999999999999;
	dis[st][id]=0;
	g[st][id]=1;
	q.push(make_pair(0,st));
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=first[u];i;i=Next[i])
		{
			int v=to[i];
			if(dis[v][id]==dis[u][id]+w[i])
			{
				g[v][id]=(g[v][id]+g[u][id])%mod;
			}
			if(dis[v][id]>dis[u][id]+w[i])
			{
				dis[v][id]=dis[u][id]+w[i];
				g[v][id]=g[u][id];
				q.push(make_pair(dis[v][id],v));
			}
		}
	}
}
signed main()
{
	n=Read(),m=Read(),op=Read(),ed=Read();
	for(int i=1;i<=m;i++) U[i]=x=Read(),V[i]=y=Read(),W[i]=z=Read(),add(x,y,z),add(y,x,z);
	dij(op);
	id++;
	dij(ed);
	ans=((g[ed][0]%mod)*(g[ed][0]%mod))%mod;
	for(int i=1;i<=n;i++)
	{
		if(dis[i][0]==dis[i][1]&&dis[i][0]+dis[i][1]==dis[ed][0])
		{
			ans=ans-(((g[i][0]*g[i][1]%mod)*(g[i][0]*g[i][1]%mod))%mod);
	        ans=(ans+mod)%mod;
		}
	}
    for(int i=1;i<=m;i++)
    {
    	int u=U[i],v=V[i],d=W[i];
    	if(dis[u][0]+d+dis[v][1]==dis[ed][0]&&dis[u][0]+d>dis[v][1]&&dis[v][1]+d>dis[u][0])
		ans=ans-(((g[u][0]*g[v][1]%mod)*(g[v][1]*g[u][0]%mod))%mod),ans=(ans+mod)%mod;
        u=V[i],v=U[i],d=W[i];
    	if(dis[u][0]+d+dis[v][1]==dis[ed][0]&&dis[u][0]+d>dis[v][1]&&dis[v][1]+d>dis[u][0])
		ans=ans-(((g[u][0]*g[v][1]%mod)*(g[v][1]*g[u][0]%mod))%mod),ans=(ans+mod)%mod;
    }
	cout<<ans;
	return 0;
}