#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

main() {
  int n; cin >> n;
  int cnt[n][26]{};
  string S[n];
  rep(i, n) {
    cin >> S[i];
    rep(j, S[i].length()) rep(k, 26) {
      if (S[i][j] != 'a' + k) continue;
      cnt[i][k]++;
      break;
    }
  }
  int ans;
  rep(i, 26) {
    rep(j, n) {
      if (j == 0) {
        ans = cnt[j][i];
      } else {
        ans = min(ans, cnt[j][i]);
      }
    }
    rep(j, ans) cout << (char)('a' + i);
  }
  cout << endl;
}