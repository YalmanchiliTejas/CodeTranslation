#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  if(a+b> 2*c){
    int z=min(x,y);
    if(x == max(x,y) && a > 2*c){
      cout << 2*c*x << endl;
    }
    else if(y == max(x,y) && b > 2*c){
      cout << 2*c*y << endl;
    }
    else if(x>y) {
      cout << 2*c*z + a*(x-z) << endl;
    }
    else {
      cout << 2*c*z + b*(y-z) << endl;
    }
  }
  else{
    cout << a*x + b*y << endl;
  }
}
