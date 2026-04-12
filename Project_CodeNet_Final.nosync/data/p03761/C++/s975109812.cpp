#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<vector<int>> cnt_i(n, vector<int>(26, 0));
  rep(i, n) rep(j, s[i].size()) ++cnt_i[i][s[i][j] - 'a'];

  vector<int> cnt(26, 100);
  rep(i, n) rep(j, 26) cnt[j] = min(cnt[j], cnt_i[i][j]);

  string ans = "";
  rep(i, 26) rep(j, cnt[i]) ans += i + 'a';
  cout << ans << endl;
  return 0;
}