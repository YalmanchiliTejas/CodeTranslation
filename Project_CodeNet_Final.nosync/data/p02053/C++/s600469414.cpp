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
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char>> c(H, std::vector<char>(W));
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      std::cin >> c[i][j];

  // Main
  std::pair<int, int> lu = std::make_pair(H, W);
  std::pair<int, int> rd = std::make_pair(-1, -1);
  std::pair<int, int> ru = std::make_pair(H, -1);
  std::pair<int, int> ld = std::make_pair(0, W);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (c[i][j] == '.')
        continue;
      if (i + j < lu.first + lu.second)
        lu.first = i, lu.second = j;
      if (i + j > rd.first + rd.second)
        rd.first = i, rd.second = j;
      if (i + (W - j) < ru.first + (W - ru.second))
        ru.first = i, ru.second = j;
      if ((H - i) + j < (H - ld.first) + ld.second)
        ld.first = i, ld.second = j;
    }
  }

  // std::cout << lu.first << " " << lu.second << std::endl;
  // std::cout << rd.first << " " << rd.second << std::endl;
  // std::cout << ru.first << " " << ru.second << std::endl;
  // std::cout << ld.first << " " << ld.second << std::endl;

  int res = 0;
  // Output
  chmax(res, (rd.first - lu.first) + (rd.second - lu.second));
  chmax(res, (ld.first - ru.first) + (ru.second - ld.second));
  std::cout << res << std::endl;

  return 0;
}

