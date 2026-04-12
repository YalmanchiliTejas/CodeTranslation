#include <bits/stdc++.h>
using namespace std;
#define oo 1000000000
#define mod 1000000007
const int N = 200010 , K = 210;
const double PI = acos(-1);
int n , m , s , t , vis[N] , vi = 0 , dp[2][N];
vector< pair<int,int> > g[N];
long long dist[2][N];

void djikstra(bool B,int src){
	priority_queue < pair<long long ,int > > q;
	q.push(make_pair(0,src));
	vi++;
	while(!q.empty()){
		int node = q.top().second;
		long long cost = q.top().first;
		q.pop();
		if(vis[node] == vi) continue;
		vis[node] = vi;
		dist[B][node] = -cost;
		for(int i=0;i<g[node].size();i++){
			int newnode = g[node][i].first;
			if(vis[newnode] != vi)
				q.push(make_pair(cost-g[node][i].second,newnode));
		}
	}
}

int solve(bool B,int node){
	if(dp[B][node] != -1) return dp[B][node];
	dp[B][node] = 0;
	for(int i=0;i<g[node].size();i++){
		if(dist[B ^ 1][node] + dist[B][g[node][i].first] + g[node][i].second == dist[0][s]){
			dp[B][node] += solve(B,g[node][i].first);
			dp[B][node] %= mod;
		}
	}
	return dp[B][node];
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for(int i=0;i<m;i++){
		int u , v, d;
		scanf("%d%d%d",&u,&v,&d);
		g[u].push_back(make_pair(v,d));
		g[v].push_back(make_pair(u,d));
	}
	djikstra(0,t);
	djikstra(1,s);
	memset(dp,-1,sizeof(dp));
	dp[1][s] = 1;
	dp[0][t] = 1;
	solve(0,s);
	solve(1,t);
	long long middist = dist[0][s] / 2;
	bool evenn = (dist[0][s] % 2 == 0);
	int sum = 0;
	int ans = 0;
	for(int node=1;node<=n;node++){
		if(dp[0][node] == -1) dp[0][node] = 0;
		if(dp[1][node] == -1) dp[1][node] = 0;
	}
	for(int node=1;node<=n;node++){
		if(evenn && dist[0][node] == middist){
			int tmp = (long long)sum * dp[0][node] % mod;
			tmp = (long long)tmp * dp[1][node] % mod;
			ans += tmp;
			ans %= mod;
			sum += (long long)dp[0][node] * dp[1][node] % mod;
			sum %= mod;
			continue;
		}
		else if(dist[0][node] > middist) continue;
		for(int j=0;j<g[node].size();j++){
			int newnode = g[node][j].first;
			if(dist[0][newnode] > middist && dist[0][node] + g[node][j].second + dist[1][newnode] == dist[0][s]){
				ans += (long long)((long long)sum * dp[0][node] % mod)* dp[1][newnode] % mod;
				ans %= mod;
				sum += (long long)dp[0][node] * dp[1][newnode] % mod;
				sum %= mod;
			}
		}
	}
	ans += ans;
	ans %= mod;
	cout << ans << endl;
  	return 0;
}