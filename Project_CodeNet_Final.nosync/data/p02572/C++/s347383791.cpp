#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
int main(){
 
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; ++i){
   cin >> a[i]; 
  }
  vector<long long> s(n, 0);
  s[n-1] = a[n-1];
  for(int i = n-2; i >= 0; --i){
  	s[i] = (s[i+1] + a[i])%mod;
  }

  long long ans = 0;
  for(int i = 0; i < n-1; ++i){
  	ans += a[i]*s[i+1];
    ans %= mod;
  }
  cout << ans << '\n';
  
  
  return 0;
}