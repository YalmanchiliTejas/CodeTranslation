#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, mod = 1000000007;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll sum = 0;
  ll ans = 0;
  for (int i = 0; i < A.size(); i++) {
    ans += sum * A[i];
    ans %= mod;
    sum += A[i];
    sum %= mod;
  }

  cout << ans << endl;

  return 0;
}