#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;

ll solve() {
  if (K == 0) return N * N;
  ll r = 0;
  for (ll b = K + 1; b <= N; ++b) {
    r += ((N + 1) / b) * (b - K) + max(0ll, (N + 1) % b - K);
  }
  return r;
}
int main() {
  cin >> N >> K;
  cout << solve() << endl;
  return 0;
}
