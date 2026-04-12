#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int x,y,z,ans=0;
  cin >> x >> y >> z;
  x = x - z;
  ans = x / (y + z);
  cout << ans << endl;
}