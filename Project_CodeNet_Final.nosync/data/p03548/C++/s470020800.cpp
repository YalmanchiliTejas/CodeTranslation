#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int ans = 0;
  ans = (X - Z)/(Y + Z);
  
  cout << ans << endl;
  
  return 0;
}