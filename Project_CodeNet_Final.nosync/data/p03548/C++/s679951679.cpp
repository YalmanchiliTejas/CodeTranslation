#include <iostream>
#include <math.h>
using namespace std;
#define prt(var) cout << (var) << endl;

int main() {
  int x, y, z;
  cin>>x>>y>>z;
  x-=z;
  prt(x/(y+z));
}