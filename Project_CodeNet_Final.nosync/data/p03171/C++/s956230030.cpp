#include <bits/stdc++.h>

long long dp[3001][3001];// true, false がそれぞれ勝ち、負け

int main(){
  int N;
  int a[3000];
  std::cin>>N;
  for(int i=0;i<N;++i){
    std::cin>>a[i];
  }
  for(int i=0;i<N;++i){
    dp[i][i]=0;
  }
  for(int d=1;d<=N;++d){
    for(int i=0;i+d<=N;++i){
      int j=i+d;
      if((N-d)%2==0){
	//太郎くんの番。X-Yを最大化。
	dp[i][j]=std::max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
      }else{
	dp[i][j]=std::min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
      }
    }
  }
  printf("%ld\n",dp[0][N]);
  return 0;
}
