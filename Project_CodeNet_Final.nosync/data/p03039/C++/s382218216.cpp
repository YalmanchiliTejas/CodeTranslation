#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long int ll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)

#define MOD 1000000007

ll calcz(ll x, ll y){
  ll a = x, b = MOD;
  ll tmp;
  vector<ll> syo;
  while(a > 1){
    syo.push_back(b / a);
    tmp = b % a;
    b = a;
    a = tmp;
  }
  ll dp1 = 0, dp2 = 1;
  rrep(i, syo.size()){
    ll tmp = (dp2 * (-syo[i]) + dp1) % MOD;
    dp1 = dp2;
    dp2 = tmp;
  }
  y = (y + MOD) % MOD;
  dp2 = (dp2 + MOD) % MOD;
  return (y % 10000 * dp2 % MOD + (y / 10000) * dp2 % MOD * 10000) % MOD;
}

ll comb(int n, int r) {
  ll val = 1;
  repi(a, n-r+1, n+1) val = (val * a) % MOD;
  repi(a, 1, r+1) val = calcz(a, val);
  return val;
}

ll f_sum(ll m, ll n){
  ll val = 0;
  repi(i, 1, m+1)
    val = (val + i * i + (m-i+1) * (m-i+1)) % MOD;
  val = (val * n * n) % MOD;
  return val;
}

int main(){
  ll N, M, K;
  cin >> N >> M >> K;

  ll ans = (f_sum(N, M) + f_sum(M, N) - M*N*(2*M*N+M+N)) % MOD;
  ans = (ans * comb(K, 2)) % MOD;
  ans = (ans * comb(M*N, K)) % MOD;
  ans = calcz(2*M*N*(M*N-1), ans);

  cout << ans << endl;
  return 0;
}
