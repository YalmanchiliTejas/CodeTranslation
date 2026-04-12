#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; ++i)

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int max = 0;

  x -= z;

  while(x >= y+z) {
    x -= y+z;
    max += 1;
  }

  cout << max << endl;

  return 0;
}
