#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

static const int IINF = 1 << 30;
static const long long LINF = 1LL << 60;
static const long long MOD = 1.0e+9 + 7;

template <typename T> std::vector<T> vectors(std::size_t n, T val) {
  return std::vector<T>(n, val);
}

template <typename T, typename... Args>
auto vectors(std::size_t n, Args... args) {
  return std::vector<decltype(vectors<T>(args...))>(n, vectors<T>(args...));
}

template <class T> inline bool chmin(T &a, const T &b) {
  return (a > b) ? a = b, true : false;
}

template <class T> inline bool chmax(T &a, const T &b) {
  return (a < b) ? a = b, true : false;
}

template <class T> inline void chadd(T &a, const T &b) { a += b, a %= MOD; }

int main() {
  // Input
  int N;
  std::cin >> N;
  assert(1 <= N and N <= 20);
  std::vector<int> H(1 + N);
  for (int i = 1; i <= N; ++i) {
    std::cin >> H[i];
    assert(1 <= H[i] and H[i] <= 100);
  }

  // Main
  int currentMax = -1;
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    if (currentMax <= H[i])
      res += 1;
    chmax(currentMax, H[i]);
  }

  // Output
  std::cout << res << std::endl;

  return 0;
}
