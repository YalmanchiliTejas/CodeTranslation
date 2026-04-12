#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> a(4);
  int r = 0;
  for (a[0] = 1; a[0] <= 3; a[0]++) {
    for (a[1] = 1; a[1] <= 3; a[1]++) {
      for (a[2] = 1; a[2] <= 3; a[2]++) {
        for (a[3] = 1; a[3] <= 3; a[3]++) {
          if (a[0] + a[1] + a[2] + a[3] != s.size()) {
            continue;
          }
          bool ok = true;
          int k = 0;
          for (auto l : a) {
            int m = 0;
            for (int i = k; i < k + l; i++) {
              m *= 10;
              m += s[i] - '0';
            }
            if (256 <= m) {
              ok = false;
            }
            if (m == 0 && l != 1) {
              ok = false;
            }
            if (m != 0 && s[k] == '0') {
              ok = false;
            }

            k += l;
            // cerr << m << " ";
          }
          // cerr << endl;
          r += ok;
          // if (ok) {
          //   for (auto e : a) {
          //     cerr << e << " ";
          //   }
          //   cerr << endl;
          // }
        }
      }
    }
  }
  cout << r << endl;
}

