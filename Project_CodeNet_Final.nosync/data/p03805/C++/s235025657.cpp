#include <iostream>
#include <assert.h>
#include <vector>

void dfs(int32_t node, std::vector<std::vector<int32_t>>& graph,
        std::vector<bool>& visiting, int32_t& numVisit, int32_t& res) {
  if (visiting[node]) { return;}
  visiting[node] = true;
  numVisit++;
  if (numVisit == (int32_t)graph.size()) {
    res++;
  } else {
    for (auto next : graph[node]) {
      dfs(next, graph, visiting, numVisit, res);
    }
  }
  visiting[node] = false;
  numVisit--;
  return;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int32_t>> graph(N);
  for (int32_t i = 0; i < M; i++) {
    int32_t a,b;
    std::cin >> a >> b;
    graph[a-1].emplace_back(b-1);
    graph[b-1].emplace_back(a-1);
  }

  std::vector<bool> visiting(N,false);
  int32_t numVisit = 0;
  int32_t res = 0;
  dfs(0, graph, visiting, numVisit, res);
  std::cout << res << std::endl;
  return 0;
}
