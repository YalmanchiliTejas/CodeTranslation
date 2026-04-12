#include<bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c;
  int x, y;
  cin >> a >> b >> c >> x >> y;
  
  int cost = 0;
  cost += min(a + b, 2 * c) * min(x, y);
  if(x > y){
    if(a > 2 * c) cost += 2 * c * (x - y);
    else cost += a * (x - y);
  }else{
    if(b > 2 * c) cost += 2 * c * (y - x);
    else cost += b * (y - x);
  }
  
  cout << cost << endl;
  
  return 0;
}