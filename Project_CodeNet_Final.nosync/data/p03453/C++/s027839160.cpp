#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;

class Dijkstra{
public:
	vector<vector<P> > G;
	vector<int> d;
	
	void init(int n){
		d.resize(n);
		G.resize(n);
	}
	void add_edge(int s, int t, int cost){
		G[s].push_back(P(t, cost));
	}
	
	void dijkstra(int s){
		priority_queue<P, vector<P>, greater<P> > q;
		fill(d.begin(), d.end(), INF);
		d[s] = 0;
		q.push(P(0, s));
		while(!q.empty()){
			P p = q.top();q.pop();
			int v = p.second;
			if(d[p.second] < p.first)continue;
			rep(i,G[v].size()){
				int to = G[v][i].first, cost = G[v][i].second;
				if(d[to] <= d[v]+cost)continue;
				d[to] = d[v]+cost;
				q.push(P(d[to], to));
			}
		}
	}
};

vector<P> G[200000];
vector<int> d[2], dp[2];
Dijkstra dij[2];
P a[400000];
map<P, int> mp;
int f[200000], dis;
const int mod = 1e9+7;

void bfs(int s, int idx){
	fill(f, f+200000, 0);
	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, s));
	dp[idx][s] = 1;
	while(!q.empty()){
		P p = q.top();q.pop();
		rep(i,G[p.se].size()){
			int to = G[p.se][i].fi, cost = G[p.se][i].se;
			if(d[idx][p.se]+d[!idx][to]+cost == dis){
				mp[P(p.se, to)] = mp[P(to, p.se)] = 1;
				ADD(dp[idx][to], dp[idx][p.se]);
				if(f[to] == 0)q.push(P(d[idx][to], to));
				f[to] = 1;
			}
		}
	}
}

int mul(int x, int y){
	int xx = (x*x)%mod, yy = (y*y)%mod;
	return (xx*yy)%mod;
}

signed main(){
	int n, m, s, t;
	scanf("%lld%lld%lld%lld", &n, &m, &s, &t);s--;t--;
	rep(i,2)dij[i].init(n+2);
	rep(i,2)dp[i].resize(n+2);
	rep(i,m){
		int u, v, c;
		scanf("%lld%lld%lld", &u, &v, &c);u--;v--;
		rep(j,2)dij[j].add_edge(u, v, c);
		rep(j,2)dij[j].add_edge(v, u, c);
		G[u].push_back(P(v, c));
		G[v].push_back(P(u, c));
		a[i] = P(u, v);
	}
	dij[0].dijkstra(s);
	dij[1].dijkstra(t);
	rep(i,2)d[i] = dij[i].d;
	dis = d[0][t];
	bfs(s, 0);bfs(t, 1);
	
	int ans = (dp[0][t]*dp[0][t])%mod;
	rep(i,n){
		if(2*d[0][i] == dis)ans = (ans+mod-mul(dp[0][i], dp[1][i]))%mod;
	}
	rep(i,m){
		int u = a[i].fi, v = a[i].se;
		if(2*d[0][u] < dis and 2*d[0][v] > dis and mp[P(u, v)] == 1)
		ans = (ans+mod-mul(dp[0][u], dp[1][v]))%mod;
		swap(u, v);
		if(2*d[0][u] < dis and 2*d[0][v] > dis and mp[P(u, v)] == 1)
		ans = (ans+mod-mul(dp[0][u], dp[1][v]))%mod;
	}
	printf("%lld\n", ans);
	return 0;
}


