#include <iostream>
using namespace std;

int main(){
int r,g,b,make;
  cin >> r >> g >> b;
  make = 100 * r + 10 * g + b;
  if(make % 4 == 0){
  cout << "YES" << endl;
  }else{
  cout << "NO" << endl;
  }
  return 0;
}