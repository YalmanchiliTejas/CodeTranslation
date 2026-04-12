#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmin(T &a, T b) { /* {{{ */
  if (a > b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  cin >> N;
  vector<int> C(26, 1e9);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int j = 0; j < s.length(); j++) {
      int c = s[j] - 'a';
      cnt[c]++;
    }
    for (int j = 0; j < 26; j++) {
      chmin(C[j], cnt[j]);
    }
  }
  bool out = false;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < C[i]; j++) {
      cout << (char)('a' + i);
      out = true;
    }
  }
  if (out) cout << endl;

  return 0;
}
/* vim:set fdm=marker: */
