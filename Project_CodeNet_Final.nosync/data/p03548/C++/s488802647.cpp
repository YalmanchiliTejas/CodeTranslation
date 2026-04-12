#include <iostream>
using namespace std;
int main(void){
  int X,Y,Z;
  cin >> X >> Y >> Z;
  
  int P = Z + Y;
  int Q = X - Z;
  
    cout << Q / P << endl;
  
  return 0;
}