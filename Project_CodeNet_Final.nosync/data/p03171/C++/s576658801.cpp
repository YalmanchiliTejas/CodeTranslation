#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[3005];
int64_t dp[3005][3005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<=N;i++){
    dp[i][i]=0;
  }
  for(int i=N-1;i>=0;i--){
    for(int j=i+1;j<=N;j++){
      dp[i][j]=std::max(as[i]-dp[i+1][j],as[j-1]-dp[i][j-1]);
    }
  }
  printf("%ld\n",dp[0][N]);
  return 0;
}
