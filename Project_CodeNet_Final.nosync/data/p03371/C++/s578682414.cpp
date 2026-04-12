#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, x, y, cost=0; cin >> a >> b >> c >> x >> y;
  if(a+b > 2*c){
    for(int i=0;i<min(x,y);i++) cost += 2*c;
    if(x > y && a < 2*c) cost += a*(x-y);
    else if(x < y && b < 2*c) cost += b*(y-x);
    else for(int i=0;i<abs(x-y);i++) cost += 2*c;
  }
  else cost = a*x + b*y;
  cout << cost << endl;
  return 0;
}