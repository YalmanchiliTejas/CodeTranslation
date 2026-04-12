#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,x,y,i,ans=0;
  cin>>a>>b>>c>>x>>y;
  
  if(c*2>=a+b){
    cout<<a*x+b*y<<endl;
    return 0;
  }else{
    if(x>y){
      ans+=c*2*y;
      if((x-y)*a<=2*(x-y)*c){
        ans+=(x-y)*a;
      }else{
        ans+=(x-y)*2*c;
      }
    }else if(x<y){
      ans+=c*2*x;
      if((y-x)*b<=2*(y-x)*c){
        ans+=(y-x)*b;
      }else{
        ans+=(y-x)*2*c;
      }
    }else{
      cout<<c*2*x<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
}