#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<long long, int> P;
typedef pair<P, int> P2;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF (1LL<<60)
#define MOD 1000000007
inline void add(int &x, int v) { x += v; if (x >= MOD) x-=MOD; }

int N, M;
vector<P> G[100000];
vector<P> G2[100000], G2rev[100000];
long long D[100000];
bool OK[100000];

int deg[100000];
int dp[100000], dp_rev[100000];


int S, T;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M >> S >> T;
  S--, T--;
  vector<P2> edges;
  rep(i, M) {
    int u, v, d;
    cin >> u >> v >> d;
    u--, v--;
    G[u].pb(P(v, d));
    G[v].pb(P(u, d));
    edges.pb(P2(P(u, v), d));
  }

  rep(i, N) D[i] = INF;
  priority_queue<P, vector<P>, greater<P> > pq;
  D[S] = 0;
  pq.push(P(D[S], S));
  while (!pq.empty()) {
    long long r = pq.top()._1;
    int x = pq.top()._2; pq.pop();
    if (D[x] < r) continue;
    for (P p : G[x]) {
      int t = p._1, len = p._2;
      if (D[t] > r+len) {
        D[t] = r+len;
        pq.push(P(D[t], t));
      }
    }
  }

  rep(i, N) OK[i] = false;
  queue<int> q;
  q.push(T);
  OK[T] = true;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (P p : G[x]) {
      int t = p._1, len = p._2;
      if (D[t]+len == D[x] && !OK[t]) {
        OK[t] = true;
        q.push(t);
      }
    }
  }
  assert(OK[S]);
  rep(x, N) if (OK[x]) {
    for (P p : G[x]) {
      int t = p._1, len = p._2;
      if (OK[t] && D[x]+len==D[t]) {
        G2[x].pb(P(t, len));
        G2rev[t].pb(P(x, len));
        deg[t]++;
      }
    }
  }
  q.push(S);
  vector<int> topo;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    topo.pb(x);
    for (P p : G2[x]) {
      int t = p._1, len = p._2;
      deg[t]--;
      if (deg[t] == 0) q.push(t);
    }
  }
  //assert(topo.size() == N);
  rep(i, N) assert(deg[i] == 0);
  assert(topo.front() == S);
  assert(topo.back() == T);

  dp[S] = 1;
  for (int x : topo) {
    for (P p : G2[x]) {
      int t = p._1, len = p._2;
      add(dp[t], dp[x]);
    }
  }
  dp_rev[T] = 1;
  for (int j=topo.size()-1; j>=0; j--) {
    int x = topo[j];
    for (P p : G2rev[x]) {
      int t = p._1, len = p._2;
      add(dp_rev[t], dp_rev[x]);
    }
  }
  assert(dp[T] == dp_rev[S]);
  int s = (1LL*dp[T]*dp[T]) % MOD;
  long long tall = D[T];
  rep(i, N) if (OK[i]) {
    long long time = D[i];
    if (time != tall-time) continue;
    int e = (1LL*dp[i]*dp_rev[i])%MOD;
    add(s, MOD-((1LL*e*e)%MOD));
  }
  for (P2 p : edges) {
    int u = p._1._1, v = p._1._2, d = p._2;
    if (!OK[u] || !OK[v]) continue;
    if (D[u] > D[v]) swap(u, v);
    if (D[u]+d!=D[v]) continue;
    // (D[u], D[u]+d) - (tall-D[v], tall-D[u])
    long long l = max(D[u], tall-D[v]);
    long long r = min(D[v], tall-D[u]);
    if (l < r) {
      int e1 = (1LL*dp[u]*dp_rev[v])%MOD;
      add(s, MOD-((1LL*e1*e1)%MOD));
    }
  }
  cout << s << "\n";
  return 0;
}
