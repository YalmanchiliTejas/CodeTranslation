// Undone
#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
#define MOD 1000000007
using namespace std;
signed main() {
  string s;
  string left = "qwertasdfgzxcvb", right = "yuiophjklnm";
  while (cin>>s, s!="#") {
    // 0: left, 1: right
    int ans = -1, side = -1;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < left.length(); j++) {
        if (left[j] == s[i]) {
          if (side != 0) {
            ans++;
            side = 0;
          }
          break;
        }
      }
      for (int j = 0; j < right.length(); j++) {
        if (right[j] == s[i]) {
          if (side != 1) {
            ans++;
            side = 1;
          }
          break;
        }
      }
    }
    cout << ans << endl;
  }
}


