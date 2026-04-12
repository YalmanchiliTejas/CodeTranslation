#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
#define INF 1e9
using namespace std;
template<typename T> void cmin(T &a, T b) { a = min(a, b); }
template<typename T> void cmax(T &a, T b) { a = max(a, b); }

char mp[10][10] = {};
string s;

signed main() {

  while (cin >> s) {
    if (s == "#") break;
    int a[4];
    rep(i, 4) cin >> a[i], a[i]--;
    int x = 0, y = 0, len = 0;
    while (s[x] != '/') {
      if (isdigit(s[x])) {
        len += s[x] - '0';
      } else
        len++;
      x++;
    }
    x = 0;
    rep(i, s.size()) {
      if (s[i] == '/')
        y++, x = 0;
      else if (isdigit(s[i])) {
        int width = s[i] - '0';
        rep(j, width) mp[y][x] = '.', x++;
      } else {
        mp[y][x] = s[i];
        x++;
      }
    }
    // cout << "tate" << y + 1 << ' ' << "yoko" << len << endl;
    // rep(i, y + 1) {
    //   rep(j, len) cout << mp[i][j];
    //   cout << endl;
    // }
    swap(mp[a[0]][a[1]], mp[a[2]][a[3]]);
    // cout << endl;
    // rep(i, y + 1) {
    //   rep(j, len) cout << mp[i][j];
    //   cout << endl;
    // }
    string ans = "";
    rep(i, y + 1) {
      rep(j, len) {
        if (isalpha(mp[i][j])) {
          ans += mp[i][j];
        } else {
          int num = 0;
          while (j < len && mp[i][j] == '.') {
            num++;
            j++;
          }
          j--;
          ans += to_string(num);
        }
      }
      if (i < y) ans += '/';
    }
    cout << ans << endl;
  }

  return 0;
}

