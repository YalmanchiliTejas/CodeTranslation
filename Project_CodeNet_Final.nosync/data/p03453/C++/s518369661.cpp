#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 200010
#define ll long long
#define mod 1000000007
 
int n,m,S,T;
struct edge{int x,y,z,next;}e[maxn<<1];
int first[maxn],len=0;
void buildroad(int x,int y,int z){e[++len]=(edge){x,y,z,first[x]};first[x]=len;}
struct node{
	int x;ll d;node(int xx=0,ll yy=0):x(xx),d(yy){}
	bool operator<(const node &ANO)const{return d>ANO.d;}
};
void add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
priority_queue<node>q;
int v[maxn],f[maxn],g[maxn];
ll dis1[maxn],dis2[maxn];
void dij(int S,ll *dis,int *F)
{
	memset(dis,63,sizeof(dis1));
	memset(v,false,sizeof(v));
	q.push(node(S,0));dis[S]=0;F[S]=1;
	while(!q.empty())
	{
		int x=q.top().x;q.pop();if(v[x])continue;v[x]=true;
		for(int i=first[x];i;i=e[i].next)
		{
			int y=e[i].y;
			if(dis[y]>dis[x]+e[i].z)dis[y]=dis[x]+e[i].z,F[y]=F[x],q.push(node(y,dis[y]));
			else if(dis[y]==dis[x]+e[i].z)add(F[y],F[x]),q.push(node(y,dis[y]));
		}
	}
}
int ans=0;
void work()
{
	ll L=dis1[T];
	for(int i=1;i<=n;i++)if(dis1[i]+dis2[i]==L&&dis1[i]*2ll==L)
	add(ans,1ll*f[i]*g[i]%mod*(f[T]-1ll*f[i]*g[i]%mod+mod)%mod);
	for(int i=1;i<=len;i++)if(dis1[e[i].x]*2<L&&dis1[e[i].y]*2>L&&dis1[e[i].x]+e[i].z+dis2[e[i].y]==L)
	add(ans,1ll*f[e[i].x]*g[e[i].y]%mod*(f[T]-1ll*f[e[i].x]*g[e[i].y]%mod+mod)%mod);
}
 
int main()
{
	scanf("%d %d %d %d",&n,&m,&S,&T);for(int i=1,x,y,z;i<=m;i++)
	scanf("%d %d %d",&x,&y,&z),buildroad(x,y,z),buildroad(y,x,z);
	dij(S,dis1,f);dij(T,dis2,g);work();printf("%d",ans);
}