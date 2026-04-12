#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll MOD = 1e9 + 7;
  ll N;
  ll sum = 0;
  ll ans = 0;
  cin >> N;

  for (ll i = 0; i < N; i++) {
    ll temp;
    cin >> temp;
    ans = (ans + temp * sum) % MOD;
    sum = (sum + temp) % MOD;
  }
  cout << ans << endl;
}