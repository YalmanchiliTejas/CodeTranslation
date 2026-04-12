#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y,ans=0;
  cin>>a>>b>>c>>x>>y;
  if(a+b>c*2){
    ans+=min(x,y)*c*2;
    if(x>y){
      if(a>c*2){
	ans+=(x-y)*c*2;
      }
      else ans+=(x-y)*a;
    }
    else if(x<y){
      if(b>c*2){
	ans+=(y-x)*c*2;
      }
      else ans+=(y-x)*b;
    }
  }
  else{
    ans=x*a+y*b;
  }
  cout<<ans<<endl;
  return(0);
}
