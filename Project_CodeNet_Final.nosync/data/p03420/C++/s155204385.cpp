#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  for (int i = K + 1; i <= N; i++) {
    ans += floor(N / (i)) * (i - K);
    ll a = N;
    a -= floor(N / i) * i;
    a -= (K - 1);
    ans += max<ll>(0, a);
  }
  cout << ans << endl;
}