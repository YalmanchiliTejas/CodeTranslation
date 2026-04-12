#include <bits/stdc++.h>
using namespace std;

long long n,k,i,ans,penuh,sisa;

int main() {
  scanf("%lld%lld\n",&n,&k);
  ans = n*n;
  
  for (i=1 ; i<=n ; i++) {
   	penuh = n / i;
    sisa = n % i;
    
    ans -= penuh * min(i,(k));
    ans -= max(0LL,min(k-1,sisa));
    //printf("%lld\n",ans);
  }
  printf("%lld\n",ans);
}