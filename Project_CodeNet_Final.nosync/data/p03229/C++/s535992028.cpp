#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];
  sort(a, a+n);
  ll ans = 0;
  if(!(n % 2)){
    rep(i, n/2){
      ans -= 2*a[i];
      ans += 2*a[n-1-i];
    }
    ans += a[n/2-1];
    ans -= a[n/2];
  } else {
    ll ans1 = 0, ans2 = 0;
    rep(i, n/2){
      ans1 -= 2*a[i];
      ans1 += 2*a[n-1-i];
      ans2 -= 2*a[i];
      ans2 += 2*a[n-1-i];
    }
    ans1 -= a[n/2];
    ans1 += a[n/2-1];
    ans2 -= a[n/2+1];
    ans2 += a[n/2];
    ans = max(ans1,ans2);
  }
  cout << ans << endl;
  return 0;
}
