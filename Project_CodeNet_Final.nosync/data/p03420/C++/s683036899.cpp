#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> K;
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  ll ans = N * N - K * N;
  for (int i = K + 1; i <= N; i++) {
    ans -= (N / i) * K + min(K - 1, N % i);
  }
  cout << ans << endl;

  return 0;
}