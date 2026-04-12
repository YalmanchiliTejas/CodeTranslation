#include <iostream>
using namespace std;
int main(void){
  int a,b,c,x,y,ans=0;
  cin>>a>>b>>c>>x>>y;
  if(a+b>=c*2){
      int s=min(x,y);
      x-=s;
      y-=s;
      ans+=c*s*2;
      if(a*x+b*y>c*2*max(x,y))ans+=c*2*max(x,y);
      else ans+=a*x+b*y;
  }
  else ans+=x*a+y*b;
  cout<<ans<<endl;
      
}
