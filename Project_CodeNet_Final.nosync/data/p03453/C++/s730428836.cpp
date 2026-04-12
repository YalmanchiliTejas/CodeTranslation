#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const LL mo=1e9+7;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Edge{
	int to,nex; LL w;
}e[N*4];
int n,m,s,t,head[N],vis[N],tot,id[N];
LL ds[N],dt[N],fs[N],ft[N],g[N];
inline void ade(int u,int v,LL w)
{e[++tot]=(Edge){v,head[u],w};head[u]=tot;}
inline void add(int &x,int y)
{
	x+=y; if(x>mo) x-=mo;
}
inline LL sqr(LL x)
{
	return x*x%mo;
}
int cmp(int x,int y)
{
	return g[x]<g[y];
}
void spfa(int s,LL *dist,LL *f)
{
	queue<int> q; q.push(s);
	for(int i=0;i<=n;i++) dist[i]=1e15,id[i]=i;
	clr(vis,0); dist[s]=0; vis[s]=f[s]=1;
	//for(int i=1;i<=n;i++) cout<<dist[i]<<' '; cout<<endl;
	while(!q.empty()){
		int u=q.front(); q.pop(); vis[u]=0;
		for(int i=head[u];i;i=e[i].nex){
			int v=e[i].to; LL w=e[i].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				if(!vis[v])
				  vis[v]=1,q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++) g[i]=dist[i];
	sort(id+1,id+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<dist[i]<<' '; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<id[i]<<' '; cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		int u=id[i];
		for(int j=head[u];j;j=e[j].nex){
			int v=e[j].to; LL w=e[j].w;
			if(dist[v]==dist[u]+w)
			  (f[v]+=f[u])%=mo;
		}
	}
}
int main()
{
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		ade(u,v,w); ade(v,u,w);
	}
	spfa(s,ds,fs); spfa(t,dt,ft);
//	cout<<"S: ";for(int i=1;i<=n;i++) cout<<fs[i]<<' '; cout<<endl;
//	cout<<"T: ";for(int i=1;i<=n;i++) cout<<ft[i]<<' '; cout<<endl;
	LL ans=sqr(fs[t]),len=ds[t];
	if(len%2==0)
	for(int u=1;u<=n;u++){
		if(ds[u]==(len/2))
		  ans=(ans-sqr(fs[u])*sqr(ft[u])%mo+mo)%mo;
	}
	int k1=len&1;
	//cout<<ans<<' '<<k1<<endl;
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=e[i].nex){
			int v=e[i].to; LL w=e[i].w;
			if(ds[u]<(len/2)+k1 && dt[v]<(len/2)+k1 && ds[u]+w+dt[v]==len){
				ans=(ans-sqr(fs[u])*sqr(ft[v])%mo+mo)%mo;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}