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
  const int sizeG = 100;
  int a, b;
  vector<vector<int>> d, lBound;
  Solver2(LL n, LL m) : a(n), b(m), d(a + 1, vector<int>(b + 1)), lBound(sizeG + 1, vector<int>(sizeG + 1, 0)){};
  void impossible() {
    cout << "Impossible" << endl;
    exit(0);
  }
  void solve() {
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        cin >> d[i][j];
      }
    }
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        for (int k = 0; k <= sizeG; ++k) {
          for (int l = 0; l <= sizeG; ++l) {
            //path with 'X' : k times
            //path with 'Y' : l times
            lBound[k][l] = max(lBound[k][l], d[i][j] - i * k - j * l);
          }
        }
      }
    }
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        int minDistance = INF;
        for (int k = 0; k <= sizeG; ++k) {
          for (int l = 0; l <= sizeG; ++l) {
            minDistance = min(minDistance, i * k + j * l + lBound[k][l]);
          }
        }
        if (minDistance > d[i][j]) impossible();
      }
    }
    cout << "Possible" << endl;
    cout << sizeG * 2 + 2 << ' ' << (sizeG + 1) * (sizeG + 1) + 2 * sizeG << endl;
    for (int k = 0; k <= sizeG; ++k) {
      for (int l = 0; l <= sizeG; ++l) {
        cout << k + 1 << ' ' << sizeG * 2 + 2 - l << ' ' << lBound[k][l] << endl;
      }
    }
    for (int i = 0; i < sizeG; ++i) {
      cout << i + 1 << ' ' << i + 2 << " X" << endl;
      cout << i + sizeG + 2 << ' ' << i + sizeG + 3 << " Y" << endl;
    }

    cout << 1 << ' ' << sizeG * 2 + 2 << endl;
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
