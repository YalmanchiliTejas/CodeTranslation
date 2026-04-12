#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  int ans=0;
  for(int i=0;;i++){
    if(i*Y+i*Z+Z<=X)  ans=i;
    else  break;
  }
  cout << ans << endl;

  return 0;
}
