#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while (true) {
    int n, l, r;
    cin >> n >> l >> r;
    if (n + l + r == 0) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    
    int ans = 0;
    for (int i = l; i <= r; i++) {
      bool flag = false;
      for (int j = 0; j < n; j++) {
        if (i % a.at(j) == 0 && j % 2 == 0) {
          ans++;
          flag = true;
          break;
        }
        else if (i % a.at(j) == 0) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        if (n % 2 == 0) ans++;
      }
    }
    
    cout << ans << '\n';
  }
}
