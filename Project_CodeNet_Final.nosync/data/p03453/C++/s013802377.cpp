#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<utility>
#include<queue>
#define fi first
#define se second
#define MK(a,b) make_pair((a),(b))
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1e9+7;
typedef pair<ll,int> pii;
inline void MOD(int &x) {if (x>=mod) x-=mod;}


int n,m;
int hd[N],pr[N*4],to[N*4],len[N*4],tot;
void addedge(int u,int v,int d) {to[++tot]=v;pr[tot]=hd[u];len[tot]=d;hd[u]=tot;}



ll ds[N],dt[N];
int S,T,fs[N],ft[N],q[N],hh,tt;
bool b[N];

void work(int S,ll *dis,int *f)
{
	for (int i=1;i<=n;i++) dis[i]=1e15,b[i]=false;
	dis[S]=0;
	priority_queue< pii ,vector< pii >,greater< pii > > heap;
	heap.push(MK(dis[S],S));
	hh=1,tt=0;
	while (!heap.empty()) 
	{
		pii t=heap.top();heap.pop();
		int u=t.se;
		if (b[u]) continue;b[u]=true;
		q[++tt]=u;
		for (int i=hd[u];i;i=pr[i]) if (dis[to[i]]>dis[u]+len[i]) 
		{
			dis[to[i]]=dis[u]+len[i];
			heap.push(MK(dis[to[i]],to[i]));
		}
	}

	f[S]=1;
	for (int u,k=1;k<=n;k++) 
	{
		u=q[k];
		for (int i=hd[u];i;i=pr[i]) if (dis[to[i]]==dis[u]+len[i]) MOD(f[to[i]]+=f[u]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	for (int u,v,d,i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&u,&v,&d);
		addedge(u,v,d);
		addedge(v,u,d);
	}

	work(S,ds,fs);
	work(T,dt,ft);
	
	//for (int i=1;i<=n;i++) printf("fs=%d ds=%lld ft=%d dt=%lld\n",fs[i],ds[i],ft[i],dt[i]);
	
	
	int ans=(ll)fs[T]*fs[T]%mod;ll tm=ds[T]>>1;;
	//printf("%d\n",ans);
	if (tm+tm==ds[T]) 
	{
		for (int i=1;i<=n;i++) 
		if (ds[i]==tm&&dt[i]==tm) ans=((ll)ans-(ll)fs[i]*fs[i]%mod*ft[i]%mod*ft[i]%mod+mod)%mod;
	}

	for (int u,v,i=1;i<=m*2;i+=2) 
	{
		u=to[i],v=to[i+1];
		if (ds[u]>ds[v]) swap(u,v);
		if (ds[u]+dt[v]+len[i]!=ds[T]) continue;
		if (ds[u]<tm&&ds[v]>tm) 
		ans=((ll)ans-(ll)fs[u]*fs[u]%mod*ft[v]%mod*ft[v]%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}