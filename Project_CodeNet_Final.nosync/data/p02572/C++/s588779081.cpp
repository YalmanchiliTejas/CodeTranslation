// sum_{i=0}^{N-2} \sum_{j=i+1}^{N-1} A_i*A_j
// sum_{i=0}^{N-2} A_i * (\sum_{j=i+1}^{N-1} A_j)
#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;

ll MOD = static_cast<ll>(1e9+7);
ll ADD(ll x, ll y) { return (x+y)%MOD; }
ll MUL(ll x, ll y) { return (x*y)%MOD; }

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for(ll i=0; i<n; i++) {
    cin >> A[i];
  }
  vector<ll> SUFFIX_SUM(n, 0);
  SUFFIX_SUM[n-1] = A[n-1];
  for(ll i=n-2; i>=0; i--) {
    SUFFIX_SUM[i] = ADD(SUFFIX_SUM[i+1], A[i]);
  }
  ll ans = 0;
  for(ll i=0; i+1<n; i++) {
    ans = ADD(ans, MUL(A[i], SUFFIX_SUM[i+1]));
  }
  cout << ans << endl;
}
