#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;

  map<char, int> mn;
  for (char c = 'a';; c++) {
    mn[c] = 1e9;
    if (c == 'z') {
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    map<char, int> cnt;

    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      cnt[s[j]]++;
    }

    for (char c = 'a';; c++) {
      mn[c] = min(mn[c], cnt[c]);
      if (c == 'z') {
        break;
      }
    }
  }

  string ans = "";
  for (char c = 'a';; c++) {
    for (int i = 0; i < mn[c]; i++) {
      ans = ans + c;
    }

    if (c == 'z') {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}