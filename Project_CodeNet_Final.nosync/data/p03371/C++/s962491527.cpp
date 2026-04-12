#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  long long couc,cxy,price=0;
  long long pmax;
  pmax=c*2*max(x,y);
  if(a+b>2*c){
    if(x>y){
      couc=y*2;
      cxy=x-y;
      price = c*couc + a*cxy;
    }
    else {
      couc=x*2;
      cxy=y-x;
      price = c*couc + b*cxy;
    }
  }
  else{
    price = a*x + b*y;
  }
  
  cout << min(price,pmax)<<endl;
}