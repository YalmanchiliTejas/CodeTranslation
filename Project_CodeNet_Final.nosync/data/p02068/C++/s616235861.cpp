#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <set>

void neko(std::set<intmax_t>& divs, intmax_t a) {
  for (intmax_t i = 2; i*i <= a; ++i) {
    if (a % i == 0) {
      divs.insert(i);
      a /= i;
    }
  }
  if (a > 1) divs.insert(a);
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n);
  for (auto& ai: a) scanf("%jd", &ai);

  std::set<intmax_t> divs;
  for (auto ai: a)
    neko(divs, ai);

  intmax_t res = 0;
  for (auto d: divs) {
    intmax_t cur = 0;
    for (auto ai: a) {
      if (ai % d != 0) continue;
      cur += ai;
    }
    res = std::max(res, cur);
  }

  printf("%jd\n", res);
}

