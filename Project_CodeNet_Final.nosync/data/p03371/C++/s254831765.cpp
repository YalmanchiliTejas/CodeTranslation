#include "bits/stdc++.h"
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int big;
  if(x>y){
    big=a;
  }else{
    big=b;
  }
  int ans=a*x+b*y;
  int ans2=((min(x,y)*2)*c)+(abs(x-y)*big);
  int ans3=((min(x,y)*2)*c)+(abs(x-y)*c*2);
  ans=min(ans,min(ans2,ans3));


  cout<<ans<<endl;
}
