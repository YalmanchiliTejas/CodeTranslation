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
  sort(a.rbegin(),a.rend());
  ll ans=0;
  if(n%2) {
    ll tans=0;
    for(ll i=0;i<(n+1)/2;i++) {
      if((n+1)/2-i>2) {
        tans+=a[i]*2;
      }
      else {
        tans+=a[i];
      }
    }
    for(ll i=(n+1)/2;i<n;i++) {
      tans-=a[i]*2;
    }
    ans=max(ans,tans);
    sort(a.begin(),a.end());
    tans=0;
    for(ll i=0;i<(n+1)/2;i++) {
      if((n+1)/2-i>2) {
        tans-=a[i]*2;
      }
      else {
        tans-=a[i];
      }
    }
    for(ll i=(n+1)/2;i<n;i++) {
      tans+=a[i]*2;
    }
    ans=max(ans,tans);
  }
  else {
    ll tans=0;
    for(ll i=0;i<n/2;i++) {
      if(n/2-i>1) {
        tans+=a[i]*2;
      }
      else {
        tans+=a[i];
      }
    }
    for(ll i=n/2;i<n;i++) {
      if(i!=n/2) {
        tans-=a[i]*2;
      }
      else {
        tans-=a[i];
      }
    }
    ans=max(ans,tans);
    sort(a.begin(),a.end());
    tans=0;
    for(ll i=0;i<n/2;i++) {
      if(n/2-i>1) {
        tans-=a[i]*2;
      }
      else {
        tans-=a[i];
      }
    }
    for(ll i=n/2;i<n;i++) {
      if(i!=n/2) {
        tans+=a[i]*2;
      }
      else {
        tans+=a[i];
      }
    }
    ans=max(ans,tans);
  }
  cout << ans << endl;
}