#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> S;
ll R;

int main() {
  cin >> N;
  S.resize(N);
  for (ll i = 0; i < N; ++i) cin >> S[i];
  for (ll k = 1; k <= N - 1; ++k) {
    ll sum = 0;
    for (ll l = 0, r = N - 1; k < r && (l < r || (l - r) % k != 0);
         l += k, r -= k) {
      sum += S[l] + S[r];
      R = max(R, sum);
    }
  }
  cout << R << endl;
  return 0;
}
