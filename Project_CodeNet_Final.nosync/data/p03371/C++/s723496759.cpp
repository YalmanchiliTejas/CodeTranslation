#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int money=0;
  if(a+b>2*c){
    int ab=min(x,y);
    money+=2*c*ab;
    int rest=max(x,y)-ab;
    int price;
    if(x>y) price=a;
    else price=b;
    if(price>2*c) money+=rest*2*c;
    else money+=rest*price;
  }
  else{
    money+=a*x+b*y;
  }
  cout<<money<<endl;
}