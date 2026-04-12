#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7,N = 1e5 + 1;
int dp[2][N],s,t,n,m;
long long dis[2][N];
struct edges{
	int x,y,w;
}e[N<<1];
struct node{
	int x,w;
	node(int a = 0,int b = 0){
		x = a;w = b;
	}
};
void add(int &a,int b){
	a+=b;
	a%=M;
	if(a >= M)a-=M;
	if(a < 0)a+=M;
}
vector<node>g[N];
bool vis[N];
void dijk(int s,bool at){
	long long *dis = ::dis[at];
	memset(vis,0,sizeof vis);
	int *dp = ::dp[at];
	dis[s] = 0;
	dp[s] = 1;
	priority_queue<pair<long long,int>>q;
	q.push({0,s});
	while(!q.empty()){
		int x = q.top().second;
		long long w = -q.top().first;
		q.pop();
		if(vis[x])continue;
		vis[x] = 1;
		for(auto i : g[x]){
			int y = i.x;
			long long cur = w + i.w;
			if(cur == dis[y])add(dp[y],dp[x]);
			if(cur >= dis[y])continue;
			dp[y] = dp[x];
			dis[y] = cur;
			q.push({-dis[y],y});
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);	
	for(int i = 0;i < m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		int a = --e[i].x,b = --e[i].y,c = e[i].w;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i = 0;i < n;i++)dis[0][i] = dis[1][i] = 1e18;
	dijk(--s,0);
	dijk(--t,1);
	long long mndis = dis[0][t];
	int ans = dp[0][t]*1LL*dp[0][t]%M,sz = 0;
	for(auto i : e){
		if(sz == m)break;
		++sz;
		long long mn = min(dis[0][i.x],dis[0][i.y]);
		long long mx = min(dis[1][i.x],dis[1][i.y]);
		if(mn == dis[0][i.y])swap(i.x,i.y);
		if(mn + mx + i.w == mndis && mn * 2 < mndis && mx * 2 < mndis)add(ans,-(dp[0][i.x]*1LL*dp[0][i.x]%M)*(dp[1][i.y]*1LL*dp[1][i.y]%M)%M);
	}
	for(int i = 0;i < n;i++)
		if(dis[0][i] == dis[1][i])add(ans,-(dp[0][i]*1LL*dp[0][i]%M)*(dp[1][i]*1LL*dp[1][i]%M)%M);
	printf("%d\n",ans);
}