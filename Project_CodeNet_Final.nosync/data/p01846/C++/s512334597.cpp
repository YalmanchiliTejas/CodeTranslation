#include <bits/stdc++.h>
using namespace std;
int mp[30][30] = {0};
int main() {
  while (true) {
    string s;
    cin >> s;
    if (s == "#")
      break;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    int w, h;
    int i = 0, j = 0, k = 0;
    while (k < s.size()) {
      if (s[k] == 'b') {
        mp[i][j] = 1;
        j++;
        k++;
      } else if (s[k] == '/') {
        j = 0;
        i++;
        k++;
      } else {
        mp[i][j] = 0;
        j++;
        s[k]--;
      }
      if (s[k] == '0') {
        k++;
      }
    }
    w = j;
    h = i + 1;
    mp[a][b] = 0;
    mp[c][d] = 1;
    string t;
    for (int i = 0; i < h; i++) {
      bool r = false;
      for (int j = 0; j < w; j++) {
        if (!mp[i][j]) {
          if (r) {
            t[t.size() - 1]++;
          } else {
            r = true;
            t.push_back('1');
          }
        } else {
          r = false;
          t.push_back('b');
        }
      }
      if (i < h - 1)
        t.push_back('/');
    }
    cout << t << endl;
  }
  return 0;
}
