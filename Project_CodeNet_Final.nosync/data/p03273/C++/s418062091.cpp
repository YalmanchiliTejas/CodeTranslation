#pragma region kyomukyomupurin

/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-05-10 19:13:16
 **/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using int64 = long long;

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int flag = 0;
  for (auto e : vec) os << (flag++ ? ", " : "{") << e;
  return os << (vec.empty() ? "{}" : "}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int flag = 0;
  for (auto e : st) os << (flag++ ? ", " : "{") << e;
  return os << (st.empty() ? "{}" : "}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int flag = 0;
  for (auto e : mp) os << (flag++ ? ", " : "{") << e;
  return os << (mp.empty() ? "{}" : "}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
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

#pragma endregion kyomukyomupurin

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w; cin >> h >> w;
  char board[h][w];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> board[i][j];
    }
  }

  bool use[101][101];
  fill(use[0], use[101], true);

  for (int i = 0; i < h; ++i) {
    bool flag = false;
    for (int j = 0; j < w; ++j) flag |= (board[i][j] == '#');
    if (!flag) {
      for (int k = 0; k < w; ++k) use[i][k] = false;
    }
  }

  for (int i = 0; i < w; ++i) {
    bool flag = false;
    for (int j = 0; j < h; ++j) flag |= (board[j][i] == '#');
    if (!flag) {
      for (int k = 0; k < h; ++k) use[k][i] = false;
    }
  }

  for (int i = 0; i < h; ++i) {
    bool flag = true;
    if (all_of(use[0], use[101], [](bool e){ return !e; })) {
      flag = false;
    }
    for (int j = 0; j < w; ++j) {
      if (use[i][j]) cout << board[i][j];
    }
    if (flag) cout << '\n';
  }

  return 0;
}