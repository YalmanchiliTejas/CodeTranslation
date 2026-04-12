#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, l, r;
  while (cin >> n >> l >> r, n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int x = l; x <= r; x++) {
      int i = 0;
      while (i < n && x % a[i] != 0) {
        i++;
      }
      if (i % 2 == 0) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
