#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, s=0;
  cin >> x >> y >> z ;
  x-=y+2*z;
  s++;
  s+=x/(y+z);
  cout << s << endl;
}
