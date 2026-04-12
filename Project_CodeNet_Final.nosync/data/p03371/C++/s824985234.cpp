#include <iostream>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if(a+b<2*c) cout << a*x+b*y;
  else if(a<2*c&&b<2*c) cout << min(x, y)*2*c+(x-min(x, y))*a+(y-min(x, y))*b;
  else if(2*c<=a&&b<2*c) cout << x*2*c+max(y-x, 0)*b;
  else if(a<2*c&&2*c<b) cout<< y*2*c+max(x-y, 0)*a;
  else cout << max(x, y)*2*c;
  return 0;
}