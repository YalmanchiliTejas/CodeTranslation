#include <iostream>
using namespace std;

int main(){
  int x, y, z, co = 0, next;
  cin >> x >> y >> z;
  while (x > 0){
    x -= z;
    next = x - y;
    if (next < z){
      break;
    }else{
      x = next;
      co += 1;
    }
  }
  cout << co << endl;
  return 0;
}