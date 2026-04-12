#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
typedef long long ll;
const ll MAXN=1e5+5,MAXM=2e5+5,P=1e9+7;
 
ll N,M,S,T;
 
struct E{ll next,to,val;} e[MAXM<<1];ll ecnt,G[MAXN];
void addEdge(ll u,ll v,ll w){e[++ecnt]=(E){G[u],v,w};G[u]=ecnt;}
void addEdge2(ll u,ll v,ll w){addEdge(u,v,w);addEdge(v,u,w);}
 
ll fS[MAXN],dS[MAXN],fT[MAXN],dT[MAXN];
 
struct HN{ll id,v;};
bool operator <(const HN &a,const HN &b){return a.v>b.v;}
std::priority_queue<HN> heap;
bool inS[MAXN];
void dijkstra(ll v0,ll *f,ll *d)
{
	memset(inS,0,sizeof inS);
	memset(d,0x3f,sizeof dS);
	d[v0]=0,f[v0]=1;heap.push((HN){v0,0});
	while(!heap.empty())
	{
		ll u=heap.top().id;heap.pop();
		if(inS[u]) continue;inS[u]=true;
		for(ll i=G[u];i;i=e[i].next)
		{
			ll v=e[i].to;
			if(inS[v]) continue;
			if(d[v]>d[u]+e[i].val)
			{
				f[v]=f[u];
				d[v]=d[u]+e[i].val;
				heap.push((HN){v,d[v]});
			}
			else if(d[v]==d[u]+e[i].val) f[v]=(f[v]+f[u])%P;
		}
	}
}
 
struct A{ll u,v,w;} a[MAXM];
int main()
{
	ll i;scanf("%d%d%d%d",&N,&M,&S,&T);
	for(i=1;i<=M;i++)
	{
		ll u,v,w;scanf("%d%d%d",&u,&v,&w);
		addEdge2(u,v,w);a[i]=(A){u,v,w};
	}
	dijkstra(S,fS,dS);
	dijkstra(T,fT,dT);
	ll ans=(ll)fS[T]*fS[T]%P;
	for(i=1;i<=N;i++)
		if(dS[i]==dT[i]&&dS[i]+dT[i]==dS[T])
			ans=(ans+P-(ll)fS[i]*fS[i]%P*fT[i]%P*fT[i]%P)%P;
	for(i=1;i<=M;i++)
	{
		ll u=a[i].u,v=a[i].v,w=a[i].w;
		if(dS[u]>dS[v]) std::swap(u,v);
		//if(dS[u]<dS[T]>>1&&dT[v]<dT[S]>>1&&dS[u]+dT[v]+w==dS[T])
		if(dS[u]+dT[v]+w==dS[T]&&std::max(dS[u],dT[v])<std::min(dS[u],dT[v])+w)
			ans=(ans+P-(ll)fS[u]*fS[u]%P*fT[v]%P*fT[v]%P)%P;
	}
	printf("%d",ans);
	return 0;
}
