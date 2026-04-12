#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n);
  rep(i, n) cin >> vec[i];
  sort(all(vec));
  if(n % 2 != 0){
    ll ans1 = 0, ans2= 0;
    for(int i=0;i<n/2; i++) ans1 -= 2*vec[i];
    ans1 += vec[n/2]+vec[n/2+1];
    for(int i=n/2+2;i<n; i++) ans1 += 2*vec[i];
    for(int i=0;i<n/2-1; i++) ans2 -= 2*vec[i];
    ans2 -= vec[n/2-1]+vec[n/2];
    for(int i=n/2+1;i<n; i++) ans2 += 2*vec[i];
    cout << max(ans1, ans2) << endl;
  }else{
    ll ans = 0;
    for(int i=0; i<n/2-1; i++) ans -= 2*vec[i];
    for(int i=n/2+1; i<n; i++) ans += 2*vec[i];
    ans += vec[n/2]-vec[n/2-1];
    cout << ans << endl;
  }
  return 0;
}