#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n,ans=1;
  cin >>n;
  ll h[n+1];
  for(ll i=1;i<=n;i++) cin >>h[i];
  for(ll i=2;i<=n;i++){
    ll fl=0;
    for(ll j=1;j<=i;j++){
      if(h[j]>h[i]){
        fl=1;
        break;
      }
    }
    if(fl==0) ans++;
  }
  cout <<ans<<endl;
}
