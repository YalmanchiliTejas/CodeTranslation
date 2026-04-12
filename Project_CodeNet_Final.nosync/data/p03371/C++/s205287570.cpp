#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  long long x,y;
  long long price = 0;
  
  cin >> a >> b >> c >> x >> y;
  
  if(a + b > c * 2){
    // C2枚の方が安い
    if(x <= y){
      price += c * x * 2;
      if(b <= c * 2) price += (y - x) * b;	// b1枚買ったほうが安い
      else price += (y - x) * c * 2;		// c2枚買ったほうが安い
    }else{
      price = c * y * 2;
      if(a <= c * 2) price += (x - y) * a;	// b1枚買ったほうが安い
      else price += (x - y) * c * 2;		// c2枚買ったほうが安い
    }
  }else{
    // A,Bそれぞれ買ったほうが安い
      price += a * x;
      price += b * y;
  }
  
  cout << price;
}
