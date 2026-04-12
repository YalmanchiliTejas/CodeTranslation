#include <iostream>
using namespace std;

int main(){
  int x, y, z;
  cin >> x >> y >> z;
  int max = (x-z)/(y+z);
  cout << max;
}