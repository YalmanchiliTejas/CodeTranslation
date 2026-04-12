#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 404000, mo = 1e9+7;
const ll inf = 1e16;
int n,m,s,t;
struct edge{int v,val;
	edge(int x=0, int y=0) {v=x; val=y;}
};
vector<edge> to[N],to1[N],to2[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll dis[N],f[N],g[N];
int q[N],seq[N];
bool exist[N];
bool cmp(int a, int b) {return dis[a]>dis[b];}
inline void inc(int &x) {x++; if (x==N) x=0;}
inline void spfa() {
	int f=0,r=1; q[f]=t; rep(i,0,n) dis[i]=inf; dis[t]=0;
	while (f!=r) {
		int u=q[f]; inc(f); exist[u]=0; int len=to[u].size();
		rep(i,0,len-1) if (dis[to[u][i].v]>dis[u]+to[u][i].val) {
			dis[to[u][i].v]=dis[u]+to[u][i].val;
			if (!exist[to[u][i].v]) {
				exist[to[u][i].v]=1; q[r]=to[u][i].v; inc(r);
			}
		}
	}
}
inline void dfs(int u) {
	exist[u]=1; int len=to[u].size();
	rep(i,0,len-1) if (dis[u]==dis[to[u][i].v]+to[u][i].val) {
		int v=to[u][i].v; to1[u].push_back(to[u][i]);
		to2[v].push_back(edge(u,to[u][i].val));
		if (!exist[v]) dfs(v);
	}
}
inline void dp() {
	f[s]=1; rep(v,1,n) {
		int u=seq[v],len=to1[u].size();
		rep(i,0,len-1) {(f[to1[u][i].v]+=f[u])%=mo; } //printf("%d %d\n",u,to1[u][i].v); 
	}
	g[t]=1; per(v,n,1) {
		int u=seq[v],len=to2[u].size();
		rep(i,0,len-1) (g[to2[u][i].v]+=g[u])%=mo;
	}
//	rep(i,1,n) printf("%lld %lld\n",f[i],g[i]);
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); read(s); read(t); int x,y,z;
	rep(i,1,m) {
		read(x);read(y);read(z); 
		to[x].push_back(edge(y,z)); to[y].push_back(edge(x,z));
	}
	spfa(); memset(exist,0,sizeof(exist)); dfs(s);
//	rep(i,1,n) printf("%lld ",dis[i]); puts("");
	rep(i,1,n) seq[i]=i; sort(seq+1,seq+n+1,cmp);
	dp(); ll ans=f[t]*f[t]%mo;
	rep(i,1,n) if (dis[i]*2==dis[s]) ans-=(f[i]*g[i]%mo)*(f[i]*g[i]%mo)%mo;
	rep(u,1,n) {
		int len=to1[u].size();
		rep(i,0,len-1) {
			int v=to1[u][i].v;
			if (dis[v]*2<dis[s]&&dis[u]*2>dis[s]) ans-=(f[u]*g[v]%mo)*(f[u]*g[v]%mo)%mo;
		}
	}
	printf("%lld",(ans%mo+mo)%mo);
	return 0;
}