#include <iostream>
#include <math.h>
using namespace std;

int main(){
  double X=0.0, Y=0.0, Z=0.0;
  double i=1.0;

  cin >> X >> Y >> Z;
  i = (X-Z)/(Z+Y);

  cout << (int)i << endl;
  return 0;
}
