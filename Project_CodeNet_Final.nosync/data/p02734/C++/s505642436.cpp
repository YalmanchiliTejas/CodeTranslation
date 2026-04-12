#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,s,ans=0,mod=998244353;
  cin >> n >> s;
  vector<long> a(n);
  vector<long> wa(s-1);
  for(long i=0;i<n;i++) cin >> a[i];

  for(long i=0;i<n;i++) {
    for(long j=s-1;j>0;j--) {
      if(a[i]+j<s) wa[a[i]+j-1]=(wa[a[i]+j-1]+wa[j-1])%mod;
      else if(a[i]+j==s) ans=(ans+wa[j-1]*(n-i))%mod;
    }
    if(a[i]<s) wa[a[i]-1]=(wa[a[i]-1]+i+1)%mod;
    else if(a[i]==s) ans=(ans+(i+1)*(n-i))%mod;
  }
  
  cout << ans << endl;
}