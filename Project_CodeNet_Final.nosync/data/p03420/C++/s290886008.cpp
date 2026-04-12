#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n, k, tmp1, tmp;
  while(cin>>n>>k){
    ll ans=0;
    for(ll i=k+1; i<=n; ++i){
      tmp=n%i;
      tmp1=n/i;
//      cout<<i<<" "<<tmp<<" "<<tmp1<<endl;
      ans+=(max(0ll, tmp-k+1)*tmp1)+max(0ll, i-1-max(k-1, tmp))*(tmp1-1);
//      cout<<"&"<<ans<<endl;
    }
    for(ll i=max(1ll, k); i<=n; ++i){
      ans+=(n-i);
    }
    cout<<ans<<endl;
  }
  return 0;
}


