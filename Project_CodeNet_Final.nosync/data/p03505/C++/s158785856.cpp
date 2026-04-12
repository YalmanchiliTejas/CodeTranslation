#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  long long k, a, b;
  cin >> k >> a >> b;
  if (a >= k) {
    cout << 1 << endl;
  } else {
    long long c = a - b;
    if (c <= 0) {
      cout << -1 << endl;
    } else {
      k -= a;
      cout << ((k + c - 1) / c) * 2 + 1 << endl;
    }
  }
  return 0;
}