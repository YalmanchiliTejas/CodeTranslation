#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 0
constexpr int kMod = 1000000007;
typedef long long LL;

std::vector<std::vector<int>> edges;

int dfs(int index, std::set<int> visited) {
  visited.insert(index);
  if (visited.size() == edges.size() - 1) return 1;

#if DEBUG
  std::cout << index << ":";
  for (int v : edges[index]) {
    if (visited.count(v)) continue;
    std::cout << v << " ";
  }
  std::cout << std::endl;
#endif

  int sum = 0;
  for (int v : edges[index]) {
    if (visited.count(v)) continue;
    sum += dfs(v, visited);
  }
  return sum;
}

int main() {
  int N, M; std::cin >> N >> M;
  edges = std::vector<std::vector<int>>(N+1);

  for (int m = 0; m < M; ++m) {
    int a, b; std::cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  std::set<int> visited;
  std::cout << dfs(1, visited) << std::endl;
}
