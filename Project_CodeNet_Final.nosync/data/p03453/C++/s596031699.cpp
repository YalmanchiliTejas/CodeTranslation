#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 200500000000000
#define MOD 1000000007
#define N 100005
#define M 1000005
#define LOG 18
#define KOK 4000000
using namespace std;

struct state {

	int anc;
	int cur;
	ll cost;

	bool operator<(const state& oth) const {

		return cost>oth.cost;

	}

};

int n,m,s,t,a,b,c;
int dp[2][N],vis[2][N];
ll dis[2][N];
vector<ii> v[N];

void solve(int w,int node) {

	priority_queue<state> q;

	dp[w][0]=1;

	q.push({0,node,0});

	while(!q.empty()) {

		state now=q.top();

		q.pop();

		if(vis[w][now.cur]) {

			if(now.cost==dis[w][now.cur]) {

				dp[w][now.cur]=(dp[w][now.cur]+dp[w][now.anc])%MOD;

			}

			continue ;

		}

		vis[w][now.cur]=1;

		dp[w][now.cur]=dp[w][now.anc];

		dis[w][now.cur]=now.cost;

		for(ii go:v[now.cur]) {

			q.push({now.cur,go.st,now.cost+go.nd});

		}

	}

}

int main() {

//	freopen("input.txt","r",stdin);

	scanf("%d %d",&n,&m);

	scanf("%d %d",&s,&t);

	for(int i=1;i<=m;i++) {

		scanf("%d %d %d",&a,&b,&c);

		v[a].pb({b,c});
		v[b].pb({a,c});

	}

	solve(0,s);
	solve(1,t);

	int ans=1ll*dp[0][t]*dp[0][t]%MOD;

	for(int i=1;i<=n;i++) {

		if(dis[0][i]*2==dis[0][t] && dis[1][i]*2==dis[0][t]) ans=(ans-1ll*dp[0][i]*dp[1][i]%MOD*dp[0][i]%MOD*dp[1][i]%MOD+MOD)%MOD;

		for(ii go:v[i]) {

			if(dis[0][i]+go.nd+dis[1][go.st]==dis[0][t] && dis[0][i]*2<dis[0][t] && dis[0][go.st]*2>dis[0][t]) {

				ans=(ans-1ll*dp[0][i]*dp[1][go.st]%MOD*dp[0][i]%MOD*dp[1][go.st]%MOD+MOD)%MOD;

			}

		}

	}

	printf("%d",ans);

}

