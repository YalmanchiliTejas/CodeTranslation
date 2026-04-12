#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  for (ll b = K + 1; b <= N; b ++) {
    for (ll sho = 0; sho * b <= N; sho ++) {
      ll kj = 0;
      if (sho * b + b - 1 <= N) kj = b - K;
      else {
        kj = max(0ll, N - sho * b - K + 1);
      }
      ans += kj;
    }
  }
  if (K == 0) ans -= N;
  cout << ans << endl;
}
