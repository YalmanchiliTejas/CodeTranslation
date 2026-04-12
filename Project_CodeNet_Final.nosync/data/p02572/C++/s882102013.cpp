#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  vector<ll> sum = A;
  ll mod = pow(10, 9) + 7;
  for (ll i = N - 1; i > 0; --i) {
    sum.at(i - 1) += sum.at(i);
    sum.at(i - 1) %= mod;
  }
  ll ans = 0;
  for (ll i = 0; i < N - 1; ++i) {
    ans = (ans + A.at(i) * sum.at(i + 1) % mod) % mod;
  }
  cout << ans << "\n";
}
