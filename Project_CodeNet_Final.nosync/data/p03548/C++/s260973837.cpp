#include <iostream>
using namespace std;

int main() {
  int X,Y,Z;
  cin >> X >> Y >> Z;
   int A;
  A = X%(Y+Z);
  if(A<Z){
    cout << X/(Y+Z)-1 << endl;
  }
  else
    cout << X/(Y+Z) << endl;
   }