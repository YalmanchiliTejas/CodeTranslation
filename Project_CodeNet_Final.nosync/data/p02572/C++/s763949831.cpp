#include <bits/stdc++.h>
using namespace std;

int main(){
  long n;  cin >> n;
  vector<long> a(n+1, 0);
  for(int i=1; i<=n; i++){
    long tmp;  cin >> tmp;
    a[i] = a[i-1] + tmp;
  }
  
  long mod = 1e9+7;

  long ans = 0;
  for(int i=1; i<n; i++){
    long thisans = ((a[i]-a[i-1])%mod) * ((a[n]-a[i])%mod) % mod;
    ans = (ans + thisans) % mod;
  }

  cout << ans << endl;
  return 0;
}
