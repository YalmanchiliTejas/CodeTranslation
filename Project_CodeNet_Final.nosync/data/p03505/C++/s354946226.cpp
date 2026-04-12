#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  long long k, a, b;
  cin >> k >> a >> b;
  if (a >= k) {
    cout << 1 << '\n';
  } else {
    if (a > b) {
      cout << (k - a + (a - b) - 1) / (a - b) * 2 + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}