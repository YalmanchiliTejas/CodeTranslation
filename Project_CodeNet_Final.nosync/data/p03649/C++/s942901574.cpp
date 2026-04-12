/**
 *    author:  tourist
 *    created: 20.11.2019 13:51:47       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  while (true) {
    bool any = false;
    for (int i = 0; i < n; i++) {
      long long steps = a[i] / n;
      any |= !!steps;
      ans += steps;
      a[i] -= steps * (n + 1);
      for (int j = 0; j < n; j++) {
        a[j] += steps;
      }
    }
    if (!any) break;
  }
  cout << ans << '\n';
  return 0;
}
