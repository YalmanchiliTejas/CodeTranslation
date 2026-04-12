#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef map<ll, ll> M;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ((ll)(x).size())

int main() {
  ll N, mod = 1000000000 + 7, result = 0;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll tmp = 0;
  REP(i, N-1) tmp += A[i];
  for (ll i = N-1; i > 0; i--) {
    result += ((tmp % mod) * (A[i] % mod)) % mod;
    // cout << tmp << " " << result << endl;
    tmp -= A[i-1];
  }
  cout << result % mod << endl;
  return 0;
}