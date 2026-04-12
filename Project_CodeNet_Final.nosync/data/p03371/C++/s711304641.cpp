#include<bits/stdc++.h>
using namespace std;
int main(){

  long long a,b,c,x,y;

  cin>>a>>b>>c>>x>>y;
  
  long long ans=0;
  if(x>y){
    ans=min((a*y+b*y),(c*(y*2)));
  }else if(x<=y){
    ans=min((a*x+b*x),(c*(x*2)));
  }

  if(x>y){
   
    ans+=min((a*(x-y)),(c*((x-y)*2)));
    
  
    
  }else if(x<=y){
    
    ans+=min((b*(y-x)),(c*((y-x)*2)));
    

    
  }
  
  cout<<ans<<endl;
  
 
  return 0;
}
