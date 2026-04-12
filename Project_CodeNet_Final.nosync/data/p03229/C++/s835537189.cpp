#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ret = 0;
  if (!(n & 1)) {
    int m = n / 2;
    for (int i = 0; i < m - 1; i++) {
      ret += - 2 * a[i] + 2 * a[n - 1 - i];
    }
    ret += -a[m - 1] + a[m];
  } else {
    int m = n / 2;
    for (int i = 0; i < m; i++) {
      ret += -2 * a[i] + 2 * a[n - 1 - i];
    }
    ret += max(a[m - 1] - a[m], a[m] - a[m + 1]);
  }
  cout << ret << endl;
  return 0;
}