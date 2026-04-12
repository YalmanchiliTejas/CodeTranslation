#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
#define uint uint64_t
#ifdef _DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif
using namespace std;

// accumlation
void solve() {
  const int MOD = 1000000007;
  int n;
  cin >> n;

  vector<uint> A(n);
  vector<uint> B(n + 1, 0);

  uint subsum = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    A.at(i) = num;
    subsum += num;
    B.at(i + 1) = subsum;
  }

  uint ans = 0;
  for (int i = 0; i < n; i++) {
    debug(A.at(i), B.at(n), B.at(i + 1));
    ans += A.at(i) * ((B.at(n) - B.at(i + 1)) % MOD);
    ans %= MOD;
  }
  cout << ans << endl;
}

void wrapper() {
  rep(i, 3) {
    cout << "[TEST " << (i + 1) << "]\n";
    solve();
    cout << "\n";
  }
}

int main() {
  fastIO;
#ifdef _DEBUG
  wrapper();
#else
  solve();
#endif
}
