#include <iostream>
using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int under2 = g*10 + b;
  if( under2%4 == 0) cout << "YES" << endl;
  else               cout << "NO"  << endl;
}