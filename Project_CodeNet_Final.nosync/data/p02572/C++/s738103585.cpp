#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;
const int MOD = 1000000007;


int main(void) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> v(N);
  v[N - 1] = A[N - 1];
  for (int i = N - 2; i > 0; --i) {
    v[i] = (A[i] + v[i + 1]) % MOD;
  }

  ll ans = 0;
  ll num;
  rep(i, N - 1) {
    num = A[i] * v[i + 1] % MOD;
    ans = (ans + num) % MOD;
  }

  cout << ans << endl;
  
  return 0;
}