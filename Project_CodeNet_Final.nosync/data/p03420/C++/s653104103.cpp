#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K; cin >> N >> K;
  ll ans {};
  for (int i = K + 1; i <= N; i++) {
    ans += max(0, i - K) * (N / i);
    ans += max(0, N % i - K + 1);
  }
  cout << ans - (!K * N) << endl;
  return 0;
}
