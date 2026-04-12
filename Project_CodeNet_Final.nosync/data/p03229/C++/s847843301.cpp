#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n; cin>>n;
  vector<ll> a(n);
  for (int i=0; i<n; i++) cin>>a[i];
  sort(a.begin(), a.end(), greater<ll>());
  ll ans=0;
  if (n%2==0) {
    for (int i=0; i<n/2-1; i++) ans+=2*a[i];
    ans+=a[n/2-1];
    ans-=a[n/2];
    for (int i=n/2+1; i<n; i++) ans-=2*a[i];
  }
  else {
    ll tmp1=a[n/2-1]+a[n/2], tmp2=-a[n/2]-a[n/2+1];
    for (int i=0; i<n/2-1; ++i) tmp1+=a[i]*2;
    for (int i=n/2+1; i<n; ++i) tmp1-=a[i]*2; 
    for (int i=0; i<n/2; ++i) tmp2+=a[i]*2;
    for (int i=n/2+2; i<n; ++i) tmp2-=a[i]*2;
    ans=max(tmp1, tmp2);
  }
  cout<<ans<<endl;
}