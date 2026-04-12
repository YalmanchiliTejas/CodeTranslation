#include <bits/stdc++.h>

#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif
#if __cplusplus <= 201402L
template <typename T>
T gcd(T a, T b) { return ((a % b == 0) ? b : gcd(b, a % b)); }
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
#endif
using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

namespace Problem {
using namespace std;

class Solver {
 public:
  int n;
  vector<LL> a;
  vector<vector<LL>> memo;
  Solver(LL n) : n(n), a(n), memo(n + 1, vector<LL>(n + 1, LINF)){};

  void solve() {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << calc(0, 0, n) << endl;
  }
  LL calc(int turn, int lb, int ub) {
    if (memo[lb][ub] < LINF) return memo[lb][ub];
    if (lb == ub) return 0;
    LL ret;
    if (turn % 2 == 0) {
      //taro
      ret = max(calc(turn + 1, lb + 1, ub) + a[lb], calc(turn + 1, lb, ub - 1) + a[ub - 1]);
    } else {
      //jiro
      ret = min(calc(turn + 1, lb + 1, ub) - a[lb], calc(turn + 1, lb, ub - 1) - a[ub - 1]);
    }
    return memo[lb][ub] = ret;
  }
};

}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(12);
  long long n = 0;
  std::cin >> n;

  Problem::Solver sol(n);
  sol.solve();
  return 0;
}
