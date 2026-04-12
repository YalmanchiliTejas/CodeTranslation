#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
  int n, mx = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (mx <= x) {
      ++ans;
    }
    mx = max(mx, x);
  }
  cout << ans << endl;
}
