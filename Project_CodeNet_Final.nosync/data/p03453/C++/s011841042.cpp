
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

struct E {
  int a, b;
  ll c;
};
bool operator>(const E& e1, const E& e2) {
  return e1.c > e2.c;
}

vector<E> g[100000+10];
int nNode, nEdge;

ll dist[2][100000+10];
bool visited[2][100000+10];
const ll INF = 1e18;
void dijkstra(int s, int p) { // p: 1ならtからの距離
  REP(u, nNode) {
    dist[p][u] = INF;
  }
  priority_queue<E, vector<E>, greater<E> > q;
  q.push((E){s, s, 0});
  dist[p][s] = 0;
  while(!q.empty()) {
    E cur = q.top(); q.pop();
    int u = cur.b;
    if(visited[p][u]) {
      continue;
    }
    // cerr << "> " << u << endl;
    visited[p][u] = true;
    REP(i, g[u].size()) {
      const E& e = g[u][i];
      int v = e.b;
      // cerr << ">>> " << v << " " << dist[p][u] + e.c << " " << dist[p][v] << endl;
      if(!visited[p][v] && dist[p][u] + e.c < dist[p][v]) {
        dist[p][v] = dist[p][u] + e.c;
        q.push((E){u, v, dist[p][v]});
      }
    }
  }
}

ll dp[2][100000+10];
ll visited2[2][100000+10];
void go(int s, int t, int p) { // p: 1ならtまでの行き方。0ならsからの行き方
  priority_queue<E, vector<E>, greater<E> > q;
  q.push((E){s, s, 0});
  dp[p][s] = 1;
  while(!q.empty()) {
    E cur = q.top(); q.pop();
    int u = cur.b;
    if(visited2[p][u]) {
      continue;
    }
    visited2[p][u] = true;
    REP(i, g[u].size()) {
      const E& e = g[u][i];
      int v = e.b;
      if(dist[p][u] + e.c + dist[p^1][v] == dist[p][t]) { // eを通るような最短路がある
        dp[p][v] = (dp[p][v] + dp[p][u]) % MOD;
        q.push((E){u, v, dist[p][v]});
      }
    }
  }
}

int main(void) {
  int s, t;

  scanf("%d%d%d%d", &nNode, &nEdge, &s, &t);
  s--;
  t--;
  REP(iEdge, nEdge) {
    E e;
    scanf("%d%d%lld", &e.a, &e.b, &e.c);
    e.a--;
    e.b--;
    // cerr << e.a << " " << e.b << endl;
    g[e.a].push_back(e);
    swap(e.a, e.b);
    g[e.a].push_back(e);
  }
  // REP(u, nNode) {
  //   fprintf(stderr, "g[%d]: ", u);
  //   REP(i, g[u].size()) {
  //     fprintf(stderr, "%d,", g[u][i].b);
  //   }
  //   fprintf(stderr, "\n");
  // }
  dijkstra(s, 0);
  dijkstra(t, 1);
  go(s, t, 0);
  go(t, s, 1);

  // REP(i, 2) {
  //   REP(j, nNode) {
  //     fprintf(stderr, "dist[%d][%d] = %lld\n", i, j, dist[i][j]);
  //   }
  // }
  // REP(i, 2) {
  //   REP(j, nNode) {
  //     fprintf(stderr, "dp[%d][%d] = %lld\n", i, j, dp[i][j]);
  //   }
  // }

  assert(dp[0][t] == dp[1][s]);
  ll dst = dist[1][s];
  ll res = dp[1][s] * dp[0][t] % MOD;
  // cerr << ">>>>> " << res << endl;
  REP(u, nNode) {
    REP(i, g[u].size()) {
      const E& e = g[u][i];
      int v = e.b;
      ll dsu = dist[0][u];
      ll dvt = dist[1][v];
      if(dsu + e.c + dvt == dst) { // 最短路で使う枝
        if(dsu*2 < dst && dst < (dsu+e.c)*2) { // 道のりの中点がこの枝の上
          res = (res - dp[0][u]*dp[1][v]%MOD*dp[0][u]%MOD*dp[1][v]%MOD + MOD) % MOD;
          // cerr << ">>>>> " << u << " " << v << " " << dsu << " " << res << endl;
        }
      }
    }
  }
  REP(u, nNode) {
    if(dist[0][u] + dist[1][u] == dst) { // 最短路で使うノード
      if(dist[0][u]*2 == dst) { // 道のりの中点がこのノードの上
        res = (res - dp[0][u]*dp[1][u]%MOD*dp[0][u]%MOD*dp[1][u]%MOD + MOD) % MOD;
        // cerr << ">>>>> " << u << " " << res << endl;
      }
    }
  }
  printf("%lld\n", res);

  return 0;
}
