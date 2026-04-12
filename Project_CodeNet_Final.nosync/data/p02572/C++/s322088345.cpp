#include <iostream>
#include <vector>

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  
  constexpr int64_t mod=1e9+7;
  
  int N;
  std::cin>>N;
  
  std::vector<int64_t> A(N);
  for(int i=0;i!=N;i++)
  {
    std::cin>>A[i];
  }
  
  int64_t sum=0;
  for(int i=0;i!=N;i++)
  {
    sum=(sum+A[i])%mod;
  }
  
  int64_t result=0;
  for(int i=0;i!=N;i++)
  {
    sum-=A[i];
    if(sum<0)sum+=mod;
    result=(result+(A[i]*sum)%mod)%mod;
  }
  
  std::cout<<result<<std::endl;
  
  return 0;
}