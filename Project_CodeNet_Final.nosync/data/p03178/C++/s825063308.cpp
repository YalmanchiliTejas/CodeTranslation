#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>

long long int MOD = 1e9+7;

int main(){
  
  // read problem
  std::string K_string;
  long long int D, digits;
  std::cin >> K_string >> D;
  digits = K_string.length();
  
  std::vector<long long int> K;
  for(long long int i = 0; i < digits; i++){
    K.push_back(K_string[i] - '0');
  }
  
  std::cerr << "K:" << std::endl;
  for(long long int i = 0; i < digits; i++){
    std::cerr << K[i] << " ";
  }std::cerr << std::endl;
  
  // solve problem
  std::vector<std::vector<long long int> > dp_table(digits);
  for(long long int i = 0; i < digits; i++){
    for(long long int j = 0; j < D+1; j++){
      dp_table[i].push_back(0);
    }
  }
  
  // initialize dp_table
  for(long long int i = 0; i < K[0]; i++){
    dp_table[0][(i+D)%D]++;
  }
  dp_table[0][D] = (K[0]+D)%D;
  
  // fill dp_table
  for(long long int i = 1; i < digits; i++){
    // normal cases
    for(long long int j = 0; j < D; j++){
      for(long long int k = 0; k < 10; k++){
        dp_table[i][j] += dp_table[i-1][(j-k+10*D)%D];
        dp_table[i][j] = (dp_table[i][j]+MOD)%MOD;
      }
    }
    // exception cases
    dp_table[i][D] = (dp_table[i-1][D] + K[i]+D)%D;
    for(long long int j = 0; j < K[i]; j++){
      dp_table[i][(dp_table[i-1][D]+j+D)%D]++;
      dp_table[i][(dp_table[i-1][D]+j+D)%D] %= MOD;
    }
  }
  
  /*std::cerr << "dp_table:" << std::endl;
  for(long long int i = 0; i < digits; i++){
    for(long long int j = 0; j <= D; j++){
      std::cerr << dp_table[i][j] << " ";
    }std::cerr << std::endl;
  }*/
  
  long long int ans = dp_table[digits-1][0]-1;
  if(dp_table[digits-1][D]==0){
    ans++;
  }
  ans = (ans+MOD)%MOD;
  
  std::cout << ans << std::endl;
  
  return 0;
}
