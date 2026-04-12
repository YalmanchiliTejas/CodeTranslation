// 桁DPのテンプレ
// Nを入力するとN以下の自然数の数(=N)のmodQを出力

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// N ... 最大桁数
#define N 1000
#define Q 1000000007

#define rep(i,f,t) for(int i=f; i<t; i++)

int main(void){
  char n[N+1];
  int len, m;
  long long dp[N][2][5]; // digit, less, non-zero
  
  cin >> n;
  cin >> m;
  len = strlen(n);
  
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  rep(i,0,len) rep(j,0,2) rep(k,0,4){
    int mx = j ? 9 : n[i]-'0'; // 今の桁に入れられる最大値
    for (int dig=0; dig<=mx; dig++){
      int ii, jj, kk;
      ii = i+1;
      jj = j || (dig<mx); // すでにlessまたは今入れようとしてる数がn[i]未満
      kk = k + (dig==0?0:1);
      
      dp[ii][jj][kk] = (dp[ii][jj][kk] + dp[i][j][k]) % Q;
    }
  }
  
  printf("%lld\n", (dp[len][0][m]+dp[len][1][m])%Q);
  return 0;
}
