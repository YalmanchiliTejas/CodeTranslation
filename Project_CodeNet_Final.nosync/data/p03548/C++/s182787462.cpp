#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z,ans;
  cin >> x >> y >> z;
  ans = 0;
  x -= z;
  y += z;
  ans = x / y;

  cout << ans << endl;
  
  return 0;
}