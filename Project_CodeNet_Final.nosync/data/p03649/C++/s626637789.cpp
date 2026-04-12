#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool done = false;
  long long ans = 0;
  while (!done) {
    done = true;
    for (int i = 0; i < n; i++) if (a[i] >= n) {
      done = false;
      long long del = a[i] / n;
      ans += del;
      a[i] -= del * n;
      for (int j = 0; j < n; j++) if (j != i) a[j] += del;
    }
  }
  cout << ans << '\n';
  return 0;
}