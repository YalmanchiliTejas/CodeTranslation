#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type summation(InputIterator first,
                                             InputIterator last) {
  return std::accumulate(first, last, typename InputIterator::value_type());
}
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream &operator>>(std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> a(n);

  std::cin >> a;

  int64_t dp[6], dp_tmp[6];
  dp[0] = 0;     // -1個で最後をとってない
  dp[1] = 0;     // -1個で最後をとった
  dp[2] = a[0];  // 0個で最後をとってない
  dp[3] = a[1];  // 0個で最後をとった
  dp[4] = 0;     // 1個で最後をとってない
  dp[5] = 0;     // 1個で最後をとった.

  for (int64_t i = 2; i < n; i++) {
    if (i % 2 == 0) {
      // 奇数.
      dp_tmp[0] = std::max(dp[0], dp[1]);  // 0
      dp_tmp[1] = 0;                       // 0
      dp_tmp[2] = std::max(dp[2], dp[3]);
      dp_tmp[3] = dp[0] + a[i];
      dp_tmp[4] = 0;  // 0
      dp_tmp[5] = dp[2] + a[i];
    } else {
      // 偶数.
      dp_tmp[0] = std::max(dp[2], dp[3]);
      dp_tmp[1] = dp[0] + a[i];
      dp_tmp[2] = dp[5];
      dp_tmp[3] = dp[2] + a[i];
      dp_tmp[4] = 0;  // 0
      dp_tmp[5] = 0;
    }
    std::swap(dp, dp_tmp);
  }

  std::cout << std::max(dp[2], dp[3]) << std::endl;

  return 0;
}