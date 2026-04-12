#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int ans = (X-Z)/(Y+Z);
  cout << ans << endl;
}