#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

template <typename T>
pair<vector<int>,vector<int>> dijkstra(const vector<vector<pair<int,T>>> &G,int s,T inf) {
  vector<int> d(G.size(),inf),c(G.size(),0);
  d[s] = 0;
  c[s] = 1;
  using P = pair<T,int>;
  priority_queue<P,vector<P>,greater<P>> que;
  que.emplace(0,s);
  while (!que.empty()) {
    T dd; int v;
    tie(dd,v) = que.top(); que.pop();
    if (d[v] < dd) continue;
    for (auto e : G[v]) {
      // cout << d[v] << " " << e.first << " " << d[v]+e.second << endl;
      if (d[e.first] > d[v]+e.second) {
        d[e.first] = d[v]+e.second;
        c[e.first] = c[v];
        que.emplace(d[e.first],e.first);
      } else if (d[e.first] == d[v]+e.second) {
        (c[e.first] += c[v]) %= MOD;
      }
    }
  }
  return make_pair(d,c);
}

int N,M,S,T;
int U[200010],V[200010],D[200010];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> N >> M >> S >> T;
  S--; T--;
  vector<vector<pair<int,int>>> G(N);
  REP(i,M) {
    cin >> U[i] >> V[i] >> D[i];
    U[i]--; V[i]--;
    G[U[i]].emplace_back(V[i],D[i]);
    G[V[i]].emplace_back(U[i],D[i]);
  }
  vector<int> ds,cs,dt,ct;
  tie(ds,cs) = dijkstra(G,S,INF);
  tie(dt,ct) = dijkstra(G,T,INF);
  int ans = cs[T]*cs[T];
  for (int i = 0; i < N; i++) {
    if (ds[i]*2 == ds[T]) {
      (ans += MOD-cs[i]*cs[i]%MOD*ct[i]%MOD*ct[i]%MOD) %= MOD;
    }
  }
  for (int i = 0; i < M; i++) {
    
    if (ds[U[i]]+D[i]+dt[V[i]] == ds[T]) {
      if (ds[U[i]]*2 < ds[T] && ds[V[i]]*2 > ds[T]) {
        (ans += MOD-cs[U[i]]*cs[U[i]]%MOD*ct[V[i]]%MOD*ct[V[i]]%MOD) %= MOD;
      }
    }
    if (ds[V[i]]+D[i]+dt[U[i]] == ds[T]) {
      if (ds[V[i]]*2 < ds[T] && ds[U[i]]*2 > ds[T]) {
        (ans += MOD-cs[V[i]]*cs[V[i]]%MOD*ct[U[i]]%MOD*ct[U[i]]%MOD) %= MOD;
      }
    }
  }
  cout << ans << endl;

  return 0;
}