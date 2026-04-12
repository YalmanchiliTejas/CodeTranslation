#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  string s;
  while (cin >> s, s != "#") {
    int h = 1, w = 0, flag = 0;
    for (int i = 0; i < s.size(); i++) {
      h += s[i] == '/';
      if (s[i] == '/') flag = 1;
      if (!flag) w += (s[i] == 'b' ? 1 : s[i] - '0');
    }

    vector<vector<bool>> ball(h, vector<bool>(w, false));
    int y = 0, x = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '/') {
        y++; x = 0;
        continue;
      }
      if (s[i] == 'b') ball[y][x] = true, x++;
      else x += s[i] - '0';
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ball[a - 1][b - 1] = false;
    ball[c - 1][d - 1] = true;

    string ans = "";
    for (int i = 0; i < h; i++) {
      int l = 0, r = 0;
      while (l < w) {
        if (ball[i][l]) {
          ans += 'b';
        } else {
          while (r + 1 < w && !ball[i][r + 1]) r++;
          ans += r - l + 1 + '0';
        }
        l = ++r;
      }
      if (i + 1 != h) ans += "/";
    }
    cout << ans << endl;
  }

  return 0;
}
