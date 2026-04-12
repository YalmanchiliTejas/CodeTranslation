#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> min_cnt(26, 51);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < s.size(); j++) {
      int pos = (int)(s[j] - 'a');
      cnt[pos]++;
    }
    for (int j = 0; j < 26; j++) {
      min_cnt[j] = min(min_cnt[j], cnt[j]);
    }
  }

  string ans = "";
  for (int i = 0; i < 26; i++) {
    if (min_cnt[i] < 51) {
      for (int j = 0; j < min_cnt[i]; j++) {
        ans += (char)('a' + i);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
