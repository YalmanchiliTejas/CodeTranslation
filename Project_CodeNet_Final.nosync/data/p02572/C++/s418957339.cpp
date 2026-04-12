#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

typedef long long ll;
const ll mod = 1e9+7;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  ll a[n];
  for (int i = 0; i < n; ++i){
    cin >> a[i];
  }
  ll pref[n+1];
  pref[0] = 0;
  for (int i = 0; i < n; ++i){
    pref[i+1] = pref[i] + a[i];
    pref[i+1] %= mod;
  }
  ll ans = 0;
  for (int i = 1; i < n; ++i){
    ans += pref[i]*a[i]%mod;
    ans %= mod;
  }

  cout << ans%mod << endl;

  return 0;
}