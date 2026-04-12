#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z,n,ans;
  cin >> x >> y >> z;
  n = x/(y+z);
  ans = 0;
  for(int i=0; i<=n;i++){
    if(i*(y+z) +z <= x){
      ans = i;
    }
  }
  cout << ans << endl;
}
