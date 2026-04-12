#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto&& w : s) cin >> w;
  vector<int> a(26, 0), b(26, 0);
  for (int j = 0; j < s[0].size(); j++) {
    a[s[0][j] - 'a']++;
  }
  for (int i = 1; i < s.size(); i++) {
    b.assign(26, 0);

    for (int j = 0; j < s[i].size(); j++) {
      b[s[i][j] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      a[j] = min(a[j], b[j]);
    }
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    ans += string(a[i], 'a' + i);
  }
  cout << ans << endl;
}