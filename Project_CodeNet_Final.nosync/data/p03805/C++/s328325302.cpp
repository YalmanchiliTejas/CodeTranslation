#define NDEBUG
//
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

int main(void) {
  int N, M;
  std::cin >> N >> M;
  std::multimap<int, int> map;
  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    assert(0 < a && a < b && b <= N);
    map.emplace(a, b);
    map.emplace(b, a);
  }
  std::vector<bool> visited(N);
  visited.resize(N);
  int ans = 0;
  std::fill(visited.begin(), visited.end(), false);

  std::function<void(int)> dfs = [&](int v) {
    if (std::all_of(visited.begin(), visited.end(), [](bool a) { return a; })) {
      ans += 1;
      return;
    }
    auto it = map.find(v);
    assert(it != map.end());
    do {
      auto v2 = it->second;
      if (visited.at(v2 - 1))
        continue;
      visited.at(v2 - 1) = true;
      dfs(v2);
      visited.at(v2 - 1) = false;
    } while ((++it)->first == v);
  };
  visited.at(0) = true;
  dfs(1);
  std::cout << ans << std::endl;
  return 0;
}
