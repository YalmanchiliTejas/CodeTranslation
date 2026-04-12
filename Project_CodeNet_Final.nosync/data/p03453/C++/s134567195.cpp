#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
ll read()
{
	char s;
	ll k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if(s==EOF)exit(0);if(s=='-')base=-1,s=getchar();
	while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
	return k*base;
}
void write(int x)
{
	if(x<0){putchar('-');write(-x);}
	else{if(x/10)write(x/10);putchar(x%10+'0');}
}
const int maxn=101000;
const int maxm=201000;
int n,m,s,t,X,Y;
ll Z;
int to[maxm<<1],ne[maxm<<1];
ll w[maxm<<1];
int po[maxn],id;
ll dis[maxn],d[maxn];
const ll mod=1e9+7;
ll dp[maxn],f[maxn];
void add(int x,int y,ll z)
{
	id++;
	to[id]=y;
	w[id]=z;
	ne[id]=po[x];
	po[x]=id;
}
struct node
{
	ll x; 
	int d;
	bool operator < (const node &a) const 
	{
		return x>a.x;
	}
} e;
ll ans;
priority_queue<node> q;
int main()
{
	id=1;
	n=read();m=read();s=read();t=read();
	for (int i=1;i<=m;i++)
	{
		X=read();Y=read();Z=read();
		add(X,Y,Z);add(Y,X,Z);
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	e.d=s;
    e.x=0;
    q.push(e);
    dp[s]=1;
	while (!q.empty())
	{
		e=q.top();q.pop();
		int u=e.d,v;
		if (e.x>dis[u]) continue;
		for (int i=po[u];i;i=ne[i])
		{
			v=to[i];
			if ((dis[u]+w[i]==dis[v]))
			{
				dp[v]+=dp[u];
				if (dp[v]>=mod) dp[v]-=mod;
			}
			if (dis[u]+w[i]<dis[v])
			{
				dis[v]=dis[u]+w[i];
				dp[v]=dp[u];
				e.d=v;
				e.x=dis[v];
				q.push(e);
			}
		
		}
	}
	
	memset(d,0x3f3f3f3f,sizeof(d));
//	cout<<d[0];
	d[t]=0;
	e.d=t;
    e.x=0;
    q.push(e);
    f[t]=1;
	while (!q.empty())
	{
		e=q.top();q.pop();
		int u=e.d,v;
		if (e.x>d[u]) continue;
		for (int i=po[u];i;i=ne[i])
		{
			v=to[i];
			if ((d[u]+w[i]==d[v]))
			{
				f[v]+=f[u];
				if (f[v]>=mod) f[v]-=mod;
			}
			if (d[u]+w[i]<d[v])
			{
				d[v]=d[u]+w[i];
				f[v]=f[u];
				e.d=v;
				e.x=d[v];
				q.push(e);
			}
		
		}
	}	
	
	ans=dp[t]*dp[t]%mod;
//	cout<<ans;
	for (int i=1;i<=n;i++)
	{
		if (dis[i]+d[i]!=dis[t]) continue;
		if (dis[i]==d[i])
		{
			ans-=dp[i]*dp[i]%mod*f[i]%mod*f[i]%mod;
//			cout<<ans<<endl;
			ans%=mod;
		} else
		if (dis[i]*2<dis[t])
		{
			for (int j=po[i];j;j=ne[j])
			{
				if (dis[to[j]]+d[to[j]]!=dis[t]) continue;
				if (dis[i]+w[j]==dis[to[j]]&&dis[i]+w[j]+d[to[j]]==dis[t]&&dis[to[j]]*2>dis[t])
				{
					ans-=dp[i]*f[to[j]]%mod*dp[i]%mod*f[to[j]]%mod;
					ans%=mod;
				}
			}
		}
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans;
	return 0;
} 