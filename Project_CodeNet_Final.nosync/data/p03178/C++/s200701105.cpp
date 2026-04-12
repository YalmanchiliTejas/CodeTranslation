#include <bits/stdc++.h>

const long long mo=1000000000+7;

std::string K;
int D;
long long dp[2][100][10001];//1:strict

int main(){
  std::cin >> K;
  std::cin >> D;
  dp[1][0][0]=1;
  for(int i=0;i<(int)(K.length());++i){
    for(int k=0;k<D;++k){
      for(int j=0;j<=9;++j){
	int nk=(j+k)%D;
	dp[0][nk][i+1]+=dp[0][k][i];
	dp[0][nk][i+1]%=mo;
      }
      for(int j=0;j<(int)(K[i]-'0');++j){
	int nk=(j+k)%D;
	dp[0][nk][i+1]+=dp[1][k][i];
	dp[0][nk][i+1]%=mo;
      }
      int nk=(k+(int)(K[i]-'0'))%D;
      dp[1][nk][i+1]+=dp[1][k][i];
      dp[1][nk][i+1]%=mo;
    }
  }
  std::cout<<(dp[0][0][(int)(K.length())]+dp[1][0][(int)(K.length())]+mo-1)%mo<<std::endl;
  return 0; 
}
