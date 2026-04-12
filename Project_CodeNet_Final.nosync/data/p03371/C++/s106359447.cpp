#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int price = x*a + y*b;
  for(int i = 0; i <= max(x,y) * 2; i++) {
    if(price > (i * c + max(0,(x-i/2)) * a + max(0,(y-i/2)) * b))
      price = i * c + max(0,(x-i/2)) * a + max(0,(y-i/2)) * b;
  }
  cout << price << endl;
}