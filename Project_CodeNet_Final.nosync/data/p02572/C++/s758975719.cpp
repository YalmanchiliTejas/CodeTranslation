#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;
const int mod = 1'000'000'007;
int main() {
  int N ;
  cin >> N;
  vector<ll> num(N);
  ll sum = 0;
  ll ans = 0;
  rep(i,N){
      cin >> num[i];
      ans = (ans + (ll)num[i]*sum % mod) % mod;
      sum = (sum+num[i]) % mod ;
  }
  
  cout << ans <<  endl;
}

