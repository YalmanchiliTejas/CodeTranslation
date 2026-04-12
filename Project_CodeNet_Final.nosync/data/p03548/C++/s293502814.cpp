#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main(){
  int x,y,z,cnt = 0;
  cin >> x >> y >> z;
  x -= z;
  while(x >= 0){
    x -= z + y;
    cnt++;
  }
  cout << cnt - 1 << endl;
}
