#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;

  int ans = 0;
  x -= z;
  while(x-z >= y){
    ans++;
    x -= y;
    x -= z;
  }

  cout << ans << endl;
  return 0;
}


