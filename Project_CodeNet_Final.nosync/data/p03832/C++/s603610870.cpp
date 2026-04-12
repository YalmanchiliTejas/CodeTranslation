#include<bits/stdc++.h>
using namespace std;
using I = long long;
const I M = 1e9+7;
vector<I> factorial = {1};
I power(I m, I n) {
  if(!n) return 1;
  return (n & 1) ? (power(m, n - 1) * m % M) : power(m * m % M, n >> 1);
}
I inverse(I n) {
  return power(n, M - 2);
}
I memo[1001][1001];
I combination(I n, I r) {
  if(memo[n][r]) return memo[n][r];
  return memo[n][r] = (r % n == 0ll ? 1ll : (combination(n - 1, r - 1) + combination(n - 1, r)) % M);
}
int main() {
  I N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  while(factorial.size() <= N) factorial.emplace_back(factorial.back() * factorial.size() % M);
  vector<I> dp(N+1);
  dp[0] = 1;
  for(auto i=A; i<=B; ++i) if(i*C <= N) {
    auto dup = dp;
    auto c = 1ll;
    for(auto k=1ll; k<=(C-1); ++k) {
      c = c * combination(i*k, i) % M;
      c = c * inverse(k) % M;
    }
    for(auto j=0ll; j<N; ++j) if(dup[j]) {
      auto d = c;
      for(auto k=C; k<=D && j+i*k<=N; ++k) {
        d = d * combination(i*k, i) % M;
        d = d * inverse(k) % M;
        auto e = d * combination(N-j, i*k) % M;
        dp[j+i*k] += dup[j] * e % M;
        dp[j+i*k] %= M;
      }
    }
  }
  cout << dp[N] << endl;
}
