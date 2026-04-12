#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int pat1,pat2,pat3;
  pat1 = a*x+b*y;
  if(x>y)  pat2 = c*2*y+(x-y)*a;
  else pat2 = c*2*x+(y-x)*b;
  if(x>y) pat3 = x*2*c;
  else pat3 = y*2*c;
  int m = min({pat1,pat2,pat3});
  cout << m << "\n";
  return 0;
}