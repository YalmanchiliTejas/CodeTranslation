#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long llong;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];

  int ans = 1;
  int m = H[0];
  for (int i = 1; i < N; i++) {
    if (m > H[i]) continue;
    ans++;
    m = max(m, H[i]);
  }
  cout << ans << endl;
  return 0;
}