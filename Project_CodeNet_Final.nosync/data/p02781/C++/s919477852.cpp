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
  std::string s;
  std::cin >> s;
  int64_t k;
  std::cin >> k;

  std::vector<int64_t> dp1(k + 1, 0), dp2(k + 1, 0);
  dp1[0] = 1;
  for (const auto c : s) {
    int n = c - '0';
    std::vector<int64_t> dp1t(k + 1, 0), dp2t(k + 1, 0);

    for (int64_t i = 0; i < k + 1; i++) {
      dp2t[i] += dp2[i];
      if (i < k) {
        dp2t[i + 1] += 9 * dp2[i];
      }
    }
    for (int64_t i = 0; i < k + 1; i++) {
      if (n == 0) {
        dp1t[i] += dp1[i];
      } else {
        if (i < k) {
          dp1t[i + 1] += dp1[i];
          dp2t[i + 1] += (n - 1) * dp1[i];
        }
        dp2t[i] += dp1[i];
      }
    }
    std::swap(dp1, dp1t);
    std::swap(dp2, dp2t);
  }

  std::cout << dp1[k] + dp2[k] << std::endl;

  return 0;
}
