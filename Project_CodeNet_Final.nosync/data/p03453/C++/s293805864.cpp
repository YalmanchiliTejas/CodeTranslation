#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,M=200005,Mod=1e9+7;
int n,m,S,T,edgenum,X[M],Y[M],Z[M],head[N],Next[M*2],vet[M*2],val[M*2];
ll ans,d1[N],d2[N],g1[N],g2[N];
bool vis[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
void add(int u,int v,int w){
	edgenum++;
	Next[edgenum]=head[u];
	vet[edgenum]=v;
	val[edgenum]=w;
	head[u]=edgenum;
}
void dij(ll*d,ll*g,int s){
	d[s]=0,g[s]=1;
	que.push(make_pair(0,s));
	while(!que.empty()){
		int u=que.top().second;
		ll w=que.top().first;
		que.pop();
		if(vis[u]||d[u]<w)continue;
		vis[u]=1;
		for(int i=head[u];i;i=Next[i]){
			int v=vet[i];
			if(d[v]==w+val[i])g[v]=(g[v]+g[u])%Mod;
			if(d[v]>w+val[i]){
				g[v]=g[u];
				d[v]=w+val[i];
				que.push(make_pair(d[v],v));
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		X[i]=x,Y[i]=y,Z[i]=z;
	} 
	memset(d1,0x3f,sizeof d1);
	memset(d2,0x3f,sizeof d2);
	dij(d1,g1,S);
	memset(vis,0,sizeof(vis));
	dij(d2,g2,T);
	ll dis=d1[T];
	ans=g1[T]*g1[T]%Mod;
	for(int i=1;i<=n;i++)
		if(d1[i]+d2[i]==dis&&d1[i]==d2[i])
			ans=(ans-g1[i]*g1[i]%Mod*g2[i]%Mod*g2[i]%Mod)%Mod;
	for(int i=1;i<=m;i++){
		int u=X[i],v=Y[i],d=Z[i];
		if(d1[u]+d+d2[v]==dis&&d1[u]+d>d2[v]&&d2[v]+d>d1[u])
			ans=(ans-g1[u]*g2[v]%Mod*g1[u]%Mod*g2[v]%Mod)%Mod;
		u=Y[i],v=X[i],d=Z[i];
		if(d1[u]+d+d2[v]==dis&&d1[u]+d>d2[v]&&d2[v]+d>d1[u])
			ans=(ans-g1[u]*g2[v]%Mod*g1[u]%Mod*g2[v]%Mod)%Mod;
	}
	printf("%lld",(ans%Mod+Mod)%Mod);
	return 0;
}