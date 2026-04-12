#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
  int x, y, z;
  cin >> x >> y >> z;
  int ans = (x - z)/(y+z);
  cout << ans << endl;
  return 0;
}
