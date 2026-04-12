#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int a1, a2, a3;

  a1 = a*x + b*y;
  a2 = 2*c * max(x, y);

  if (x >= y){
    a3 = 2*c * y + a * ( x - y );
  } else {
    a3 = 2*c * x + b * ( y - x);
  }

  cout << min({a1, a2, a3}) << endl;
  
	return 0;
}
