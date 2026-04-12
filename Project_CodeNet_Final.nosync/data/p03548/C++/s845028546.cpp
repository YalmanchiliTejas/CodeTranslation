#include <iostream>
using namespace std;

int main(){
  int X,Y,Z,i=0;cin >> X>>Y>>Z;
  while(X >= i*(Y+Z)+Z){
    i++;
  }
  cout << i-1 << endl;
}
