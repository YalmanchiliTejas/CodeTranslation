#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

int main(){
  std::string N;
  long long int K, nbits;
  
  std::cin >> N >> K;
  nbits = N.length();

  std::vector<long long int> N_vec;
  for(long long int i = 0; i < nbits; i++){
    N_vec.push_back((long long int)N[i] - '0');
  }

  std::cerr << "N: " << N << std::endl << "K: " << K << std::endl;
  std::cerr << "N_vec:" << std::endl;
  for(long long int i = 0; i < nbits; i++){
    std::cerr << N_vec[i];
  }std::cerr << std::endl;

  // solve problem
  std::vector<std::vector<long long int> > dp(nbits, std::vector<long long int>(K+2));

  dp[0][0] = 1;
  dp[0][1] = N_vec[0]-1;
  dp[0][K+1] = 1;

  for(long long int i = 1; i < nbits; i++){
    // update dp[i][0]
    dp[i][0] = dp[i-1][0];
    // update dp[i][j] 1<=j<=K
    for(long long int j = 1; j <= K; j++){
      dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*9;
    }
    if(dp[i-1][K+1] <= K && N_vec[i] != 0){
      dp[i][dp[i-1][K+1]]++;
    }
    if(dp[i-1][K+1] < K && N_vec[i] != 0){
      dp[i][dp[i-1][K+1]+1] += N_vec[i]-1;
    }
    // update dp[i][K+1]
    if(N_vec[i] != 0){
      dp[i][K+1] = dp[i-1][K+1] + 1;
    }
    else{
      dp[i][K+1] = dp[i-1][K+1];
    }
  }

  if(dp[nbits-1][K+1] == K){
    dp[nbits-1][K]++;
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << dp[nbits-1][K] << std::endl;

  return 0;
}
