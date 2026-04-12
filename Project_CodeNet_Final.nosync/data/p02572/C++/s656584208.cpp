#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int64_t ans = 0, s = 0;
  constexpr int mod = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ans = (ans + x * s) % mod;
    s = (s + x) % mod;
  }
  cout << ans << endl;
  return 0;
}

