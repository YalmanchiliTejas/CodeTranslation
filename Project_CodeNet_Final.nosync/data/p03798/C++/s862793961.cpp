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
  int64_t n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::string a[] = {"SS", "SW", "WS", "WW"};

  const auto same = [](auto i) {
    if (i == 'S') {
      return 'S';
    } else {
      return 'W';
    }
  };
  const auto rev = [](auto i) {
    if (i == 'S') {
      return 'W';
    } else {
      return 'S';
    }
  };


  for (int64_t i = 1; i < n; i++) {
    for (auto &j : a) {
      if (s[i] == 'o' && j[i] == 'S') {
        j.push_back(same(j[i - 1]));
      } else if (s[i] == 'o') {
        j.push_back(rev(j[i - 1]));
      } else if (j[i] == 'S') {
        j.push_back(rev(j[i - 1]));
      } else {
        j.push_back(same(j[i - 1]));
      }
    }
  }

  for (auto &j : a) {
    if (j.front() == j.back()) {
      j.pop_back();
      if ((((j.front() == 'S' && s.front() == 'o')
        || (j.front() == 'W' && s.front() == 'x')) && j[1] == j.back()) ||
        (((j.front() == 'S' && s.front() == 'x')
        || (j.front() == 'W' && s.front() == 'o')) && j[1] != j.back())) {
        std::cout << j << std::endl;
        return 0;
      }
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}
