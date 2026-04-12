#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  if (N % 2 == 1) {
    ll m = N / 2;
    ll ml = m - 1;
    ll mr = m + 1;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
      if (i < ml) ans -= 2 * A.at(i);
      else if (i > mr) ans += 2 * A.at(i);
    }
    ll case1 = -2 * A.at(ml) + A.at(m) + A.at(mr);
    ll case2 = - A.at(ml) - A.at(m) + 2 * A.at(mr);
    ll add = max(case1, case2);
    cout << ans + add << endl;
  }else {
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
      if (i < N/2 - 1) ans -= 2 * A.at(i);
      else if (i == N/2 - 1) ans -= A.at(i);
      else if (i == N/2) ans += A.at(i);
      else ans += 2 * A.at(i);
    }
    cout << ans << endl;
  }

  return 0;
}

