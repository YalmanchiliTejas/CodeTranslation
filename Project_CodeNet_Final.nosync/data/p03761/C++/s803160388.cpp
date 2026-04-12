#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;

int main() {
  int n;
  cin >> n;
  int cnt[26];
  rep(i, 26) cnt[i] = 50;
  rep(i, n) {
    string s;
    cin >> s;
    int tmp[26];
    rep(j, 26) tmp[j] = 0;
    rep(j, s.length()) ++tmp[s[j]-'a'];
    rep(j, 26) cnt[j] = min(cnt[j], tmp[j]);
  }
  rep(i, 26) {
    rep(j, cnt[i]) printf("%c", i+'a');
  }
  cout << endl;
  return 0;
}