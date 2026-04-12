#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main( ){
  int n;
  scanf("%d", &n);
  long long num[n], sum[n];
  for(int i = 0; i < n; i++){
    scanf("%lld", &num[i]);
    sum[i] = i == 0 ? num[i] : (sum[i - 1] % mod + num[i] % mod) % mod; 
  }
  long long ans = 0;
  for(int i = n - 1; i > 0; i--){
    ans = (ans % mod + (num[i] % mod * sum[i - 1] % mod) % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}