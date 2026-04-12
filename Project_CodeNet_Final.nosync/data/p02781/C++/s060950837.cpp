#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <unordered_set>
#include <ctime>
typedef long long int llint;

llint dp[1000][5] = {};

int main(void){

  std::string N;
  llint K;
  std::cin >> N >> K;

  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 9;
  for(int keta=2; keta<200; keta++){
    for(int k=0; k<4; k++){
      dp[keta][k] += dp[keta-1][k];
      dp[keta][k+1] += dp[keta-1][k]*9;
    }
  }

  
  std::vector<std::pair<int, int> > data;  
  
  llint result = 0;
  while(N.size() != 0){
    llint i_ketame = N[0]-'0';
    if(i_ketame == 0){
      N = N.substr(1);
      continue;
    }
    
    for(llint j=0; j<i_ketame; j++){
      data.push_back(std::make_pair(N.size()-1, j==0?K:K-1));
    }
    N = N.substr(1);
    K--;
    if(K<0) break;
  }
  if(K==0) result++;
  for(const auto& elem: data){
    if(elem.second<0) continue;
    //std::cout << elem.first << " " << elem.second << std::endl;
    //std::cout << dp[elem.first][elem.second] << std::endl;;
    result += dp[elem.first][elem.second];
  }
  std::cout << result << std::endl;
  
  return 0;
}
