#include <algorithm>
#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<uint32_t>>;

uint32_t dfs(const Graph& G, uint32_t node, std::vector<bool>& visit) {
  visit[node] = true;
  if (std::all_of(visit.begin(), visit.end(), [](bool v) { return v; })) {
    visit[node] = false;
    return 1;
  }

  uint32_t count = 0;
  for (auto&& to : G[node]) {
    if (visit[to]) continue;
    count += dfs(G, to, visit);
  }

  visit[node] = false;
  return count;
}

int main() {
  uint32_t N = 0, M = 0;
  std::cin >> N >> M;
  Graph G(N);
  for (size_t i = 0; i < M; i++) {
    uint32_t a = 0, b = 0;
    std::cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  std::vector<bool> visit(N, false);
  std::cout << dfs(G, 0, visit) << std::endl;

  return 0;
}