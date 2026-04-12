#include <bits/stdc++.h>

using namespace std;

using edge_t = std::pair<int, int>;
struct vertex_t {
  std::vector<edge_t*> edges;
};

int solve(int vertexIdx, const std::vector<vertex_t>& vertices,
          const std::vector<edge_t>& edges,
          std::unordered_set<int> visitedVertexIdxes) {
  if (visitedVertexIdxes.count(vertexIdx) > 0) {
    return 0;
  }
  if (visitedVertexIdxes.size() == vertices.size() - 1) {
    return 1;
  }

  int ret = 0;
  visitedVertexIdxes.insert(vertexIdx);
  for (auto edge : vertices[vertexIdx].edges) {
    int const nextVertexIdx =
        edge->first == vertexIdx ? edge->second : edge->first;
    ret += solve(nextVertexIdx, vertices, edges, visitedVertexIdxes);
  }
  visitedVertexIdxes.erase(vertexIdx);
  return ret;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<vertex_t> vertices(n, vertex_t());
  std::vector<edge_t> edges(m);
  for (auto& e : edges) {
    std::cin >> e.first >> e.second;
    e.first--;
    e.second--;
    vertices[e.first].edges.push_back(&e);
    vertices[e.second].edges.push_back(&e);
  }
  std::unordered_set<int> visitedVertexIdxes{};
  std::cout << solve(0, vertices, edges, visitedVertexIdxes) << std::endl;
  return 0;
}
