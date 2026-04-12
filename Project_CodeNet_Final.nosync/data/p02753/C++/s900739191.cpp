#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
 
int main() {
  string s;
  cin >> s;

  bool a = false;
  bool b = false;

  rep(i, 3) {
    if (s.substr(i, 1) == "A") {
      a = true;
    } else {
      b = true;
    }
  }
  if (a && b) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
