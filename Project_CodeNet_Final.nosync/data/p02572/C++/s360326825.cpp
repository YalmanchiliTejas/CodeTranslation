#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin>>n;
  ll a[n];
  for(int i = 0;i < n;i++)
    cin>>a[i];
  ll s[n+1];
  s[n] = 0;
  for(int i = n-1; i>=0;i--) {
    s[i] = (s[i+1] + a[i])%mod;
  }
  
  ll ans = 0;
  for(int i = 0;i < n;i++) {
    ans = (ans + ((a[i] % mod) * (s[i+1] % mod)))%mod;
  }
  cout<<ans<<"\n";
  return 0;
}