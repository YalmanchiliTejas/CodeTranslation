#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int money=0;
  if(a+b>c*2) {
    int cnt=min(x,y);
    money=c*cnt*2;
    if(cnt==x){
      if(b>c*2) money+=(y-x)*c*2;
      else money+=(y-x)*b;
    }
    else{
      if(a>c*2) money+=(x-y)*c*2;
      else money+=(x-y)*a;
    }
    cout<<money;
  }
  else cout<<a*x+b*y;

}
