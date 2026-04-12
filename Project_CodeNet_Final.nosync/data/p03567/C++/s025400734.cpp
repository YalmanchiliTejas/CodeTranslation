#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  for (int i = 0; i + 2 <= s.size(); ++i) {
    if (s.substr(i, 2) == "AC") {
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
  return 0;
}
