#include<bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z; cin >> x >> y >> z;
  if (x < y + z*2) cout << 0 << endl;
  else {
    x -= y + z*2;
    cout << 1 + x / (y+z) << endl;
  }
}