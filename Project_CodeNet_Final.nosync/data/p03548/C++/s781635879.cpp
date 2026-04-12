#include <iostream>
using namespace std;

int main(){
  int X,Y,Z; cin >> X >> Y >> Z;
  int q,r; q = X/(Y+Z); r = X%(Y+Z);
  if(r<Z){cout << q-1;}
  else{cout << q;}
  
  return 0;
}