#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, y, z;
  int ans;
  
  cin >> x >> y >> z;
  
  ans = x / (y + z);
  
  if(x % (y + z) < z) ans--;
  
  cout << ans << endl;
  
  return 0;
}