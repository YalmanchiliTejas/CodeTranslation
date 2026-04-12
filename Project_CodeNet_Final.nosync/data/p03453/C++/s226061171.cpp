#include<cstdio>
#include<queue>
#include<cstring>
#define MN 200005
using namespace std;
typedef long long ll;
int n,m,num,S,T,head[MN],x[MN],y[MN];
bool vis[MN];
const int mod=1e9+7;
ll d1[MN],d2[MN],v[MN],f1[MN],f2[MN];
struct edge{int to,next;ll w;}g[MN<<1];
struct node{
	int x;ll y;
	friend bool operator<(node x,node y){return x.y>y.y;}
};
priority_queue<node> q;
void dij(ll *d,ll *f,int u){
	memset(vis,0,sizeof(vis));
	d[u]=0;f[u]=1;q.push((node){u,0});
	while(!q.empty()){
		node tmp=q.top();q.pop();if(vis[tmp.x]||tmp.y>d[tmp.x])continue;vis[tmp.x]=1;
		for(int i=head[tmp.x];i;i=g[i].next)
			if(d[g[i].to]>d[tmp.x]+g[i].w)f[g[i].to]=f[tmp.x],q.push((node){g[i].to,d[g[i].to]=d[tmp.x]+g[i].w});
			else if(d[g[i].to]==d[tmp.x]+g[i].w)f[g[i].to]+=f[tmp.x],f[g[i].to]%=mod;
	}
}
void ins(int u,int v,ll w){g[++num].next=head[u];head[u]=num;g[num].to=v;g[num].w=w;}
void dec(ll &x,ll y){(x-=y)<0?(x+=mod):0;}
int main(){
//	freopen("03.in","r",stdin);
//	freopen("03.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&x[i],&y[i],&v[i]),ins(x[i],y[i],v[i]),ins(y[i],x[i],v[i]);
	memset(d1,0x3f,sizeof(d1));memset(d2,0x3f,sizeof(d2));
	dij(d1,f1,S);dij(d2,f2,T);ll ans=f1[T]*f1[T]%mod;
	for(int i=1;i<=n;i++)if(d1[i]+d2[i]==d1[T]&&d1[i]==d2[i])dec(ans,f1[i]*f2[i]%mod*f1[i]%mod*f2[i]%mod);
	for(int i=1;i<=m;i++){
		if(d1[x[i]]+d2[y[i]]+v[i]==d1[T]&&(d1[x[i]]+v[i]>d2[y[i]]&&d2[y[i]]+v[i]>d1[x[i]]))dec(ans,f1[x[i]]*f2[y[i]]%mod*f1[x[i]]%mod*f2[y[i]]%mod);
		if(d1[y[i]]+d2[x[i]]+v[i]==d1[T]&&(d1[y[i]]+v[i]>d2[x[i]]&&d2[x[i]]+v[i]>d1[y[i]]))dec(ans,f1[y[i]]*f2[x[i]]%mod*f1[y[i]]%mod*f2[x[i]]%mod);
	}printf("%lld\n",((ans%mod)+mod)%mod);
}