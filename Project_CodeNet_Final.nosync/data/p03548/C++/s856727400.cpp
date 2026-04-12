#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y, z; cin >> x >> y >> z;
  x -= z;
  y += z;
  cout << x / y << endl;
  return 0;
}
