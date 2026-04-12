#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

typedef long long ll;
const ll INF = 1e18;
const ll MAX_N = 8;

ll N, M;
bool graph[MAX_N][MAX_N];

ll dfs(ll v, bool visited[MAX_N]) {
  bool all_visited = true;

  for (ll i = 0; i < N; i++) {
    if (visited[i] == false) {
      all_visited = false;
    }
  }

  if (all_visited) {
    return 1;
  }

  int ret = 0;

  for (ll i = 0; i < N; i++) {
    if (graph[v][i] == false) {
      continue;
    }
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    ret += dfs(i, visited);
    visited[i] = false;
  }

  return ret;
}

int main(int argc, char* argv[])
{
  std::cin >> N >> M;

  for (ll i = 0; i < M; i++) {
    ll A, B;
    std::cin >> A >> B;
    graph[A-1][B-1] = true;
    graph[B-1][A-1] = true;
  }

  bool visited[MAX_N];
  for (ll i = 0; i < N; i++) {
    visited[i] = false;
  }

  visited[0] = true;
  
  ll ans = dfs(0, visited);
  std::cout << ans << std::endl;

  return 0;
}
