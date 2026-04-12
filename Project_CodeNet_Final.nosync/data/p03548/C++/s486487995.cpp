#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, occ = 0, ans = 0;
  cin >> x >> y >> z;
  
  occ += z;
    
  while(occ <= x){
    occ += y + z;
    ans++;
  }
  
  cout << ans - 1 << endl;
}
