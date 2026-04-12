#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  ll mod = (ll)1e9+7;
  vector<ll> A(n),B(n+1,0);
  
  rep(i, n){
    cin >> A[i];
    B[i+1] = B[i] + A[i];
  }
  
  ll ans = 0;
  
  rep(i, n){
    ll sum = (B[n] - B[i+1]) % mod; 
    ans += A[i] * sum ;
    ans %= mod;
  }
    
  cout << ans << endl;
}