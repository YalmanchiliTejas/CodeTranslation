#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> divisor(ll n) {
  vector<ll> v;
  for(ll i=1; i*i<=n; i++) {
    if(n%i==0) {
      v.push_back(i);
      if(i*i!=n) v.push_back(n/i);
    }
  }
  sort(v.begin(),v.end());
  return v;
}

int main() {
  ll n;
  cin >> n;
  ll a[n];
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a,a+n);
  vector<ll> p=divisor(a[n-1]);
  ll ans=0,l=0;
  for(int r=0; r<p.size(); r++) {
    while(l<n&&a[l]<=p[r]) {
      ans+=p[r]-a[l];
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}
