#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long int;
using Graph = vector< vector<int> >;

/*
void chmax(ll &A, const ll B) {
  A = max(A, B);
}
*/

ll N, K, dp[100010][2][2], sz[100010];

void dfs(Graph &G, int cur, int par=-1) {
  sz[cur] = 1;
  for(auto to : G[cur]) {
    if(to == par) continue;
    dfs(G, to, cur);
    sz[cur] += sz[to];
  }
}

int solve(Graph &G, int cur, int f1, int f2, int par=-1) {
  if(dp[cur][f1][f2] >= -1) return dp[cur][f1][f2];

  ll val = -1;
  if(f1 == 0) {
    if(f2 == 0) {
      val = 0;
      for(auto to : G[cur]) {
        if(to == par) continue;
        val += (sz[to] >= K);
      }
    }

    if(f2 == 1) {
      for(auto to : G[cur]) {
        if(to == par) continue;
        ll tmp = solve(G, to, 0, 1, cur);
        if(tmp >= 0) val = max(val, tmp);

        tmp = solve(G, to, 1, 1, cur);
        if(tmp >= 0) {
          tmp += (N - sz[to]) >= K;
          val = max(val, tmp);
        }
      }
    }

    return dp[cur][f1][f2] = val;
  }
  if(f1 == 1) {
    int M = G[cur].size();
    vector<ll> dpcur(3, -1);
    dpcur[0] = 0;
    for(size_t i=0; i<G[cur].size(); i++) {
      int to = G[cur][i];
      if(to == par) continue;
      
      vector<ll> dpnxt(3, -1);
      for(int j=0; j<=2; j++) {
        if(dpcur[j] < 0) continue;
        
        // take
        if(j < 2) {
          ll tmp = solve(G, to, 1, 0, cur);
          if(tmp >= 0) {
            dpnxt[j+1] = max(dpnxt[j+1], dpcur[j] + tmp);
          }
        }

        // do not take
        dpnxt[j] = max(dpnxt[j], dpcur[j] + (sz[to] >= K));
      }
      swap(dpcur, dpnxt);
    }

    if(f2 == 0) {
      return dp[cur][f1][f2] = (val = max(dpcur[0], dpcur[1]));
    }
    if(f2 == 1) {
      return dp[cur][f1][f2] = (val = max(dpcur[1], dpcur[2]));
    }
  }
}

int main() {
  cin >> N >> K;

  Graph G(N);
  for(int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  fill(dp[0][0], dp[N+1][0], -2);
  dfs(G, 0);
  cout << max(solve(G, 0, 0, 1), solve(G, 0, 1, 1)) << endl;

  /*
  for(int i=0; i<N; i++) {
    for(int f1=0; f1<2; f1++) {
      for(int f2=0; f2<2; f2++) {
        fprintf(stderr, "dp[%d][%d][%d] = %lld\n", i, f1, f2, dp[i][f1][f2]);
      }
    }
  }
  */
  return 0;
}

