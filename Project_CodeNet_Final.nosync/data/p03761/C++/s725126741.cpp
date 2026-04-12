#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<string> s(n);
  vector<vector<int> > bucket(n, vector<int>(26));
  rep(i, n) {
    cin >> s[i];
    rep(j, s[i].size()) {
      bucket[i][s[i][j]-'a']++;
    }
  }

  int minCnt[26] = {};
  rep(i, 26) minCnt[i] = 1e9;
  rep(i, n) rep(j, 26) {
    minCnt[j] = min(minCnt[j], bucket[i][j]);
  }

  string ans = "";
  rep(i, 26) {
    while(minCnt[i]--) ans += (char)(i+'a');
  }

  cout << ans << '\n';
  return 0;
}
