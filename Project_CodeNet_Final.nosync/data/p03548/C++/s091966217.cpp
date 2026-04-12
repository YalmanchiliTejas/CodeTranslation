#include <iostream>
#include <iomanip>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]){
  int x,y,z;
  cin >> x >> y >> z;
  if (x<(2 * z + y)){
    cout << 0 << endl;
  }else{
    cout << int((x-y-z*2)/(y+z)) + 1 << endl;
  }

  return 0;
}
