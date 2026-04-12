#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const LL M = 998244353;

int main() {
  LL N, S;
  cin >> N >> S;
  vector<LL> A(N);
  for(auto& i: A) cin >> i;

  LL ans = 0;
  vector<LL> dp(S+2);
  for(auto i=0; i<N; ++i) {
    auto x = min(S+1, A[i]);
    for(auto j=S; x<=j; --j) (dp[j] += dp[j-x]) %= M;
    dp[x] += i+1;
    (ans += dp[S]) %= M;
  }
  cout << ans << endl;
}
