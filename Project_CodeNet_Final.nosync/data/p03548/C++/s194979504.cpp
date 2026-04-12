#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int x,y,z,s=1;
  cin >> x >> y >> z;
  while (y*s+z*(s+1) <= x) s++;
  cout << --s << endl;;
  return 0;
}