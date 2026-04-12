#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll MOD = 1000000007;
  ll N;
  cin >> N;
  vector<ll> A(N);
  sort(A.begin(),A.end());
  ll sum = 0;
  for (auto &e : A) {
    cin >> e;
    sum += e;
  }
  ll ans = 0;
  for (auto e : A) {
    sum -= e;
    ans = ((sum)%MOD * e + ans) % MOD;
  }
  cout << ans << endl;
}