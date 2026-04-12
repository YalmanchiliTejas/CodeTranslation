#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ya=min(a+b,2*c);
  if(x>y)
  cout << min(2*x*c,y*ya+(x-y)*a) << endl;
  else
  cout << min(2*y*c,x*ya+(y-x)*b) << endl;
}