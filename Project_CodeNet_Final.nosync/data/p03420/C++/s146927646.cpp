#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N,K;
  cin >> N >> K;
  ll ans = 0;
  if (K == 0) {
    ans = N * N;
  }
  else {
    for (ll b = K+1; b <= N; b++) {
      ans += ((N + 1) / b) * (b - K);
      ans += max(N - (((N + 1) / b) * b) + 1 - K,(ll)(0)); 
    }
  }
  cout << ans << endl;
  return 0;
}