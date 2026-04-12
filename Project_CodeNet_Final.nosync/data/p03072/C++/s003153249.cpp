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
  vec h(n);
  for(ll i=0;i<n;i++) cin >> h[i];
  ll ans=0;
  ll tmp=h[0];
  for(ll i=0;i<n;i++) {
    ans+=tmp<=h[i];
    tmp=max(tmp,h[i]);
  }
  cout << ans << endl;
}