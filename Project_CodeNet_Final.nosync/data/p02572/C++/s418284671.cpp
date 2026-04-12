#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

void solve(long N, vector<long> A) {
  vector<long> cum(N, 0);
  REP(i, N) {
    if (i == 0)
      cum[i] = A[i];
    else
      cum[i] = (cum[i - 1] + A[i]) % MOD;
  }
  long ans(0);
  FOR(i, 1, N) {
    ll mul = cum[i - 1] * A[i];
    ans += mul % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;
  
  vector<long> A(N);
  REP(i, N)
    cin >> A[i];

  solve(N, move(A));

  return 0;
}
