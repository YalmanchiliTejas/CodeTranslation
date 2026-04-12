#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll sum = 0;
  if (N % 2 == 0) {
    for (ll i = 0; i < N / 2; i++) sum -= A[i];
    for (ll i = N/2; i < N ; i++) sum += A[i];
    sum *= 2;
    sum += A[N/2 - 1] - A[N/2];
  }else {
    ll sum1 = 0;
    for (ll i = 0; i < N / 2; i++) sum1 -= A[i];
    for (ll i = N/2; i < N ; i++) sum1 += A[i];
    sum1 *= 2;
    sum1 -= A[N/2] + A[N/2 + 1];
    ll sum2 = 0;
    for (ll i = 0; i < N / 2 + 1; i++) sum2 -= A[i];
    for (ll i = N/2 + 1; i < N ; i++) sum2 += A[i];
    sum2 *= 2;
    sum2 += A[N/2 - 1] + A[N/2];
    sum = max(sum1, sum2);
  }
  cout << sum << endl;

  return 0;
}

