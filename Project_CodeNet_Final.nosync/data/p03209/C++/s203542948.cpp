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

int64 cnt(int64 N, int64 X, vector<int64>& all, vector<int64>& p) {
  if (N == 0) return 1;
  if (X <= 1) return 0;
  if (X <= 1 + all[N - 1]) return cnt(N - 1, X - 1, all, p);
  if (X == 2 + all[N - 1]) return p[N - 1] + 1;
  if (X <= all[N - 1] * 2 + 2)
    return p[N - 1] + 1 + cnt(N - 1, X - all[N - 1] - 2, all, p);
  return p[N - 1] * 2 + 1;
}

int main() {
  int64 N, X;
  cin >> N >> X;
  vector<int64> all(51);
  vector<int64> p(51);
  all[0] = 1;
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    all[i] = all[i - 1] * 2 + 3;
    p[i] = p[i - 1] * 2 + 1;
  }
  debug(all, p);
  int64 ans = cnt(N, X, all, p);
  cout << ans << endl;
  return 0;
}
