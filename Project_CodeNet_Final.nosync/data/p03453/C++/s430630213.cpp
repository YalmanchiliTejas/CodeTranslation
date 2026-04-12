#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define mod 1000000007
#define MN 100005
using namespace std;
struct node
{
	ll val; int pos;
	friend bool operator<(const node& a,const node& b) {return a.val>b.val;}
};
struct edge{int nex,to,wt;}e[MN<<2];
struct bian{int x,y,z;}b[MN<<1];
priority_queue <node> q;
ll dis[2][MN];
int hr[MN],gs[2][MN];
int n,m,S,T,sm,ans,pin;

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

inline void ins(int x,int y,int z) {e[++pin]=(edge){hr[x],y,z}; hr[x]=pin;}
inline void rw(int& x,int y) {x+=y; if (x>=mod) x-=mod;}
inline void rd(int& x,int y) {x-=y; if (x< 0  ) x+=mod;}

void dijk(int SS,bool g)
{
	register int i,x;
	memset(dis[g],100,sizeof(dis[g]));
	dis[g][SS]=0; gs[g][SS]=1; q.push((node){dis[g][SS],SS});
	while (!q.empty())
	{
		while (!q.empty()&&dis[g][q.top().pos]!=q.top().val) q.pop();
		if (q.empty()) break;
		for (x=q.top().pos,q.pop(),i=hr[x];i;i=e[i].nex)
			if (dis[g][x]+e[i].wt<dis[g][e[i].to])
				dis[g][e[i].to]=dis[g][x]+e[i].wt,
				gs[g][e[i].to]=gs[g][x],q.push((node){dis[g][e[i].to],e[i].to});
			else if (dis[g][x]+e[i].wt==dis[g][e[i].to])
				rw(gs[g][e[i].to],gs[g][x]);
	}
}

int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	register int i,x,y,z;
	n=read(); m=read(); S=read(); T=read();
	for (i=1;i<=m;++i)
		b[i].x=x=read(),b[i].y=y=read(),b[i].z=z=read(),
		ins(x,y,z),ins(y,x,z);
	dijk(S,0); dijk(T,1);
	ans=1LL*(gs[0][T])*(gs[0][T]-1)%mod;
	for (i=1;i<=n;++i)
		if (dis[0][i]+dis[1][i]==dis[0][T]&&dis[0][i]==dis[1][i])
			sm=1LL*gs[0][i]*gs[1][i]%mod,
			rd(ans,1LL*sm*(sm-1)%mod);
	for (i=1;i<=m;++i)
		if (dis[0][b[i].x]+dis[1][b[i].y]+b[i].z==dis[0][T])
		{
			if (dis[0][b[i].x]*2<dis[0][T]&&dis[1][b[i].y]*2<dis[0][T])
				sm=1LL*gs[0][b[i].x]*gs[1][b[i].y]%mod,
				rd(ans,1LL*sm*(sm-1)%mod);
		}
		else if (dis[1][b[i].x]+dis[0][b[i].y]+b[i].z==dis[0][T])
		{
			if (dis[1][b[i].x]*2<dis[0][T]&&dis[0][b[i].y]*2<dis[0][T])
				sm=1LL*gs[1][b[i].x]*gs[0][b[i].y]%mod,
				rd(ans,1LL*sm*(sm-1)%mod);
		}
	printf("%d",ans);
}