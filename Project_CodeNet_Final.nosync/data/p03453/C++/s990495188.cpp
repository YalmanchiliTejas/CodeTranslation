#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
using namespace std;
typedef long long LL;
typedef double db;
//char buf[1<<24],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
	if (x< 0) putchar('-'),x=-x;
	if (x>=10) print(x/10);
	putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
void del(int &x,int y) { x+=y; x=x>=P?x-P:x; }
struct EDGE { int v,w,nx; }lb[N<<1]; int top[N],tot;
void add (int u,int v,int w) { lb[++tot]=(EDGE){v,w,top[u]},top[u]=tot; }
#define pii pair<LL,int>
#define fi first
#define se second
#define mp make_pair
priority_queue <pii> q;
bool vis[N];
int n,m;
void dij (int s,LL *dis,int *an)
{
	memset (dis,63,sizeof (LL)*(n+1));
	memset (vis,0,sizeof (bool)*(n+1));
	dis[s]=0,q.push (mp(-dis[s],s));
	an[s]=1;
	while (q.size ())
	{
		int u=q.top ().se; q.pop ();
		if (vis[u]) continue;
		vis[u]=1;
		for (int kb=top[u]; kb; kb=lb[kb].nx)
		{
			int v=lb[kb].v,w=lb[kb].w;
			if (dis[v]> dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push (mp(-dis[v],v));
				an[v]=0;
			}
			if (dis[v]==dis[u]+w) del(an[v],an[u]);
		}
	}
}
int S(int A) { return (LL)A*A%P; }
LL dis[2][N];
int an[2][N];
int s,t;
int x[N],y[N],w[N];
int main ()
{
	// freopen (".in","r",stdin);
	// freopen (".out","w",stdout);
	sc(n),sc(m),sc(s),sc(t);
	for (int i=1; i<=m; i++)
	{
		sc(x[i]),sc(y[i]),sc(w[i]);
		add (x[i],y[i],w[i]),add (y[i],x[i],w[i]);
	}
	dij (s,dis[0],an[0]);
	dij (t,dis[1],an[1]);
	LL d=dis[0][t],d2=d>>1;
	int ans=(LL)an[0][t]*an[1][s]%P;
	if (!(d&1)) for (int i=1; i<=n; i++)
		if (dis[0][i]==d2) del(ans,P-S((LL)an[0][i]*an[1][i]%P));
	for (int i=m+1; i<=m<<1; i++)
		x[i]=y[i-m],y[i]=x[i-m],w[i]=w[i-m];
	m<<=1;
	for (int i=1; i<=m; i++)
		if (dis[0][x[i]]< d2&&dis[1][y[i]]< d2&&dis[0][x[i]]+dis[1][y[i]]+w[i]==d)
			del(ans,P-S((LL)an[0][x[i]]*an[1][y[i]]%P));
	pr(ans);
	return 0;
}
