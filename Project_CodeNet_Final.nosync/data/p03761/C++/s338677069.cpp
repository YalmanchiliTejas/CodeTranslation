#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, j;
  cin >> n;
  vector<string> s(n);
  for (i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> cnt(n, vector<int>(26, 0));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < s[i].size(); ++j) {
      ++cnt[i][s[i][j] - 'a'];
    }
  }
  string ans;
  vector<int> tmp(26, 51);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < 26; ++j) {
      tmp[j] = min(tmp[j], cnt[i][j]);
    }
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    if (tmp[c - 'a'] != 0) {
      for (i = 0; i < tmp[c - 'a']; ++i) {
        ans.push_back(c);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}