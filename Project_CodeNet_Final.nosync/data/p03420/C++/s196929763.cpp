#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,k;
  cin >> n >> k;
  ll ans=0;
  ll zero=0;
  if(k>0) {
    for(ll i=k+1;i<=n;i++) {
      ll temp=i-k;
      ans+=n/i*temp+max(n%i-k+1,zero);
    }
  }
  else {
    ans=n*n;
  }
  cout << ans << endl;
}