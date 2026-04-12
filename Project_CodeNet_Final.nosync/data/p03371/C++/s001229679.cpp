#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  long long a,b,c,x,y,ans=0;cin>>a>>b>>c>>x>>y;
  if(a+b<c*2) ans=a*x+b*y;
  else{
    ans+=c*2*min(x,y);
    if(x>y){
      if(a>c*2) ans+=c*2*(x-y);
      else ans+=a*(x-y);
    }else{
      if(b>c*2) ans+=c*2*(y-x);
      else ans+=b*(y-x);    
    }
  }
  cout<<ans;
}