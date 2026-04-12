#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
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

template <class T> inline void chadd(T &a, const T &b) {
  a += b, a %= MOD;
  // TODO minus case
}

template <class T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
  if (v.empty())
    return s;
  s << *v.begin();
  for (auto iter = v.begin() + 1; iter != v.end(); ++iter)
    if (std::is_fundamental<T>::value)
      s << " " << *iter;
    else
      s << std::endl << *iter;
  return s;
}

int main() {
  // Input
  long long N;
  std::cin >> N;

  std::vector<long long> A(N);
  for (int i = 0; i < N; ++i)
    std::cin >> A[i];

  std::reverse(A.begin(), A.end());

  // for (int i = 0; i < N; ++i)
  //   std::cout << A[i] << " ";

  std::vector<long long> dp(N, LINF);
  // dp[i] = 増加部分列の長さが i + 1 の場合の、最終要素の最小値

  for (int i = 0; i < N; ++i)
    // *std::lower_bound(dp.data(), dp.data() + N, A[i]) = A[i];
    *std::upper_bound(dp.data(), dp.data() + N, A[i]) = A[i];

  std::cout << std::lower_bound(dp.data(), dp.data() + N, LINF) - dp.data() << std::endl;

  return 0;
}
