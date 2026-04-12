#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z, ans=0;
  cin >> X >> Y >> Z;
  
  ans = (X-Z)/(Y+Z);
  
  cout << ans << endl;
}