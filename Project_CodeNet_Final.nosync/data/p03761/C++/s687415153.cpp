#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) {
    string ss;
    cin >> ss;
    sort(ss.begin(), ss.end());
    s[i] = ss;
  }
  string res = "";
  rep(i, 26) {
    char c = 'a' + i;
    int cnt = INT_MAX;
    rep(j, n) {
      int tmpCnt = 0;
      rep(k, s[j].size()) {
        if (s[j][k] == c) {
          tmpCnt++;
        }
      }
      cnt = min(cnt, tmpCnt);
    }
    if (cnt > 0) {
      rep(i, cnt) {
        res += c;
      }
    }
  }
  cout << res << endl;

  return 0;
}
