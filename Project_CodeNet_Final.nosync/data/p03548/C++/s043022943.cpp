#include <iostream>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int num = 0;
  x -= z;
  while(x >= y + z){
    x = x - y - z;
    num++;
  }
  cout << num << endl;
  return 0;
}
