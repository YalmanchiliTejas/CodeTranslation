#include <iostream>
#include <algorithm>

int a,b,c,x,y;
int main(){
  std::cin>>a>>b>>c>>x>>y;
  
  long long ans=2*c*std::max<long long>(x,y);
  long long sum=2*c*std::min<long long>(x,y);
  if(x!=y){
    if(x>y)
      sum+=a*(x-y);
    else
      sum+=b*(y-x);
  }
  ans=std::min<long long>(sum,ans);
  ans=std::min<long long>(ans,a*x+b*y);
  
  std::cout<<ans<<std::endl;
  return 0;
}
