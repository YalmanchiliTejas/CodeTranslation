#include <iostream>
#include <string>

std::string K;
int d;

int dp[10001][100][2];
constexpr int mod = 1000000007;

int main(){
  std::cin >> K;
  std::cin >> d;
  int n = K.length();
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < d; j++){
      for(int k = 0; k < 10; k++){
        int l = (10 * d + j - k) % d;
        dp[i][j][0] += dp[i-1][l][0];
        if(dp[i][j][0] >= mod) dp[i][j][0] -= mod;
        if(k == K[n-i]-'0') dp[i][j][1] += dp[i-1][l][1];
        if(k <  K[n-i]-'0') dp[i][j][1] += dp[i-1][l][0];
        if(dp[i][j][1] >= mod) dp[i][j][1] -= mod;
      }
    }
  }
  std::cout << (dp[n][0][1] + mod-1) % mod << std::endl;
  return 0;
}
