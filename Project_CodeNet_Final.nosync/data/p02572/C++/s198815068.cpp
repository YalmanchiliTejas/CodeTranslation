#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> sum(N+1, 0);
  REP(i, N){
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  ll ans = 0;
  REP(i, N){
    ll add = (A[i] * ((sum[N] - sum[i+1])%mod)) % mod;
    ans += add;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
