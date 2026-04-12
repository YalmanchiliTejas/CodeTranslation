#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

int dp[101][4][2];

int main(){
  std::string N;
  int K;
  std::cin >> N;
  scanf("%d",&K);
  std::vector<int > num;
  for (int i=0; i<N.length(); i++){
    num.push_back(int(N[i])-int('0'));
  }
  std::reverse(num.begin(), num.end());

  for (int i=0; i<101; i++){
    for (int j=0; j<4; j++){
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }

  dp[0][0][1] = 1;
  for (int i=0; i<N.length(); i++){
    dp[i+1][0][1] = 1;
    for (int j=1; j<=3; j++){
      int val = num[i];
      //printf("val=%d\n",val);
      //printf("dp[%d][%d][1]=%d\n",i,j-1,dp[i][j-1][1]);
      //printf("dp[%d][%d][0]=%d\n",i,j-1,dp[i][j-1][0]);
      if (val!=0){
        dp[i+1][j][1] = (dp[i][j][1]+dp[i][j][0])+(val-1)*(dp[i][j-1][1]+dp[i][j-1][0])+dp[i][j-1][1];
        dp[i+1][j][0] = (9-val)*(dp[i][j-1][0]+dp[i][j-1][1])+dp[i][j-1][0];
      } else {
        dp[i+1][j][1] = dp[i][j][1];
        dp[i+1][j][0] = dp[i][j][0] + 9*(dp[i][j-1][0]+dp[i][j-1][1]);
      }
      //printf("dp[%d][%d][1]=%d+%d+%d=%d\n",i+1,j,dp[i][j][1],(val-1)*(dp[i][j-1][1]+dp[i][j-1][0]),dp[i][j-1][1],dp[i+1][j][1]);
      //printf("dp[%d][%d][0]=%d\n",i+1,j,dp[i+1][j][0]);
    }
  }
  printf("%d\n",dp[N.length()][K][1]);
  return 0;
}
