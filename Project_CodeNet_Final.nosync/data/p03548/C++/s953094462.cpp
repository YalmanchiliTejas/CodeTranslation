#include <string>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  int a = y + z;
  int b = x - z;
  cout << b / a;
}