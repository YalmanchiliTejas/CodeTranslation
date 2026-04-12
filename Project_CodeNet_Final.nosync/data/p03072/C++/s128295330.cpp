#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 1;
  int m = h[0];
  for (int i = 1; i < n; i++) {
    m = max(h[i - 1], m);
    if (h[i] >= m) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}