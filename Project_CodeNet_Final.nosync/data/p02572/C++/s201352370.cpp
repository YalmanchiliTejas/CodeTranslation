#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int N;
  cin >> N;
  vector<int> A(N), ac(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    ac[i + 1] = ac[i] + A[i];
  }

  const int mod = 1e9 + 7;
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int t = A[i] * ((ac[N] - ac[i + 1]) % mod) % mod;
    (ans += t) %= mod;
  }
  cout << ans << endl;
}
