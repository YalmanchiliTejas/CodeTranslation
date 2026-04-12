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
  for (ll i = max(1ll, K); i <= N; ++i) {
    ans += N / i * max(0ll, (i - K));
    ans += max(0ll, (N % i) - K + 1);
  }
  if (K == 0) {
    ans -= N;
  }
  cout << ans << endl;
}
