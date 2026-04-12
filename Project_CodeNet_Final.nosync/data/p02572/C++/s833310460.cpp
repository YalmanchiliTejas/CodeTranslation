#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll wa = 0;
  REP(i, N) {
    wa += A[i];
    wa %= MOD;
  }
  wa %= MOD;
  ll ans = 0;
  REP(i, N) {
    wa -= A[i];
    if (wa <= 0) {
      wa += MOD;
    }
    ll tmp = A[i] * (wa);
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}