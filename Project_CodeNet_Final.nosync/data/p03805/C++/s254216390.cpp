#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int dfs(int u, int d, int N, vector<bool>& seen, vector<vector<int>>& adj)
{
  seen[u] = true;
  ++d;
  if (d == N) { return 1; }
  int ret = 0;
  for (int v : adj[u]) {
    if (not seen[v]) {
      ret += dfs(v, d, N, seen, adj);
      seen[v] = false;
    }
  }
  return ret;
}

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int>> adj(N + 5, vector<int>());
  int a, b;
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> seen(N + 5, 0);
  int ans = dfs(1, 0, N, seen, adj);
  printf("%d\n", ans);
  return 0;
}
