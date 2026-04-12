#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;
const ll MAX_N = 8;

ll N, M;
std::vector< std::vector<ll> > vedge(MAX_N, std::vector<ll>(MAX_N, INF));

ll dfs(ll v, std::vector<bool>& visited)
{
  bool all_visited = true;

  for (ll i = 0; i < N; i++) {
    if (visited[i] == false) {
      all_visited = false;
    }
  }

  if (all_visited) {
    return 1;
  }

  ll ret = 0;
  for (ll i = 0; i < N; i++) {
    if (visited[i]) continue;
    if (vedge[v][i] == INF) continue;
    visited[i] = true;
    ret += dfs(i, visited);
    visited[i] = false;
  }

  return ret;
}

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  for (ll i = 0; i < M; i++) {
    ll a, b;
    std::cin >> a >> b;
    a--; b--;
    vedge[a][b] = 1;
    vedge[b][a] = 1;
  }

  std::vector<bool> visited(N, false);
  visited[0] = true;
  ll ans = dfs(0, visited);

  std::cout << ans << std::endl;

  return 0;
}
