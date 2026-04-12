#include <iostream>
#include <vector>
using ll =long long;
int main()
{
  int N;std::cin>>N;
  ll X;std::cin>>X;
  std::vector<ll> s(N+1,1),p(N+1,1);
  for(int i=1;i<=N;i++){
    s[i]=2*s[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  auto dp=[&](auto&& self,const int l,const ll x)->ll{
    if(l==0)return 1;
    if(x<=1)return 0;
    if(x<=1+s[l-1])return self(self,l-1,x-1);
    if(x==2+s[l-1])return 1+p[l-1];
    if(x<=2+2*s[l-1])return p[l-1]+1+self(self,l-1,x-2-s[l-1]);
    return 2*p[l-1]+1;
  };
  std::cout<<dp(dp,N,X)<<std::endl;
  return 0;
}
