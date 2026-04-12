#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
  sort(b, b + n);
  int l = b[n / 2 - 1], r = b[n / 2];
  for (int i = 0; i < n; i++) {
    if (a[i] <= l) cout << r << endl;
    else cout << l << endl;
  }
  return 0;
}
