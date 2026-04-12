#include <bits/stdc++.h>
using namespace std;
int main () {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int count = 0;
  while (X >= (count + 1) * (Y + Z) + Z) {
    count++;
  }
  cout << count << endl;
  return 0;
}