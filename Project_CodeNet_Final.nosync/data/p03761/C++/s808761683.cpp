#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> cnt(n, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      cnt[i][s[j] - 'a']++;
    }
  }

  string ans;
  for (int i = 0; i < 26; i++) {
    int mi = INT_MAX;
    for (int j = 0; j < n; j++) {
      mi = min(mi, cnt[j][i]);
    }
    for (int j = 0; j < mi; j++) {
      ans += ('a' + i);
    }
  }

  cout << ans << endl;
  return 0;
}