#include <bits/stdc++.h>
using namespace std;
string l = "qwertasdfgzxcvb";
int main() {
  while (true) {
    string s;
    cin >> s;
    if (s == "#")
      break;
    int ans = -1;
    int now = -1;
    for (int i = 0; i < s.size(); i++) {
      bool ok = false;
      for (auto c : l)
        if (s[i] == c) {
          ok = true;
        }
      if (ok) {
        if (now != 1)
          ans++;
        now = 1;
      } else {
        if (now != 0) {
          ans++;
        }
        now = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
