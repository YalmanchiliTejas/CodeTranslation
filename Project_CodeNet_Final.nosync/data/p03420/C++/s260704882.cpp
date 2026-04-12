#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  //k == あまり
  for (ll k = K; k <= N - 1; ++k) {
    // ans += N - k;
    ll cnt = 0;
    while (true) {
      if (k + (k + 1) * cnt > N) {
        break;
      }
      ll l = max(1ll, k), r = N + 1;
      while (l + 1 != r) {
        ll m = (l + r) / 2;
        if (k + m * cnt <= N) {
          l = m;
        }
        else {
          r = m;
        }
      }
      ans += l - k;
      // i == b
      // for (ll i = k + 1; i <= N; ++i) {
      //   if (k + i * cnt == 0) {
      //     continue;
      //   }
      //   if (k + i * cnt <= N) {
      //     // cout << "あまり " << k << ' ' << "a:" << k + i * cnt << " b:" << i << endl;
      //     ans += 1;
      //   }
      //   else {
      //     break;
      //   }
      // }
      cnt += 1;
    }
  }
  if (K == 0) {
    ans -= N;
  }
  cout << ans << endl;
}
