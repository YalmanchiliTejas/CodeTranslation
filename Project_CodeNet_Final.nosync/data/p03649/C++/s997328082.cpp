#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

bool f(std::vector<intmax_t>& a) {
  std::sort(a.rbegin(), a.rend());
  intmax_t n = a.size();
  a[0] -= n;
  for (size_t i = 1; i < a.size(); ++i) ++a[i];
  std::sort(a.begin(), a.end());

  return !std::all_of(a.begin(), a.end(), [=](auto x) { return x < n; });
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n);
  for (auto& ai: a) scanf("%jd", &ai);

  if (std::all_of(a.begin(), a.end(), [=](auto x) { return x < intmax_t(n); }))
    return puts("0"), 0;

  intmax_t res = 0;
  while (true) {
    intmax_t s = 0;
    for (size_t i = 0; i < n; ++i)
      s += a[i] / n;

    auto b = a;
    for (size_t i = 0; i < n; ++i) {
      b[i] += (s-b[i]/n) - (b[i]/n)*n;
    }

    if (std::any_of(a.begin(), a.end(), [=](auto x) { return x >= intmax_t(n); })) {
      a = std::move(b);
      res += s;
    } else {
      break;
    }
  }

  if (std::any_of(a.begin(), a.end(), [=](auto x) { return x >= intmax_t(n); })) {
    while (f(a)) ++res;
  }
  printf("%jd\n", res);
}
