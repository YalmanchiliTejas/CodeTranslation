#pragma region kyomukyomupurin

/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-05-02 11:44:10
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

int64 dp[202020][3];

constexpr int64 inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int64> a(n); cin >> a;

  fill(dp[0], dp[202020], -inf);

  if (n & 1) {
    dp[0][0] = a[0], dp[1][1] = a[1], dp[2][2] = a[2];
    dp[2][0] = a[0] + a[2], dp[3][1] = max(a[0], a[1]) + a[3];

    for (int i = 4; i < n; ++i) {
      dp[i][0] = dp[i - 2][0] + a[i];
      dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
      dp[i][2] = max({dp[i - 2][2], dp[i - 3][1], dp[i - 4][0]}) + a[i];
    }

    cout << max({dp[n - 1][2], dp[n - 2][1], dp[n - 3][0]}) << endl;
  } else {
    dp[0][0] = a[0], dp[1][1] = a[1], dp[2][0] = a[0] + a[2];
    for (int i = 3; i < n; ++i) {
      dp[i][0] = dp[i - 2][0] + a[i];
      dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
    }
    cout << max(dp[n - 1][1], dp[n - 2][0]) << endl;
  }

  return 0;
}