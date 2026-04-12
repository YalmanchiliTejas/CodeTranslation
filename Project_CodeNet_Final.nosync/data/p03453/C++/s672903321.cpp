#include<bits/stdc++.h>
using namespace std;
const int maxn=400100;
const long long md=1e9+7;
const long long INF=1e17;
struct edge{
	int s,t,v;
}E[maxn];
struct node{
	int p;
	long long d;
};
bool operator < (const node &A,const node &B){
	return A.d>B.d;
}
int S,T;
int n,m;
long long dp1[maxn],dp2[maxn];
long long dis1[maxn],dis2[maxn];
int beg[maxn],tto[maxn],nex[maxn],w[maxn],e;
void putin(int s,int t,int v){
	tto[++e]=t;
	nex[e]=beg[s];
	beg[s]=e;
	w[e]=v;
}
void dij(int s,long long *dis,long long *dp){
	static priority_queue<node> q;
	static bool vis[maxn];
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	dis[s]=0,dp[s]=1;
	q.push((node){s,0});
	node st;
	int u;
	while(!q.empty()){
		st=q.top();
		q.pop();
		if(vis[st.p]) continue;
		u=st.p,vis[u]=1;
		for(int i=beg[u];i;i=nex[i]){
			if(dis[tto[i]]>dis[u]+w[i]){
				dis[tto[i]]=dis[u]+w[i];
				dp[tto[i]]=dp[u];
				q.push((node){tto[i],dis[tto[i]]});
			}
			else if(dis[tto[i]]==dis[u]+w[i])
				(dp[tto[i]]+=dp[u])%=md;
		}
	}
}
int main(){
//	freopen("A.in","r",stdin);
	int s,t,v;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&t,&v);
		E[i<<1]=(edge){s,t,v};
		E[i<<1|1]=(edge){t,s,v};
		putin(s,t,v);
		putin(t,s,v);
	}
	dij(S,dis1,dp1);
	dij(T,dis2,dp2);
	long long sum=dp1[T],ans=0;
	for(int i=1;i<=n;i++){
		if(dis1[i]+dis2[i]==dis1[T]&&dis1[i]==dis2[i]){
			ans=(ans+dp1[i]*dp2[i]%md*(dp1[T]-dp1[i]*dp2[i]%md+md)%md)%md;
			sum=(sum-dp1[i]*dp2[i]%md+md)%md;
		}
	}
//	printf("%lld\n",sum);
	for(int i=2;i<=(m<<1|1);i++){
		if(dis1[E[i].s]+E[i].v+dis2[E[i].t]!=dis1[T]) continue;
		if((dis1[E[i].s]+E[i].v)*2>dis1[T]&&(dis2[E[i].t]+E[i].v)*2>dis1[T])
			ans=(ans+dp1[E[i].s]*dp2[E[i].t]%md*(dp1[T]-dp1[E[i].s]*dp2[E[i].t]%md+md))%md;
	}
	printf("%lld\n",ans);
	return 0;
}
