#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h, w = 0, ans = 0;
  for (cin >> n; n--;) {
    cin >> h;
    if (h >= w) ans++;
    w = max(w, h);
  }
  cout << ans;
  return 0;
}