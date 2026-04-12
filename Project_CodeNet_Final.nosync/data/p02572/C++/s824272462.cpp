#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const ll MOD=1e9+7;

int main(){
  int n;
  cin>>n;
  
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  
  ll sum=0,sum2=0;
  
  rep(i,n){
    sum=(sum+A[i])%MOD;
    sum2=(sum2+A[i]*A[i]%MOD)%MOD;
  }
  
  ll ans;
  rep(i,MOD){
    if((2*i+sum2)%MOD==sum*sum%MOD) ans=i;
  }
  cout<<ans<<endl;
  
  return 0;
}