#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <queue>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<int> a(N);
  for (auto& ai: a) scanf("%d", &ai);

  int const inf = 2e9;

  std::multiset<int> b;
  for (size_t i = 0; i < N; ++i) {
    auto it = b.lower_bound(a[i]);
    if (it == b.begin()) {
      b.insert(a[i]);
      continue;
    }
    b.erase(--it);
    b.insert(a[i]);
  }
  printf("%zu\n", b.size());
}
