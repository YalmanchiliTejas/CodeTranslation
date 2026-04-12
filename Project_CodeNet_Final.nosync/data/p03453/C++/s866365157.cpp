#include <bits/stdc++.h>
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
typedef long long ll;
const double eps=1e-16;
const int mod=1e9+7;
const int N=500005;
int n,m,head[N],now=0,S,T;
int tmpS[N],tmpT[N];
ll pathS[N],pathT[N];
using namespace std;

struct node
{
	int t,w,next;
}adj[N<<1];
void add(int s,int t,int w)
{
	adj[++now]=(node){t,w,head[s]};
	head[s]=now;
}
struct que
{
	int s;
	ll len;
};
bool operator<(que a,que b){return a.len>b.len;}
priority_queue<que> Q;
void dij(int st,ll *path,int *tmp)
{
	int i,s,t,w;
	for (i=1;i<=n;i++) path[i]=(1ll<<60);
	path[st]=0,tmp[st]=1;Q.push((que){st,0});
	que fr;
	while (!Q.empty())
	{
		fr=Q.top(),Q.pop();
		if (fr.len!=path[fr.s]) continue;
		s=fr.s;
		for (i=head[s];i;i=adj[i].next)
		{
			t=adj[i].t,w=adj[i].w;
			if (path[t]>path[s]+w)
			{
				path[t]=path[s]+w,tmp[t]=tmp[s];
				Q.push((que){t,path[t]});
			}
			else if (path[t]==path[s]+w) tmp[t]=(tmp[s]+tmp[t])%mod;
		}
	}
}
inline int read()
{
	char c;int x;
	while (c=getchar(),c<'0' || c>'9');x=c^'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x;
}
void write(int x)
{
	if (x==0) return;
	write(x/10);
	putchar((x%10)+'0');
}
//void upd(int& x,int y){if (x==-1) x=y;else x=max(x,y);}

int main()
{
	#ifdef Kay
		freopen ("code.in","r",stdin);
		freopen ("code.out","w",stdout);
	#endif
	scanf ("%d %d %d %d",&n,&m,&S,&T);
	int i,s,t,w;
	for (i=1;i<=m;i++)
	{
		scanf ("%d %d %d",&s,&t,&w);
		add(s,t,w),add(t,s,w);
	}
	dij(S,pathS,tmpS),dij(T,pathT,tmpT);
	//printf ("%lld %d\n",pathS[T],tmpS[T]);
	int ans=(ll)tmpS[T]*tmpS[T]%mod;
	int tmp=0;
	if (!(pathS[T]&1))
	{
		for (i=1;i<=n;i++)
		if ((pathS[i]<<1)==pathS[T])
		{
			int x=(ll)tmpS[i]*tmpT[i]%mod;
			x=(ll)x*x%mod;
			tmp=(tmp+x)%mod;
		}
	}
	for (s=1;s<=n;s++)
	for (i=head[s];i;i=adj[i].next)
	if (s<adj[i].t)
	{
		t=adj[i].t,w=adj[i].w;
		if (pathS[s]==pathS[t]) continue;
		int u=s,v=t;
		if (pathS[u]>pathS[v]) swap(u,v);
		if (pathS[u]+pathT[v]+adj[i].w!=pathS[T]) continue;
		if (pathS[u]*2<pathS[T] && pathS[v]*2>pathS[T])
		{
			int x=(ll)tmpS[u]*tmpT[v]%mod;
			x=(ll)x*x%mod;
			tmp=(tmp+x)%mod;
		}
	}
	tmp=mod-tmp;
	ans=(ans+tmp)%mod;
	cout<<ans;
	return 0;
}
