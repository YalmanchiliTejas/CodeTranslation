#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
  char c = s[k - 1];
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == c) continue;
    s[i] = '*';
  }
  cout << s << endl;
  return 0;
}
