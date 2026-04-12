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
  ll ans = 0;
  for (int i = K + 1; i <= N; i++) {
    ans += N / i * (i - K) + max(0LL, N % i - K + 1);
  }
  cout << ans << endl;

  return 0;
}