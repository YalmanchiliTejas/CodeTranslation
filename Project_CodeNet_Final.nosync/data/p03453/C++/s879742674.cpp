#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxm 200005
typedef long long ll;
typedef pair<ll,int> pii;
#define mp make_pair
#define ff first
#define ss second
const int mod=1e9+7;

int n,m,s,t;
bool can[maxn];

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

struct graph{
	bool vis[maxn]; ll dis[maxn];
	int tot,now[maxn],pre[maxm*2],son[maxm*2],val[maxm*2],f[maxn]; pii heap[maxn];
	void add(int a,int b,int c){son[++tot]=b,pre[tot]=now[a],now[a]=tot,val[tot]=c;}
	void link(int a,int b,int c){add(a,b,c),add(b,a,c);}
	void dijkstra(int x){
		memset(dis,63,sizeof(dis)),dis[x]=0,f[x]=1;
		int top=0; heap[++top]=mp(dis[x],x),make_heap(heap+1,heap+top+1,greater<pii>());
		while (top){
			pii x=heap[1]; pop_heap(heap+1,heap+top+1,greater<pii>()),--top; ll d=x.ff; int id=x.ss,v=f[id];
			if (vis[id]) continue; vis[id]=1;
			for (int p=now[id];p;p=pre[p]){
				if (dis[son[p]]>d+val[p]){
					f[son[p]]=v;
					heap[++top]=mp(dis[son[p]]=d+val[p],son[p]);
					push_heap(heap+1,heap+top+1,greater<pii>());
				}
				else if (dis[son[p]]==d+val[p]) f[son[p]]=(f[son[p]]+v)%mod;
			}
		}
	}
}g1,g2;

struct edge{int x,y,z;}e[maxm];

int main(){
	n=read(),m=read(),s=read(),t=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		e[i]=(edge){x,y,z};
		g1.link(x,y,z),g2.link(x,y,z);
	}
	g1.dijkstra(s),g2.dijkstra(t);
	int ans=1ll*g1.f[t]*g1.f[t]%mod; ll all=g1.dis[t];
	if (~all&1){
		for (int i=1;i<=n;i++)
			if (i!=s&&i!=t&&g1.dis[i]+g2.dis[i]==all&&g1.dis[i]==g2.dis[i])
				ans=(ans-1ll*g1.f[i]*g2.f[i]%mod*g1.f[i]%mod*g2.f[i])%mod;
	}
	for (int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		ll d1=g1.dis[x]+g2.dis[y]+z,d2=g1.dis[y]+g2.dis[x]+z;
		if (d1==all&&max(g1.dis[x],g2.dis[y])*2<all) ans=(ans-1ll*g1.f[x]*g2.f[y]%mod*g1.f[x]%mod*g2.f[y])%mod;
		if (d2==all&&max(g2.dis[x],g1.dis[y])*2<all) ans=(ans-1ll*g2.f[x]*g1.f[y]%mod*g2.f[x]%mod*g1.f[y])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}
