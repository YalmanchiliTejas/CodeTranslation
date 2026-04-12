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
    auto itr = std::lower_bound(dp.begin(), dp.end(), A[i]);
    itr--;
    *itr = A[i];
  }
  int counter=N-1;
  while (counter>=0){
    //printf("dp[%d]=%d\n", counter, dp[counter]);
    if (dp[counter]==-1){
      break;
    }
    counter--;
  }
  std::cout << N-1-counter << std::endl;
  return 0;
}