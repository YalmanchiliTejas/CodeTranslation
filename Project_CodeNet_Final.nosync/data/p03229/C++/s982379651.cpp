#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

intmax_t f(std::deque<intmax_t> const& a) {
  size_t n = a.size();
  intmax_t res = 0;
  for (size_t i = 1; i < n; ++i)
    res += std::abs(a[i]-a[i-1]);

  // for (size_t i = 0; i < n; ++i)
  //   fprintf(stderr, "%jd%c", a[i], i+1<n? ' ': '\n');

  return res;
}

intmax_t g(std::deque<intmax_t> a) {
  size_t n = a.size();
  std::deque<intmax_t> res;
  for (size_t i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      res.push_back(a.front());
      a.pop_front();
    } else {
      res.push_back(a.back());
      a.pop_back();
    }
  }

  intmax_t score = f(res);
  {
    intmax_t x = res.back();
    res.pop_back();
    res.push_front(x);
  }
  score = std::max(score, f(res));
  return score;
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::deque<intmax_t> a(n);
  for (auto& ai: a) scanf("%jd", &ai);
  std::sort(a.begin(), a.end());

  intmax_t score = g(a);
  std::reverse(a.begin(), a.end());
  score = std::max(score, g(a));

  printf("%jd\n", score);
}
