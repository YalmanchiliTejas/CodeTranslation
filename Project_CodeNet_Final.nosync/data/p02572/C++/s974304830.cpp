#include <bits/stdc++.h>
using namespace std;
using  ll=long long;
using ld=long double;
const int MAX_N=2e5+9,mod=1e9+7;
unsigned  long long pref[MAX_N];
int main(){
  int n; cin>>n;
  for(int i=1;i<=n;i++)
      cin>>pref[i],pref[i]+=pref[i-1];
 unsigned long long ans=0;
  for(int i=1;i<=n;i++){
     ll temp=(((pref[i]-pref[i-1])%mod)*((pref[n]-pref[i])%mod))%mod;
     ans=((ans%mod)+(temp%mod))%mod;
  }
  cout<<ans%mod;
}