#include <bits/stdc++.h>

template <typename InputIterator>
typename InputIterator::value_type
summation(InputIterator first, InputIterator last) {
  using T = typename InputIterator::value_type;
  T *p = new T();
  const auto sum = std::accumulate(first, last, *p);
  delete p;
  return sum;
}
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v);
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p);
template <typename T>
std::istream& operator>> (std::istream &stream, std::vector<T> &v) {
  for (auto &i : v) {
    stream >> i;
  }
  return stream;
}
template <typename T1, typename T2>
std::istream& operator>> (std::istream &stream, std::pair<T1, T2> &p) {
  stream >> p.first >> p.second;
  return stream;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  std::cin >> s;
  std::vector<std::vector<int>> c(26, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      c[s[i][j] - 'a'][i]++;
    }
  }

  std::vector<int> al(26);

  for (int i = 0; i < 26; i++) {
    al[i] = *std::min_element(c[i].cbegin(), c[i].cend());
  }

  std::string ans("");

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < al[i]; j++) {
      ans.push_back(static_cast<char>('a' + i));
    }
  }

  std::cout << ans << std::endl;
  return 0;
}