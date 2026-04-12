#include<bits/stdc++.h>
using namespace std;
main(){
  long a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  long ans=min(a*x+b*y,2*c*max(x,y));
  if(x>y){
    ans=min(ans,a*(x-y)+2*c*y);
  }
  else if(y>x){
    ans=min(ans,b*(y-x)+2*c*x);
  }
  cout<<ans<<endl;
}    
