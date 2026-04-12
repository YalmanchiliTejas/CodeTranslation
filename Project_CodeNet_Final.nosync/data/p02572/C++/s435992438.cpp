#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,ans=0,add=0,two=0,mod=1000000007;
  cin>>n;
  vector<long long> A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
    add+=A[i];
    add%=mod;
  }
  ans=add*add%mod;
  for (int i = 0; i < n; i++){
		ans -= (long long)A[i] * A[i] % mod;
		if (ans < 0) ans += mod;
  }
  ans *= (mod + 1) / 2;
  ans %= mod;
  cout<<ans<<endl;
}