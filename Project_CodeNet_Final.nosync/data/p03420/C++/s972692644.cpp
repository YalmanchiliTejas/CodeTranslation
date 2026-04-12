#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int64 N, K;
  cin >> N >> K;
  int64 cnt = 0;
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  for (int i = K + 1; i <= N; i++) {
    int shou = (N - K) / i + 1;
    int amari = (N - K) % i;
    if (amari + 1 >= i - K) {
      cnt += shou * (i - K);
    } else {
      cnt += shou * (amari + 1);
      cnt += (shou - 1) * (i - K - amari - 1);
      debug(i, shou, amari);
    }
    debug(i, cnt);
    // for (int j = K; j < i; j++) {
    //   if (j == 0) {
    //     cnt += (N - j) / i;
    //   } else {
    //     cnt += (N - j) / i + 1;
    //   }
    //   debug(i, j, cnt);
    // }
  }
  cout << cnt << endl;
  return 0;
}