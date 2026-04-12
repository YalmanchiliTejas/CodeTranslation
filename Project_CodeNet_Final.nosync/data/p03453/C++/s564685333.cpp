#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF=1000000000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const ll M = 1000000007;

int main(){
	static ll n,m;
	static ll s,t;
	static ll u[200010],v[200010],d[200010];
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld",&s,&t);
	rep(i,m){
		scanf("%lld%lld%lld",&u[i],&v[i],&d[i]);
	}
	
	static vector<P> G[100010];
	rep(i,m){
		G[u[i]].pb(P(v[i],d[i]));
		G[v[i]].pb(P(u[i],d[i]));
	}
	
	static ll cost[2][100010];
	static bool used[2][100010];
	rep(i,2)rep(j,100010){
		cost[i][j] = INF;
		used[i][j] = false;
	}
	priority_queue<P,vector<P>,greater<P>> que[2];
	rep(i,2){
		cost[i][s] = 0;
		que[i].push(P(cost[i][s],s));
		while(!que[i].empty()){
			P p = que[i].top(); que[i].pop();
			if(used[i][p.sc])continue;
			used[i][p.sc] = true;
			rep(j,G[p.sc].size()){
				P w = G[p.sc][j];
				if(cost[i][w.fr] > cost[i][p.sc] + w.sc){
					cost[i][w.fr] = cost[i][p.sc] + w.sc;
					que[i].push(P(cost[i][w.fr],w.fr));
				}
			}
		}
		swap(s,t);
	}
	
	static ll ret = 0;
	static ll dp[100010] = {};
	dp[s] = 1;
	vector<P> vec;
	rep1(i,n)vec.pb(P(cost[0][i],i));
	sor(vec);
	rep(i,vec.size()){
		int v = vec[i].sc;
		dp[v] %= M;
		rep(j,G[v].size()){
			P ed = G[v][j];
			if(cost[0][ed.fr] != cost[0][v] + ed.sc)continue;
			if(cost[0][ed.fr] + cost[1][ed.fr] != cost[0][t])continue;
			dp[ed.fr] += dp[v];
		}
	}
	static ll dp_[100010] = {};
	dp_[t] = 1;
	vec.clear();
	rep1(i,n)vec.pb(P(cost[1][i],i));
	sor(vec);
	rep(i,vec.size()){
		int v = vec[i].sc;
		dp_[v] %= M;
		rep(j,G[v].size()){
			P ed = G[v][j];
			if(cost[1][ed.fr] != cost[1][v] + ed.sc)continue;
			if(cost[1][ed.fr] + cost[0][ed.fr] != cost[0][t])continue;
			dp_[ed.fr] += dp_[v];
		}
	}
	
	/*rep1(i,n){
		printf("%lld %lld\n",dp[i],dp_[i]);
	}*/
	
	rep1(i,n){
		if(cost[0][i]+cost[1][i] == cost[0][t] && cost[0][i] == cost[1][i]){
			ll d = (dp[i]*dp_[i])%M;
			d = (d*d)%M;
			ret += M-d;
			if(ret > M)ret -= M;
		}
	}
	rep(i,m){
		if(cost[0][u[i]]+d[i]+cost[1][v[i]] == cost[0][t] &&
			cost[0][u[i]]*2 < cost[0][t] && cost[1][v[i]]*2 < cost[0][t]){
			ll d = (dp[u[i]]*dp_[v[i]])%M;
			d *= d; d %= M;
			ret += M-d;
			if(ret > M)ret -= M;
		}
		if(cost[0][v[i]]+d[i]+cost[1][u[i]] == cost[0][t] &&
			cost[0][v[i]]*2 < cost[0][t] && cost[1][u[i]]*2 < cost[0][t]){
			ll d = (dp[v[i]]*dp_[u[i]])%M;
			d *= d; d %= M;
			ret += M-d;
			if(ret > M)ret -= M;
		}
	}
	
	ret += dp[t]*dp[t];
	cout << ret%M << endl;
}

