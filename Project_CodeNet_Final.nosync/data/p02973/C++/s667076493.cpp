#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  std::vector<int > dp(N, -1);
  for (int i=0; i<N;i++){
    scanf("%d", &A[i]);
  }
  for (int i=0; i<N; i++){
    //printf("i=%d\n", i);
    auto itr = std::lower_bound(dp.rbegin(), dp.rend(), A[i]);
    if (itr==dp.rbegin()){
      dp.push_back(A[i]);
    } else {
      itr--;
      *itr = A[i];
    }
  }
  int counter=0;
  while (counter<N){
    //printf("dp[%d]=%d\n", counter, dp[counter]);
    if (dp[counter]==-1){
      break;
    }
    counter++;
  }
  std::cout << counter << std::endl;
  return 0;
}