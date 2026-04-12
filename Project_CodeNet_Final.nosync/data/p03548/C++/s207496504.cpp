#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,y,z;
  cin >> x >> y >> z;
  if(x % (y + z) < z) {
    cout << x / (y + z) - 1 << endl;
  }else {
    cout << x / (y + z) << endl;
  }
}