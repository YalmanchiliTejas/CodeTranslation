#include <bits/stdc++.h>
using namespace std;

const string h = "lllllllrrrrrrrrrllllrlllrl";

int main() {
  string s;
  while (cin >> s, s[0] != '#') {
    int cur = -1;
    int ans = -1;
    for (auto&& c : s) {
      if (h[c - 'a'] == 'l') {
        if (cur != 0) ++ans;
        cur = 0;
      } else {
        if (cur != 1) ++ans;
        cur = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

