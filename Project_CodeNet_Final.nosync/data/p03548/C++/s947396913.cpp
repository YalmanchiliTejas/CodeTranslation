#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int P = X / (Y + Z);
  int R = X % (Y + Z);
  
  cout << (R >= Z ? P : P - 1) << endl;
  return 0;
}
