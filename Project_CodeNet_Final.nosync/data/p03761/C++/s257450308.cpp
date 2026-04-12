#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(26, (int)1e9);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> ncnt(26, 0);
    for (auto&& c : s) {
      ncnt[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      cnt[i] = min(cnt[i], ncnt[i]);
    }
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    while (cnt[i]--) {
      ans += char('a' + i);
    }
  }
  cout << ans << '\n';
  return 0;
}