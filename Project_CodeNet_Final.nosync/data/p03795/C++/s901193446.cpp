// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 07/14/20 20:57:13
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n; cin>>n;
  int ans = n*800 - (n/15)*200;
  cout << ans << endl;

  return 0;
}
