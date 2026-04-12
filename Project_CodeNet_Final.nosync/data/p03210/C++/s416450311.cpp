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
  Solver(LL n) : n(n){};

  void solve() {
    if(n==3 || n == 5 || n == 7 ) {
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
};
class Solver2 {
 public:
  int n, m;
  Solver2(LL n, LL m) : n(n), m(m){};

  void solve() {
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
