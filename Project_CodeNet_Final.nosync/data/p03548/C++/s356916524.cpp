#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int p = 1;
  while((y + z) * (p + 1) + z <= x){
    p++;
  }
  cout << p << endl;
}