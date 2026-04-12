#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

  int X, Y, Z;
  cin >> X >> Y >> Z;

  int res = (X-Z)/(Y+Z);
  cout << res << endl;
  return 0;
}
