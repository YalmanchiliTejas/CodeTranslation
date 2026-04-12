#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define INF 1e9;
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

vector<bool> visited;
ll ans = 0;
ll N, M;

void dfs(const Graph &G, ll v, ll depth) {
  if (visited[v]) return;
  if (depth == N - 1) {
    ans++;
  }
  visited[v] = true;

  for (auto next_v : G[v]) {
    if (visited[next_v]) continue;
    dfs(G, next_v, depth + 1);
  }
  visited[v] = false;
}

int main() {
  cin >> N >> M;
  Graph G(N);
  REP(i, M) {
    ll a, b;
    cin >> a >> b;
    a--, b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  visited.assign(N, false);
  dfs(G, 0, 0);

  cout << ans;

  return 0;
}