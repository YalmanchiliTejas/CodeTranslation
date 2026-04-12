#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

int main(){
  int n, s;
  cin >> n >> s;
  vector<ll> A(n);
  for (int i=0; i<n; i++) cin >> A[i];

  ll ans = 0;
  vector<ll> sum(s+1);
  for (int i=0; i<n; i++){
    sum[0]++;
    ll a = A[i];
    for (int k=s-a; k>=0; k--){
      sum[k+a] += sum[k];
      sum[k+a] %= mod;
    }
    ans += sum[s];
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}