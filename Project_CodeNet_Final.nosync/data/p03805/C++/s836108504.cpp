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
  int64_t n, m;
  std::cin >> n >> m;
  std::vector<std::set<int>> no(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    no[a].insert(b);
    no[b].insert(a);
  }

  std::vector<bool> flag(n, false);
  flag[0] = true;

  std::multimap<int, std::vector<bool>> q;
  for (const auto i : no[0]) {
    q.insert({i, flag});
  }
  int count = 0;

  while (!q.empty()) {
    std::multimap<int, std::vector<bool>> tmp;

    for (auto i : q) {
      i.second[i.first] = true;
      if (std::all_of(i.second.cbegin(), i.second.cend(), [] (auto i) {
        return i;})) {
        count++;
      } else {
        for (const auto j : no[i.first]) {
          if (!i.second[j]) {
            tmp.insert({j, i.second});
          }
        }
      }
    }

    std::swap(q, tmp);
  }

  std::cout << count << std::endl;
  return 0;
}