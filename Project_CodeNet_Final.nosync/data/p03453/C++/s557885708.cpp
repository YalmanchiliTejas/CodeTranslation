// copied
#include<bits/stdc++.h>
#define ll long long
#define pa pair<ll,int>
#define mo 1000000007
#define N 100005
using namespace std;
ll ds[N],dt[N],ways[N],wayt[N];
struct edge{int to,next,v;}e[N*4];
int head[N],vis[N];
int n,m,s,t,tot,ans;
priority_queue<pa > q;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dijk_heap(int S,ll *dis,ll *way){
	for (int i=1;i<=n;i++)
		dis[i]=1e18,vis[i]=0,way[i]=0;
	dis[S]=0; way[S]=1;
	while (!q.empty()) q.pop();
	q.push(pa(0,S));
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue; vis[x]=1;
		for (int i=head[x];i;i=e[i].next){
			ll tmp=dis[x]+e[i].v;
			if (dis[e[i].to]>tmp){
				dis[e[i].to]=tmp;
				way[e[i].to]=0;
				q.push(pa(-tmp,e[i].to));
			}
			if (dis[e[i].to]==tmp)
				way[e[i].to]=(way[e[i].to]+way[x])%mo;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijk_heap(s,ds,ways);
	ans=1ll*ways[t]*ways[t]%mo;
	dijk_heap(t,dt,wayt);
	for (int i=1;i<=n;i++)
		if (ds[i]*2==ds[t]&&ds[i]+dt[i]==ds[t])
			ans=(ans+mo-1ll*ways[i]*ways[i]%mo*wayt[i]%mo*wayt[i]%mo)%mo;
	for (int x=1;x<=n;x++)
		for (int i=head[x];i;i=e[i].next)
			if (ds[x]+e[i].v+dt[e[i].to]==ds[t])
				if (ds[x]*2<ds[t]&&dt[e[i].to]*2<ds[t])
					ans=(ans+mo-1ll*ways[x]*wayt[e[i].to]%mo*ways[x]%mo*wayt[e[i].to]%mo)%mo;
	printf("%d\n",ans);
}
