#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K; cin >> N >> K;
  ll ans {};
  for (int i = K + 1; i <= N; i++) {
    ans += (i - K) * (N / i);
    ans += ( (N % i) ? max(0, N % i - K + 1) : 0 );
    ans -= (N % i and !K);
  }
  cout << ans << endl;
  return 0;
}
