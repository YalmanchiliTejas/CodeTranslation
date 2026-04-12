#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = std::int64_t;
using P = std::tuple<int,int>;

constexpr ll MOD = 998244353;
int N, S;
int A[3100];
ll dp[3100][3100];

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> S;

  for(int i=0;i<N;++i){
      std::cin >> A[i];
  }

  ll res = 0;

  for(int i=0;i<N;++i){
      for(int j=0;j<=S;++j){
          dp[i+1][j] = dp[i][j];
      }

      for(int j=0;j+A[i]<=S;++j){
          dp[i+1][j+A[i]] = (dp[i+1][j+A[i]] + dp[i][j]) % MOD;
      }

      dp[i+1][A[i]] = (dp[i+1][A[i]] + i + 1) % MOD;

      // for(int j=0;j<=S;++j){
      //     std::cout << dp[i+1][j] << " ";
      // }
      // std::cout << std::endl;

      ll x = dp[i+1][S] - dp[i][S];
      if(x < 0){
          x += MOD;
      }

      res = (res + x * (N - i) % MOD) % MOD;
  }

  std::cout << res << std::endl;
}
