#include<queue>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=100000,mod=1000000007;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,s,t,ans; queue<int> q;
struct hnode{
	int id; ll v;
	bool operator<(const hnode &t)const{
		return v>t.v;
	}
};
struct edge{int to,len;};
priority_queue<hnode> hp;
struct graph{
	vector<edge> g[maxn+10]; ll dis[maxn+10]; int dz[maxn+10],f[maxn+10];
	vector<edge> z[maxn+10];
	void add(int u,int v,int w){
		g[u].push_back((edge){v,w});
		g[v].push_back((edge){u,w});
	}
	void dijkstra(int s){
		for(int i=1;i<=n;++i) dis[i]=i==s?0:inf;
		hp.push((hnode){s,0});
		for(;!hp.empty();){
			hnode x=hp.top(); hp.pop(); if(x.v>dis[x.id]) continue;
			for(int i=0;i<g[x.id].size();++i){
				edge e=g[x.id][i];
				if(x.v+e.len<dis[e.to]){
					dis[e.to]=x.v+e.len; hp.push((hnode){e.to,dis[e.to]});
				}
			}
		}
	}
	void addeg(int u,int v,int w){z[u].push_back((edge){v,w}); ++dz[v];}
	void buildnew(){
		for(int i=1;i<=n;++i)
			for(int j=0;j<g[i].size();++j){
				edge e=g[i][j]; if(dis[i]+e.len==dis[e.to]) addeg(i,e.to,e.len);
			}
	}
	void topsort(int s){
		f[s]=1; for(int i=1;i<=n;++i) if(!dz[i]) q.push(i);
		for(;!q.empty();q.pop()){
			int x=q.front();
			for(int i=0;i<z[x].size();++i){
				int e=z[x][i].to; (f[e]+=f[x])%=mod;
				if(!--dz[e]) q.push(e);
			}
		}
	}
}g,rg;
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i){
		int l,r,w; scanf("%d%d%d",&l,&r,&w);
		g.add(l,r,w); rg.add(l,r,w);
	}
	g.dijkstra(s); rg.dijkstra(t); 
	g.buildnew(); rg.buildnew(); 
	ll d=g.dis[t];
	g.topsort(s); rg.topsort(t); ans=1ll*g.f[t]*rg.f[s]%mod;
	for(int i=1;i<=n;++i){
		for(int j=0;j<g.g[i].size();++j){
			edge e=g.g[i][j];
			if(g.dis[i]+e.len+rg.dis[e.to]==d&&g.dis[i]*2<d&&g.dis[e.to]*2>d){
				ll now=1ll*g.f[i]*rg.f[e.to]%mod;
				ans-=1ll*now*now%mod;
				ans=(ans+mod)%mod;
			}
		}
		if(g.dis[i]+rg.dis[i]==d&&g.dis[i]*2==d){
			ll now=1ll*g.f[i]*rg.f[i]%mod;
			ans-=1ll*now*now%mod;
			ans=(ans+mod)%mod;
		}
	}
	printf("%d",ans);
}