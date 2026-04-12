#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll ans=0;
  while(1) {
    ll count=0;
    for(ll i=0;i<n;i++) {
      count+=a[i]/n;
    }
    for(ll i=0;i<n;i++) {
      a[i]=a[i]%n+count-a[i]/n;
    }
    ans+=count;
    if(count==0) break;
  }
  cout << ans << endl;
}