#include <cassert>
#include <iostream>
#include <vector>

using llong = long long;

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

template <class T> inline bool chmax(T &a, const T &b) {
  return (a < b) ? a = b, true : false;
}

template <class T> inline bool chmin(T &a, const T &b) {
  return (a > b) ? a = b, true : false;
}

template <class T> inline void chadd(T &a, const T &b) { a += b, a &= MOD; }

int main() {
  // Input
  int numArray;
  std::cin >> numArray;
  assert(1 <= numArray and numArray <= 3000);
  std::vector<llong> gain(1 + numArray);
  for (int i = 1; i <= numArray; ++i) {
    std::cin >> gain[i];
    assert(1 <= gain[i] and gain[i] <= 1.0e+9);
  }

  // Initialization
  auto dp = vectors<llong>(1 + numArray, 1 + numArray, -LINF);

  // Initial condition
  for (int i = 1; i <= numArray; ++i)
    dp[i][i] = gain[i];

  // DP main
  for (int k = 0; k < numArray; ++k) {
    for (int i = 1; i <= numArray - k; ++i) {
      int j = i + k;
      assert(1 <= i and i <= j and j <= numArray);
      if (j + 1 <= numArray)
        chmax(dp[i][j + 1], gain[j + 1] - dp[i][j]);
      if (i - 1 >= 1)
        chmax(dp[i - 1][j], gain[i - 1] - dp[i][j]);
    }
  }

  // Output
  std::cout << dp[1][numArray] << std::endl;

  return 0;
}
