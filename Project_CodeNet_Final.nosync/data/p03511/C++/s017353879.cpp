/**
 *    author:  tourist
 *    created: 12.12.2019 18:56:59       
**/
#include <bits/stdc++.h>

using namespace std;

string rep(string s, int k) {
  string t = "";
  for (int i = 0; i < k; i++) {
    t += s;
  }
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int len;
  cin >> len;
  string s;
  string t;
  cin >> s;
  cin >> t;
  int ns = (int) s.size();
  int nt = (int) t.size();
  string ans = "}";
  for (int i = 0; i * ns <= len; i++) {
    if ((len - i * ns) % nt == 0) {
      int j = (len - i * ns) / nt;
      ans = min(ans, rep(s, i) + rep(t, j));
      ans = min(ans, rep(t, j) + rep(s, i));
      break;
    }
  }
  for (int i = len / ns; i >= 0; i--) {
    if ((len - i * ns) % nt == 0) {
      int j = (len - i * ns) / nt;
      ans = min(ans, rep(s, i) + rep(t, j));
      ans = min(ans, rep(t, j) + rep(s, i));
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
