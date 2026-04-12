#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = (ll)1e9+7;

int main() {
  ll N;
  cin >> N;

  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll comSum[N];
  comSum[N-1]=0;
  for (ll i = N-2; i >= 0; i--) {
    comSum[i] = comSum[i+1]+A[i+1];
    comSum[i] %= MOD;
  }

  ll ans = 0;
  for (int i = 0; i < N-1; i++) {
    ans += A[i]*comSum[i]%MOD;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}