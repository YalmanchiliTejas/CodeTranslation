#include <bits/stdc++.h>
using namespace std;

int main() {

  int a,b,c; cin >> a >> b >> c;
  int x,y; cin >> x >> y;
  
  int s = a*x + b*y;
  int t = 2*c*max(x,y);
  int u;
  if (x == y){
    u = 2*c*x;
  } else if (x > y){
    u = 2*c*y + a*(x-y);
  } else {
     u = 2*c*x + b*(y-x);
  }

  cout << min(s,min(t,u)) << endl;
  
}