#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s.push_back(s[0]);
  s.push_back(s[1]);
  bool f = false;
  vector<int> ans(n + 2); // 0 sheep, 1 wolf
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans[0] = i, ans[1] = j;
      for (int i = 2; i <= n+1; i++) {
        if (ans[i-1] == 0) {
          // previous sheep
          ans[i] = s[i-1] == 'o' ? ans[i-2] : !ans[i-2];
        } else {
          // previous wolf
          ans[i] = s[i-1] == 'x' ? ans[i-2] : !ans[i-2];
        }
      }
      if (ans[0] == ans[n] && ans[1] == ans[n+1]) {
        f = true;
        break;
      }
    }
    if (f) break;
  }
  
  if (f) {
    for (int i = 0; i < n; i++) cout << (ans[i] == 0 ? 'S' : 'W');
  } else {
    cout << -1;
  }
  cout << endl;
  return 0;
}
