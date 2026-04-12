#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(26));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, s.length()) {
      v[i][s[j] - 'a']++;
    }
  }

  string ans;
  rep(i, 26) {
    int count = 100;
    rep(j, n) {
      count = min(count, v[j][i]);
    }
    rep(j, count) {
      ans.push_back('a' + i);
    }
  }

  cout << ans << endl;
  
  return 0;
}