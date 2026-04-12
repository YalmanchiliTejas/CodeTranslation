#include <bits/stdc++.h>

using namespace std;

int n, cnt[100][26];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int l = 0; l < (int) s.size(); l++) {
      int tmp = s[l] - 'a';
      cnt[i][tmp]++;
    }
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    int sml = 1e9;
    for (int j = 0; j < n; j++) {
      sml = min(sml, cnt[j][i]);
    }
    for (int l = 0; l < sml; l++) {
      ans += (char) ('a' + i);
    }
    //cout << (char) ('a' + i) << ' ' << sml << endl;
  }
  cout << ans << endl;
  return 0;
}
