#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ff first
#define ss second
#define nl '\n'
//////////////////////////////////////////////////

const int N = 100100, M = N + N;
const ll INF = (ll) 1e17, mod = 7+(ll)1e9;

int n, m, s, t;
ll dist[N], dps[N], dpt[N];
vector< pair<ll, ll> > g[N];
vector< int > dag[N], dagt[N];
int eu[M], ev[M]; ll ew[M];
priority_queue< pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

void dijkstra(int src) {
  fill(dist, dist+n+1, INF);
  dist[src] = 0;
  pq.emplace(dist[src], src);
  while( not pq.empty() ) {
    auto fr = pq.top(); pq.pop();
    ll u = fr.ss, del = fr.ff;
    if( del > dist[u] ) continue;
    for( const auto&e: g[u] ) {
      if( dist[e.ff] > del + e.ss ) {
	dist[e.ff] = e.ss + del;
	pq.emplace(dist[e.ff], e.ff);
      }
    }
  }
  for(int e=1;e<=m;e++) {
    int u = eu[e], v = ev[e]; ll w = ew[e];
    if( dist[u] > dist[v] ) swap(u, v);
    if( dist[u] + w == dist[v] ) {
      dag[u].emplace_back(v);
      dagt[v].emplace_back(u);
    }
  }
}

void dfs(int u, ll dp[], const int&sink, vector< int > dag[]) {
  if( dp[u] != -1 ) return;
  if( u == sink ) {
    dp[u] = 1;
    return;
  }
  dp[u] = 0;
  for(const int&v : dag[u]) {
    dfs(v, dp, sink, dag);
    dp[u] = (dp[u] + dp[v])%mod;
  }
}

inline bool intersect(ll a, ll b, ll c, ll d) {
  return not (b <= c or a >= d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); srand(time(0));
  
  cin >> n >> m;
  cin >> s >> t;
  for(int e=1;e<=m;e++) {
    int u, v; ll w;
    cin >> u >> v >> w;
    eu[e] = u, ev[e] = v, ew[e] = w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  
  dijkstra(s);
  
  // for(int i=1;i<=n;i++) cout << ds[i] << ' '; cout << endl;
  // for(int i=1;i<=n;i++) cout << dt[i] << ' '; cout << endl;
  
  fill(dps, dps+n+1, -1);
  for(int i=1;i<=n;i++) if( dps[i] == -1 ) dfs(i, dps, t, dag);
  fill(dpt, dpt+n+1, -1);
  for(int i=1;i<=n;i++) if( dpt[i] == -1 ) dfs(i, dpt, s, dagt);
  
  // assert(dpt[t] == dps[s]);
  
  ll tot = ( dps[s] * dps[s] ) % mod; // all pairs
  
  ll foo = 0;
  for(int i=1;i<=n;i++) { // meet at node
    if( dist[i] == dist[t] - dist[i] ) {
      ll ways = ( dps[i] * dpt[i] ) % mod;
      ways = (ways * ways)%mod; // all pairs passing through i
      foo = (foo + ways)%mod;
    }
  }
  
  for(int e=1;e<=m;e++) {
    int x = eu[e], y = ev[e]; ll w = ew[e];
    if( dist[x] > dist[y] ) swap(x, y);
    if( dist[x] + w != dist[y] ) continue;

    ll sx = dist[x], sy = dist[y],
      tx = dist[t] - dist[x], ty = dist[t] - dist[y];
    
    if( tx > ty ) swap(tx, ty); // 
    if( intersect(sx, sy, tx, ty) ) {
      ll ways = ( dps[y] * dpt[x] )%mod;
      ways = (ways * ways)%mod;
      foo = (foo + ways)%mod;
    }
  }
  
  cout << (tot + mod - foo) % mod << endl;
  
  return 0;
}
/* -*- -*- */
