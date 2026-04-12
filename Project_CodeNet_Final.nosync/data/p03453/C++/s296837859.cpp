#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL INF=1LL<<50,mod=1e9+7;
const int N=100005,M=200005*2;
struct edge{
	int x,y,z;
}e[M];
struct gragh{
	int cnt,x[M],y[M],z[M],nxt[M],fst[N],ways[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		y[++cnt]=b,x[cnt]=a,z[cnt]=c,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}G,DAG,DAF;
int n,m,S,T,vis[N];
int q[N],head,tail,qmod,in[N];
LL dis[2][N];
void SPFA(int t,int S){
	int x,y;
	head=tail=0,qmod=n+1;
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n;i++)
		dis[t][i]=INF;
	dis[t][S]=0;
	q[tail=tail%qmod+1]=S;
	vis[S]=1;
	while (head!=tail){
		vis[x=q[head=head%qmod+1]]=0;
		for (int i=G.fst[x];i;i=G.nxt[i]){
			y=G.y[i];
			if (dis[t][x]+G.z[i]<dis[t][y]){
				dis[t][y]=dis[t][x]+G.z[i];
				if (!vis[y])
					vis[q[tail=tail%qmod+1]=y]=1;
			}
		}
	}
}
void build_DAG(){
	DAG.clear(),DAF.clear();
	for (int i=1;i<=m;i++){
		int &x=e[i].x,&y=e[i].y,z=e[i].z;
		if (dis[0][x]>dis[0][y])
			swap(x,y);
		if (dis[0][x]+z==dis[0][y]&&dis[1][y]+z==dis[1][x])
			DAG.add(x,y,z),DAF.add(y,x,z);
	}
}
void build_ways(){
	int x,y;
	head=tail=0;
	memset(in,0,sizeof in);
	memset(DAG.ways,0,sizeof DAG.ways);
	DAG.ways[S]=1;
	for (int i=1;i<=m;i++)
		in[DAG.y[i]]++;
	q[++tail]=S;
	while (head<tail){
		x=q[++head];
		for (int i=DAG.fst[x];i;i=DAG.nxt[i]){
			y=DAG.y[i];
			DAG.ways[y]=(DAG.ways[y]+DAG.ways[x])%mod;
			if (!--in[y])
				q[++tail]=y;
		}
	}
	head=tail=0;
	memset(in,0,sizeof in);
	memset(DAF.ways,0,sizeof DAF.ways);
	DAF.ways[T]=1;
	for (int i=1;i<=m;i++)
		in[DAF.y[i]]++;
	q[++tail]=T;
	while (head<tail){
		x=q[++head];
		for (int i=DAF.fst[x];i;i=DAF.nxt[i]){
			y=DAF.y[i];
			DAF.ways[y]=(DAF.ways[y]+DAF.ways[x])%mod;
			if (!--in[y])
				q[++tail]=y;
		}
	}
}
bool inway(int x){
	return dis[0][x]+dis[1][x]==dis[0][T];
}
LL sqr(LL x){
	return x%mod*(x%mod)%mod;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	G.clear();
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G.add(x,y,z),G.add(y,x,z);
		e[i].x=x,e[i].y=y,e[i].z=z;
	}
	SPFA(0,S);
	SPFA(1,T);
	build_DAG();
	build_ways();
	LL ans=sqr(DAG.ways[T])%mod;
	for (int i=1;i<=n;i++)
		if (dis[0][i]*2==dis[0][T]&&dis[1][i]*2==dis[0][T])
			ans=(ans+mod-sqr(1LL*DAG.ways[i]*DAF.ways[i]))%mod;
	for (int i=1;i<=DAG.cnt;i++){
		int x=DAG.x[i],y=DAG.y[i];
		if (inway(x)&&inway(y)&&dis[0][x]*2<dis[0][T]&&dis[1][y]*2<dis[0][T])
			ans=(ans+mod-sqr(1LL*DAG.ways[x]*DAF.ways[y]))%mod;
	}
	printf("%d",(int)ans);
	return 0;
}