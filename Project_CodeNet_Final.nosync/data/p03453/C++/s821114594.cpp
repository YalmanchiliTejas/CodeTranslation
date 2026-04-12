#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
 
const int N=200005;
const ll inf=1000000000000000ll;
const int mod=1000000007;
 
struct E{
	int to,next,w;
}mem[N<<1];
struct node{
	int x,y,w;
	node(){}
	node(int x,int y,int w):x(x),y(y),w(w){}
}e[N<<1];
int n,m,num,x,y,w,s,t,ans,cnt;
ll s1,s2;
int head[N],dp1[N],dp2[N],d[N];
bool vis[N];
ll dis1[N],dis2[N];
queue<int> q;
vector<int> lev[N];
 
void add(int x,int y,int w){
	num++;
	mem[num].to=y; mem[num].next=head[x]; mem[num].w=w;
	head[x]=num;
	e[++cnt]=node(x,y,w);
}

void spfa(int st,ll dis[]){
	int j,k,u,i;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=n;i++) dis[i]=inf;
	q.push(st); dis[st]=0;
	while (!q.empty()){
		k=q.front(); q.pop(); vis[k]=0;
		for (j=head[k];j;j=mem[j].next){
			u=mem[j].to;
			if (dis[k]+1ll*mem[j].w<dis[u]){
				dis[u]=dis[k]+1ll*mem[j].w;
				if (!vis[u]){
					q.push(u); vis[u]=1;
				}
			}
		}
	}
}

void work(int st,ll dis[],int dp[]){
	int i,j,u,k;
	memset(d,0,sizeof(d));
	for (i=1;i<=n;i++) lev[i].clear();
	for (i=1;i<=n;i++){
		for (j=head[i];j;j=mem[j].next){
			u=mem[j].to;
			if (dis[i]+1ll*mem[j].w==dis[u]){
				lev[i].push_back(u); d[u]++;
			}
		}
	}
	q.push(st); dp[st]=1;
	while (!q.empty()){
		k=q.front(); q.pop();
		for (j=0;j<lev[k].size();j++){
			u=lev[k][j]; d[u]--;
			(dp[u]+=dp[k])%=mod;
			if (!d[u]) q.push(u);
		}
	}
}

int main(){
	int i,j,u;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w); add(y,x,w);
	}
	spfa(s,dis1);
	spfa(t,dis2);
	work(s,dis1,dp1);
	work(t,dis2,dp2);
	ans=1ll*dp1[t]*dp1[t]%mod;
	for (i=1;i<=n;i++){
		if (dis1[i]==dis2[i]&&dis1[i]+dis2[i]==dis1[t]){
			(ans-=1ll*dp1[i]*dp1[i]%mod*dp2[i]%mod*dp2[i]%mod)%=mod;
		}
	}
	for (i=1;i<=cnt;i++){
		x=e[i].x; y=e[i].y; w=e[i].w;
		if (2ll*dis1[x]<dis1[t]&&2ll*dis2[y]<dis1[t]&&dis1[x]+dis2[y]+1ll*w==dis1[t]){
			(ans-=1ll*dp1[x]*dp1[x]%mod*dp2[y]%mod*dp2[y]%mod)%=mod;
		}
	}
	ans=(ans%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}