#include <bits/stdc++.h>
 
typedef long long ll;
const int MAX_N = 100000;
 
int main() {
  int N;
  ll s[MAX_N];
  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> s[i];
  }
 
  ll ans = 0;
  for(int C = 1; C < N - 1; ++C) {
    ll dp = 0;
    for(int k = 1; (ll) k * C < N - 1; ++k) {
      int A = N - 1 - k * C;
      int B = A - C;
      if(B <= 0) continue;
      if(A % C == 0 and k * C >= A) continue;
      dp += s[A] + s[k * C];
      ans = std::max(ans, dp);
    }
  }
  std::cout << ans << std::endl;
}