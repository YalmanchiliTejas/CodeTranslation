#include<iostream>
#include<vector>

int main(){
  int n;
  std::cin>>n;
  std::vector<int64_t> a(n);
  for(auto& ai:a)std::cin>>ai;
  
  std::vector<int64_t> sum(n+1);
  for(int i=0;i<n;++i)sum[i+1] = sum[i]+a[i];
  
  constexpr int64_t mod = 1e9+7;
  int64_t ans = 0;
  for(int i=0;i+1<n;++i){
    int64_t sum_aj = sum[n]-sum[i+1];
    sum_aj %= mod;
    ans += a[i]*sum_aj%mod;
    ans %= mod;
  }
  
  std::cout << ans << std::endl;
}