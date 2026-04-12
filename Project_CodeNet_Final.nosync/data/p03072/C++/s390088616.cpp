#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<int> h(n);
  for (auto& hi: h) scanf("%d", &hi);

  int res = 0;
  int max = 0;
  for (size_t i = 0; i < n; ++i) {
    if (max <= h[i]) {
      ++res;
      max = h[i];
    }
  }
  printf("%d\n", res);
}
