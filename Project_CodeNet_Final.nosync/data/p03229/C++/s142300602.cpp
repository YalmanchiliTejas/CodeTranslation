#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef int64_t Int;
Int mod = 1e9+7;

int main() {
  Int n;
  cin >> n;
  vector<Int> a(n);
  for (Int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  if (n % 2 == 0) {
    Int res = 0;
    for (Int i = 0; i < n; i++) {
      if (i < n / 2) {
        res -= a[i] * 2;
      }
      else {
        res += a[i] * 2;
      }
    }
    dump(res + a[n / 2 - 1] - a[n / 2]);
  }
  else {
    Int res1 = 0;
    Int res2 = 0;
    for (Int i = 0; i < n; i++) {
      if (i < n / 2) {
        res1 -= a[i] * 2;
      }
      else {
        res1 += a[i] * 2;
      }
    }
    res1 -= a[n / 2] + a[n / 2 + 1];
    for (Int i = 0; i < n; i++) {
      if (i <= n / 2) {
        res2 -= a[i] * 2;
      }
      else {
        res2 += a[i] * 2;
      }
    }
    
    res2 += a[n / 2] + a[n / 2 - 1];
   //  cout << res1 << " " << res2 << endl;
    dump(max(res1, res2));
  }
  return 0;
}
