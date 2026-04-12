#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x;
  int y;
  int z;
  cin >> x >> y >> z;
  x -= z;
  cout << (x/(y+z));
}