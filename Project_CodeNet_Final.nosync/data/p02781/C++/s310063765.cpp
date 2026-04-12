#include<iostream>
#include<cstdint>
#include<string>

int const MAXNL = 100;
int const MAXK = 3;

int64_t dp1[MAXNL+1][MAXK+1] = {0};
int64_t dp2[MAXNL+1][MAXK+1] = {0};
std::string N;
int K;

int main() {
  std::cin >> N >> K;
  int l = N.size();
  dp1[0][0] = 1;
  for(int i = 0; i < l; ++i) {
    int d = N[i] - '0';
    // dp1[i][k] -> ...
    if(d > 0) {
      // dp1[i][k] -> d
      for(int k = 0; k+1 <= K; ++k) dp1[i+1][k+1] += dp1[i][k];
      // dp1[i][k] -> [1,d)
      for(int k = 0; k+1 <= K; ++k) dp2[i+1][k+1] += dp1[i][k]*(d-1);
      // dp1[i][k] -> 0
      for(int k = 0; k <= K; ++k) dp2[i+1][k] += dp1[i][k];
    } else {
      // dp1[i][k] -> 0
      for(int k = 0; k <= K; ++k) dp1[i+1][k] += dp1[i][k];
    }
    // dp2[i][k] -> ...
    //   dp2[i][k] -> ... [1,9]
    for(int k = 0; k+1 <= K; ++k) dp2[i+1][k+1] += dp2[i][k]*9;
    //   dp2[i][k] -> ... 0
    for(int k = 0; k <= K; ++k) dp2[i+1][k] += dp2[i][k];
  }
  std::cout << dp1[l][K] + dp2[l][K] << std::endl;
  return 0;
}
