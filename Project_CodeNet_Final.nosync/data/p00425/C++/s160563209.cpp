#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define shosu(n) setprecision(n)
#define INF 999999999
using namespace std;
int main() {
  int N;
  while (cin >> N, N) {
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g, ans = 1;
    string s;
    rep(i, N) {
      cin >> s;
      if (s[0] == 'N') {
        g = a;
        a = b;
        b = f;
        f = e;
        e = g;
      } else if (s[0] == 'E') {
        g = a;
        a = d;
        d = f;
        f = c;
        c = g;
      } else if (s[0] == 'W') {
        g = a;
        a = c;
        c = f;
        f = d;
        d = g;
      } else if (s[0] == 'S') {
        g = a;
        a = e;
        e = f;
        f = b;
        b = g;
      } else if (s[0] == 'R') {
        g = b;
        b = c;
        c = e;
        e = d;
        d = g;
      } else if (s[0] == 'L') {
        g = b;
        b = d;
        d = e;
        e = c;
        c = g;
      }
      ans += a;
    }
    cout << ans << endl;
  }
  return 0;
}