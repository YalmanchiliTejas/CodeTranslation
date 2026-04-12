#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
  int X, Y, Z; cin >> X >> Y >> Z;
  int result = (X-Z) / (Y+Z);
  cout << result << endl;
  return 0;
}