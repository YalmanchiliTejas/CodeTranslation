#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll N,X,M;
  cin >> N >> X >> M;
  if (N < ll(1e6)) {
    ll ans = X;
    for (ll i = 2; i <= N; ++i) {
      X = (X*X)%M;
      ans += X;
    }
    cout << ans << endl;
    return 0;
  }


  ll ans = X;
  ll i = 2;
  while (i <= M) {
    X = (X*X)%M;
    ans += X;
    ++i;
  }

  map<ll,array<ll,2>> prev_sum;

  while (i <= N) {
    if (prev_sum.count(X)) {
      auto& [pi, p_sum] = prev_sum[X];
      ll cycle_len = i - pi;
      ll steps_remain = N+1 - i; // TODO should this be N?
      ll cycle_remain = steps_remain / cycle_len;
      ans += (ans-p_sum)*cycle_remain;
      i += cycle_len*cycle_remain;
      break;
    }
    prev_sum[X] = {i, ans}; // TODO should this be i-1
    X = (X*X)%M;
    ans += X;
    ++i;
  }

  while (i <= N) {
    X = (X*X)%M;
    ans += X;
    ++i;
  }

  cout << ans << endl;
}
