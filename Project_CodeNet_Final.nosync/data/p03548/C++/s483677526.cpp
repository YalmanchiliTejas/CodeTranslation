#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  int ans = x/(y+z);
  cout << ans << endl;
  return 0;
}
