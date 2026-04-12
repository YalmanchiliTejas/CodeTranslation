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

  std::multiset<int64_t> ans;
  ans.insert(a[0]);

  for (int64_t i = 1; i < n; i++) {
    auto itr = ans.lower_bound(a[i]);
    if (itr == ans.begin()) {
      ans.insert(a[i]);
    } else {
      ans.erase(--itr);
      ans.insert(a[i]);
    }
  }
  std::cout << ans.size() << std::endl;
  return 0;
}
