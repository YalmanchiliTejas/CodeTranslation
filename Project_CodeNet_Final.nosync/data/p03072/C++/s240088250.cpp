#include <bits/stdc++.h>

using namespace std;



int main() {
  int n, ans=1, mx;
  cin >> n;
  cin >> mx;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    if (i && a>=mx) {
      mx = a;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
