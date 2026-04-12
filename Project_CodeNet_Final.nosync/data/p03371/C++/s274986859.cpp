#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,x,y;
  int ans=0;
  cin>>a>>b>>c>>x>>y;
  if(a+b<=2*c){
    ans=a*x+b*y;
  }else{
     
      int s=c*2*x+b*(y-x);
      int t=c*2*y+a*(x-y);
      int u=c*max(x,y)*2;
    if(x<=y){
        ans=min(u,s);
    }else{
        ans=min(u,t);
    }
  }
  cout<<ans;
  return 0;
}