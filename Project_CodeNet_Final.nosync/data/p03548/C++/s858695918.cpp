#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){

  int x, y, z;
  cin >> x >> y >> z;
  if ((x - (y + z) * (x / (y + z))) >= z){
    cout << (x / (y + z)) << endl;
  }
  else {
    cout << (x / (y + z)) - 1 << endl;
  }

  return 0;
}
