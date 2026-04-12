#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, x, y, price, chpst=10000000000;

int m2n(int nedan){
  if(nedan==x)return a;
  else if(nedan==y)return b;
  else return 0;
}

int main(){
  cin >> a >> b >> c >> x >> y;
  for(int i=0; i<=min(x, y); i++){
    price=a*x+b*y+i*(2*c-a-b);
    chpst = min(chpst, price);
  }
  for(int i=min(x, y)+1; i<=max(x, y); i++){
    price += (2*c-m2n(max(x, y)));
    chpst = min(chpst, price);
  }
  cout << chpst;
  return 0;
}
  