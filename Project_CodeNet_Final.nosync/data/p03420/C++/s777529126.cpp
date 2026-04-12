#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(){
  unsigned long long n,k;
  cin >> n >> k;
  unsigned long long comb = 0;
  if(k==0){
    std::cout << n*n << std::endl;
    return 0;
  }
  for(unsigned long long i=k+1;i<=n;++i){
    comb += n/i*(i-k);
    if(n%i >= k) {
      comb += (n%i-k+1);
    }
    // std::cout << i << " " << comb << std::endl;
  }
  std::cout << comb << std::endl;

  return 0;
}