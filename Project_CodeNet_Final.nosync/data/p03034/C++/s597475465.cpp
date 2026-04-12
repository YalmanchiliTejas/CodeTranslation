#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> s(n);
  for (auto& si: s) scanf("%jd", &si);

  intmax_t res = 0;
  for (size_t c = 1; c <= n-1; ++c) {
    intmax_t cur = 0;
    std::vector<bool> reached(n);
    for (size_t kc = 0; kc <= n-1; kc += c) {
      if (reached[n-1-kc] || reached[kc]) break;
      if (kc == n-1-kc) break;
      reached[n-1-kc] = reached[kc] = true;
      if (n-1-kc < c) break;
      // fprintf(stderr, "+ [%zu] + [%zu]\n", kc, n-1-kc);
      cur += s[n-1-kc] + s[kc];
      res = std::max(res, cur);
    }
    // fprintf(stderr, "===\n");
  }
  printf("%jd\n", res);
}
