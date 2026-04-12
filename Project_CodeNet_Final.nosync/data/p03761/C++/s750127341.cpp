#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<vector<int>> cnt(n, vector<int>(26, 0));
  rep(i, n) {
    cin >> s[i];
    rep(j, s[i].size()) cnt[i][s[i][j] - 'a']++;
  }

  vector<int> ans(26, 1e9);
  rep(i, 26) {
    int min_v = 1e9;
    rep(j, n) min_v = min(min_v, cnt[j][i]);
    rep(j, min_v) cout << char('a' + i);
  }
  cout << endl;
  return 0;
}
