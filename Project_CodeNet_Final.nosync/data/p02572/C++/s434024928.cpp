//テンプレ：

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin>>n;
  vector<ll>v1(n);
  vector<ll>v2(n);
  ll count=0;
  for(ll i=0;i<n;i++){
    cin>>v1[i];
    count+=v1[i];
    count%=mod;
    v2[i]=count;
  }
  ll ans=0;
  for(ll j=1;j<n;j++){
    ll  x=(v1[j])*(v2[j-1]);
    x%=mod;
    ans+=x;
    ans%=mod;
  }
  cout<<ans<<endl;
}
    