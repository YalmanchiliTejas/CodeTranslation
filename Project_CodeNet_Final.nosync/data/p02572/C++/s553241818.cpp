#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll x=0, ans=0;
  int mod=1000000007;
  rep(i, n){
    ans += (a[i]*x)%mod;
    ans%=mod;
    x+=a[i];
    x%=mod;
  }
cout << ans << endl;
  
  return 0;
}
