#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ans = (X - Z) / (Y + Z);
  cout << ans;
  return 0;
}