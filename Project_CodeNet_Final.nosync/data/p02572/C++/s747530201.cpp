#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <queue>

#define CHECK_IMPL1(cond)                \
    if (!(cond)) {                       \
      DEBUG("expected cond: " << #cond); \
      assert(cond);                      \
    }

#define CHECK_IMPL2(cond, message)                                              \
    if (!(cond)) {                                                              \
      DEBUG("expected cond: " << #cond << " failed with message: " << message); \
      assert(cond);                                                             \
    }

#define CHECK_IMPL(_1, _2, NAME, ...) NAME
#define CHECK(...) CHECK_IMPL(__VA_ARGS__, CHECK_IMPL2, CHECK_IMPL1, CHECK_IMPL0)(__VA_ARGS__)

#ifdef __APPLE__
#define DEBUG(message) std::cerr << message << std::endl;
#else
#define DEBUG(message)
#endif

constexpr int MOD = 1e9 + 7;

int add(int64_t a, int64_t b) {
  int64_t s = a + b;
  return ((s + MOD) % MOD + MOD) % MOD;
}

int mul(int64_t a, int64_t b) {
  return (a * b) % MOD;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int64_t s = sum - a[i];
    ans = add(ans, mul(a[i], s % MOD));
  }

  std::cout << mul(ans, 500000004) << std::endl;
}

int main() {
#ifdef __APPLE__
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  //std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
