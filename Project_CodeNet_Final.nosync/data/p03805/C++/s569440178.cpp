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

class Solver2 {
 public:
  int n, m;
  vector<set<int>> graph;
  Solver2(LL n, LL m) : n(n), m(m), graph(n){};

  void solve() {
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      graph[--a].insert(--b);
      graph[b].insert(a);
    }
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    int ans = 0;
    do {
      bool ok = true;
      for (int i = 0; i < n - 1; ++i) {
        if (graph[perm[i]].count(perm[i + 1]) == 0) ok = false;
      }
      if (ok) ans++;
    } while (next_permutation(perm.begin(), perm.end()) && perm[0] == 0);
    cout << ans << endl;
  }
};
}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(12);
  long long n = 0, m;
  std::cin >> n >> m;

  Problem::Solver2 sol(n, m);
  sol.solve();
  return 0;
}
