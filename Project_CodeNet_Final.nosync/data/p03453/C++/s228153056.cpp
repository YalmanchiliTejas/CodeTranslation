/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long ll;
inline void Fail(){printf("0");exit(0);}
inline void debug(int x){cerr<<"debug: "<<x<<"\n";}
inline void debug(int n,int x[]){cerr<<"debug "<<"\n";rep(i,n)cerr<<x[i]<<" ";cerr<<"\n";}
inline void debug(string x){cerr<<"debug: "<<x<<"\n";}

const int maxn=100005;
const int mod=1e9+7;
inline void add(int &a,int b){a=(a+b)%mod;}
inline int mult(int a,int b){return 1LL*a*b%mod;}
int n,m,s,t,ans,ans2;
vector<pii>edge[maxn];
int dp[2][maxn],u[maxn*2],v[maxn*2],c[maxn*2];
ll dist[2][maxn];
bool vis[2][maxn];
priority_queue<pair<ll,int> >q;

void Dij(int tp){
	while(!q.empty())q.pop();
	rep(i,n)dist[tp][i]=(1LL<<62)-1LL;
	int f=tp?t:s;
	dist[tp][f]=0;
	dp[tp][f]=1;
	q.push(mp(0,f));
	while(!q.empty()){
		pair<ll,int>x=q.top();q.pop();
		x.first=-x.first;
		if(x.first!=dist[tp][x.second])continue;
		rep(i,edge[x.second].size()){
			pii y=edge[x.second][i];
			if(dist[tp][y.first]>x.first+y.second){
				dist[tp][y.first]=x.first+y.second;
				dp[tp][y.first]=dp[tp][x.second];
				q.push(mp(-(x.first+y.second),y.first));
			}
			else if(dist[tp][y.first]==x.first+y.second){
				add(dp[tp][y.first],dp[tp][x.second]);
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	s--;t--;
	rep(i,m){
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		u[i]--;v[i]--;
		edge[u[i]].pb(mp(v[i],c[i]));
		edge[v[i]].pb(mp(u[i],c[i]));
	}
	rep(k,2)Dij(k);
	rep(k,2)rep(i,n)dp[k][i]=mult(dp[k][i],dp[k][i]);
	ans=dp[0][t];
	ll mn=dist[0][t];
	rep(i,n){
		if(dist[0][i]+dist[1][i]>mn||dist[0][i]!=dist[1][i])continue;
		add(ans2,mult(dp[0][i],dp[1][i]));
	}
	rep(i,m){
		if(dist[0][u[i]]+dist[1][v[i]]+c[i]==mn&&abs(dist[0][u[i]]-dist[1][v[i]])<c[i])
		add(ans2,mult(dp[0][u[i]],dp[1][v[i]]));
		if(dist[0][v[i]]+dist[1][u[i]]+c[i]==mn&&abs(dist[0][v[i]]-dist[1][u[i]])<c[i])
		add(ans2,mult(dp[1][u[i]],dp[0][v[i]]));
	}
	ans=(ans-ans2+mod)%mod;
	printf("%d",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/