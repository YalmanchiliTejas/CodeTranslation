#include <iostream>
using ll = long long ;
int main()
{
  ll K,A,B;
  std::cin>>K>>A>>B;
  if(K<=A){return std::cout<<1<<std::endl,0;}
  if(A<=B){return std::cout<<-1<<std::endl,0;}
  const ll ans = (K-B-1)/(A-B)*2LL+1LL;
  std::cout<<ans <<std::endl;
}
