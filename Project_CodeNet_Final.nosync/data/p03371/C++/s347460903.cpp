#include<iostream>
using namespace std;
int main()
{
  int a,b,c,x,y,moneyAB=0,money=0,moneyABC=0;
  cin >> a >> b >> c >> x >> y;
  money+= a*x + b*y;
  if(x>y)
  {
    moneyAB = 2*y*c + (x-y)*a;
    moneyABC = 2*x*c;
  }
  else
  {
    moneyAB = 2*x*c + (y-x)*b;
    moneyABC = 2*y*c;
  }
  
  if(money>moneyAB)
    if(moneyAB<moneyABC)
      cout<<moneyAB;
    else
      cout<<moneyABC;
  else
  if(money<moneyABC)
    cout<<money;
  else
    cout<<moneyABC;
  return 0;
}
