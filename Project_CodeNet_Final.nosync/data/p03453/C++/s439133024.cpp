#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int N=200009;
const int M=400009;
const int md=1e9+7;

typedef long long ll;
typedef pair<ll,ll> pr;

int n,m,s,t,a[N],b[N];
ll c[N];
bool on[M<<1];
inline bool chkmin(ll &a,ll b){if(a>b){a=b;return 1;}return 0;}

struct graph
{
	int to[M<<1],nxt[M<<1],frm[M<<1],beg[N],tot;
	int id[N],deg[N];
	bool inq[N];
	ll f[N],dis[N],w[M<<1];

	inline void add(int u,int v,ll c)
	{
		to[++tot]=v;
		nxt[tot]=beg[u];
		frm[tot]=u;
		w[tot]=c;
		beg[u]=tot;
		++deg[v];
	}

	inline void spfa(int s)
	{
		queue<int> q;
		memset(dis,127,sizeof(dis));
		q.push(s);dis[s]=0;
		while(!q.empty())
		{
			int u=q.front();q.pop();inq[u]=0;
			for(int i=beg[u],v;i;i=nxt[i])
				if(dis[v=to[i]]>dis[u]+w[i])
				{
					dis[v]=dis[u]+w[i];
					if(!inq[v])inq[v]=1,q.push(v);
				}
		}
	}

	inline void dp(int s)
	{
		queue<int> q;
		q.push(s);f[s]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=beg[u];i;i=nxt[i])
			{
				(f[to[i]]+=f[u])%=md;
				if(!(--deg[to[i]]))
					q.push(to[i]);
			}
		}
	}
}g1,g2,g3,g4;

inline ll sqr(ll a){return a*a%md;}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&a[i],&b[i],&c[i]);c[i]%=md;
		g1.add(a[i],b[i],c[i]);g1.add(b[i],a[i],c[i]);
		g2.add(a[i],b[i],c[i]);g2.add(b[i],a[i],c[i]);
	}
	
	g1.spfa(s);g2.spfa(t);
	for(int i=1;i<=m;i++)
		if(g1.dis[a[i]]+c[i]+g2.dis[b[i]]==g1.dis[t])
		{
			g3.add(a[i],b[i],c[i]);on[i]=1;
			g4.add(b[i],a[i],c[i]);
		}
		else if(g1.dis[b[i]]+c[i]+g2.dis[a[i]]==g1.dis[t])
		{
			swap(a[i],b[i]);on[i]=1;
			g3.add(a[i],b[i],c[i]);
			g4.add(b[i],a[i],c[i]);
		}
	g3.dp(s);g4.dp(t);

	ll ans=sqr(g3.f[t]);
	for(int i=1;i<=m;i++)
		if(on[i] && g1.dis[a[i]]*2ll<g1.dis[t] && g2.dis[b[i]]*2ll<g1.dis[t])
			ans=(ans-sqr(g3.f[a[i]])*sqr(g4.f[b[i]])%md+md)%md;
	
	for(int i=1;i<=n;i++)
		if(g1.dis[i]*2ll==g1.dis[t])
			ans=(ans-sqr(g3.f[i])*sqr(g4.f[i])%md+md)%md;

	printf("%lld\n",(ans%md+md)%md);
	return 0;
}
