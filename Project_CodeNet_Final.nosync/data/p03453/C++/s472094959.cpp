#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10,p=1e9+7;
int inc(int x,int y){x+=y;return x>=p?x-p:x;}int dec(int x,int y){x-=y;return x<0?x+p:x;}int mul(int x,int y){return (ll)x*y%p;}struct edge{int f,t,l;}w[N];int n,m,S,T,head[N],nxt[N];
void add(int f,int t,int l){
	static int cnt=0;
	w[++cnt]=(edge){f,t,l};
	nxt[cnt]=head[f];
	head[f]=cnt;
}
ll disS[N],disT[N];
int dpS[N],dpT[N];
bool vis[N];
typedef pair<ll,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > Q;
int q[N];ll *val;
bool cmp(int x,int y){return val[x]<val[y];}
void dijsktra(int S,ll *dis,int *dp){
	for (int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	Q.push(pii(dis[S]=0,S));
	while (!Q.empty()){
		int v=Q.top().second;Q.pop();
		if (vis[v]) continue;vis[v]=1;
		for (int i=head[v];i;i=nxt[i]){
			int u=w[i].t;
			if (dis[u]>dis[v]+w[i].l) Q.push(pii(dis[u]=dis[v]+w[i].l,u));
		}
	}
	dp[S]=1;
	for (int i=1;i<=n;i++) q[i]=i;
	val=dis;sort(q+1,q+n+1,cmp);
	for (int i=1;i<=n;i++){
		int v=q[i];
		for (int i=head[v];i;i=nxt[i]){
			int u=w[i].t;
			if (dis[u]==dis[v]+w[i].l) dp[u]=inc(dp[u],dp[v]);
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &S, &T);
	for(register int i=1; i<=m; ++i){
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		add(u, v, l);
		add(v, u, l);
	}
	dijsktra(S, disS, dpS);
	dijsktra(T, disT, dpT);
	long long len=disS[T];
	int ans=mul(dpS[T], dpS[T]);
	for(register int i=1; i<=n; ++i){
		int k=mul(dpS[i], dpT[i]);
		k=mul(k, k);
		if(disS[i]*2==len)
			ans=dec(ans, k);
	}
	for(register int v=1; v<=n; ++v)
		for(int i=head[v]; i; i=nxt[i]){
			int u=w[i].t;
			if (disS[v]+w[i].l^disS[u]||len^(disS[v]+w[i].l+disT[u])) continue;
			int k=mul(dpS[v],dpT[u]);
			k=mul(k, k);
			if (disS[v]*2<len&&disS[u]*2>len)
				ans=dec(ans, k);
		}
	printf("%d\n", ans);
	return 0;
}