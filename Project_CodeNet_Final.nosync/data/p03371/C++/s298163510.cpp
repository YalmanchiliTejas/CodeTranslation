#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,a,b,c;
  cin >> a >> b >> c >> x >> y ;
  int price1 =0;//abピザ複数枚で用意する
  int price2 = x*a + y*b;//a,bそれぞれを枚数分買う
  int price3 = 0; //abピザだけで全部用意する。あまりもでる。
  if (x<y) price1+= 2*x*c + (y-x)*b;
  else if (x>y) price1 += 2*y*c + (x-y)*a;
  else if (x=y) price1 += 2*x*c;
  price3 += 2*max(x,y)*c;
  cout << min(min(price1,price2),price3) << endl;
  
}