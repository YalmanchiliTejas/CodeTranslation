#include<bits/stdc++.h>
using namespace std;
long long n,m,s,t,tot,ans,u,v,d,a[200001],b[200001],c[200001],head[100001],nxt[400001];
long long mod=1e9+7,to[400001],w[400001],dis1[100001],dis2[100001],g1[100001],g2[100001];
bool v1[100001],v2[100001];
inline long long read()
{
   long long sum=0,x=1;
   char ch=getchar();
   while (ch<'0'||ch>'9')
   {
       if (ch=='-')
	     x=-1;
	   ch=getchar();
   }
   while (ch>='0'&&ch<='9')
   {
   	   sum=sum*10+ch-'0';
	   ch=getchar();
   }
   return sum*x;
}
inline void write(long long x)
{
    if (x<0)
	{
        putchar('-');
        x=-x;
    }
    if (x>9)
      write(x/10);
    putchar(x%10+'0');
    return;
}
inline void add(int u,int v,int d)
{
    nxt[++tot]=head[u];
	to[tot]=v;w[tot]=d;
	head[u]=tot;
}
inline void dijkstra(long long*d,long long*g,bool*v,int s)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
	d[s]=0ll;
    q.push(pair<long long,int>(0ll,s));
    g[s]=1;
    while (!q.empty())
	{
        pair<long long,int>sr=q.top();
		q.pop();
        int u=sr.second;
		long long du=sr.first;
        if (v[u]||d[u]<du)
		  continue;
        v[u]=1;
        for (register int i=head[u];i;i=nxt[i])
		{
            if (d[to[i]]==du+w[i])
              g[to[i]]=(g[to[i]]+g[u])%mod;
            if (d[to[i]]>du+w[i])
            {
            	g[to[i]]=g[u];
                d[to[i]]=du+w[i];
				q.push(pair<long long,int>(d[to[i]],to[i]));
			}
        }
    }
}
int main()
{
    n=read();m=read(); 
    s=read();t=read();
    for (register int i=1;i<=m;++i)
    {
        u=read();v=read();d=read();
        add(u,v,d);
        add(v,u,d);
        a[i]=u;b[i]=v;c[i]=d;
	}
    memset(dis1,127,sizeof(dis1));
	memset(dis2,127,sizeof(dis2));
    dijkstra(dis1,g1,v1,s);
    dijkstra(dis2,g2,v2,t);
    long long dis=dis1[t];
    ans=g1[t]*g1[t]%mod;
    for (register int i=1;i<=n;++i)
      if (dis1[i]+dis2[i]==dis&&dis1[i]==dis2[i])
        ans=(ans-g1[i]*g1[i]%mod*g2[i]%mod*g2[i]%mod)%mod;
    for (register int i=1;i<=m;++i)
	{
        u=a[i];v=b[i];d=c[i];
        if (dis1[u]+d+dis2[v]==dis&&dis1[u]+d>dis2[v]&&dis2[v]+d>dis1[u])
          ans=(ans-g1[u]*g2[v]%mod*g1[u]%mod*g2[v]%mod)%mod;
        u=b[i],v=a[i],d=c[i];
        if (dis1[u]+d+dis2[v]==dis&&dis1[u]+d>dis2[v]&&dis2[v]+d>dis1[u])
          ans=(ans-g1[u]*g2[v]%mod*g1[u]%mod*g2[v]%mod)%mod;
    }
    write((ans%mod+mod)%mod);
    return 0;
}