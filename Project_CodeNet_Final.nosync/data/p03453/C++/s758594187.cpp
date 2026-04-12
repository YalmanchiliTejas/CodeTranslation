#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,M=200005;
const ll ms=1e9+7,inf=1ll<<60;
int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct Edg{
	int nxt,poi,cost;
}e[M<<1];
ll dis[N],fdis[N],f[N],g[N],n,m,s,t;
vector<int>E[N],G[N];
int first[N],l=0;
bool vis[N],use[N];
void addedge(int u,int v,int k){
	l++;
	e[l].nxt=first[u];
	e[l].poi=v;
	e[l].cost=k;
	first[u]=l;
}
void spfa(ll *dis,int s){
	for (int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	queue<int>q;
	q.push(s);
	dis[s]=0; vis[s]=0;
	while (!q.empty()){
		int now=q.front(); q.pop();
		for (int p=first[now];p;p=e[p].nxt){
			int v=e[p].poi;
			if (dis[v]>dis[now]+e[p].cost){
				dis[v]=dis[now]+e[p].cost;
				if (!vis[v]) q.push(v),vis[v]=1;
			}
		}
		vis[now]=0;
	}
}
void add(ll &x,ll y){
	x+=y;
	if (x>=ms) x-=ms;
}
void dfs1(int u){
	vis[u]=1;
	for (int i=0;i<E[u].size();i++){
		int v=E[u][i];
		if (!vis[v]) dfs1(v);
		add(f[u],f[v]);
	}
}
void dfs2(int u){
	vis[u]=1;
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if (!vis[v]) dfs2(v);
		add(g[u],g[v]);
	}
}
int main(){
	n=read(),m=read();
	s=read(),t=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),k=read();
		addedge(u,v,k); addedge(v,u,k);
	}
	spfa(dis,s); spfa(fdis,t);
	for (int i=1;i<=n;i++)
	use[i]=(dis[i]+fdis[i]==dis[t]);
	for (int i=1;i<=n;i++){
		if (!use[i]) continue;
		for (int p=first[i];p;p=e[p].nxt){
			int v=e[p].poi;
			if (use[v]&&dis[v]==dis[i]+e[p].cost)
			E[i].push_back(v);
		}
	}
	for (int i=1;i<=n;i++){
		if (!use[i]) continue;
		for (int p=first[i];p;p=e[p].nxt){
			int v=e[p].poi;
			if (use[v]&&fdis[v]==fdis[i]+e[p].cost)
			G[i].push_back(v);
		}
	}
	memset(vis,0,sizeof(vis));
	vis[t]=1; f[t]=1; dfs1(s);
	memset(vis,0,sizeof(vis));
	vis[s]=1; g[s]=1; dfs2(t);
	ll ans=0;
	for (int i=1;i<=n;i++){
		if (!use[i]) continue;
		if (dis[t]==dis[i]*2){
			ans=(ans+f[i]*g[i]%ms*f[i]%ms*g[i]%ms)%ms;
		}
	}
	for (int i=1;i<=n;i++){
		if (!use[i]||dis[i]*2>=dis[t]) continue;
		for (int j=0;j<E[i].size();j++){
			int v=E[i][j];
			if (dis[v]*2>dis[t]){
				ans=(ans+g[i]*f[v]%ms*g[i]%ms*f[v]%ms)%ms;
			}
		}
	}
	ans=(f[s]*f[s]-ans+ms)%ms;
	printf("%lld\n",ans);
	return 0;
}