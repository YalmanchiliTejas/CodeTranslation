#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#define _GLIBCXX_DEBUG
int main() {
  
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int price = a * x + b * y,Tprice;
  
  for ( int i = 1; i <= 100000; i++){
    Tprice = i * 2 * c + max(0,x-i) * a + max(0,y-i) * b;
    price = min(price,Tprice);
  }
  
  cout << price << endl;
  
}
