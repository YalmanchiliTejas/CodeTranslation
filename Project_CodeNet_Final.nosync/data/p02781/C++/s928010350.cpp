#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int dp[102][4][2];

int main()
{
  long long ans = 0, temp, down;
  int K, ketasu;
  string S;
  cin >> S >> K;
  ketasu = S.size();
  dp[0][0][0] = 1;
  for(int i = 0; i < ketasu; i++)for(int j = 0; j <= K; j++)for(int k = 0; k < 2; k++){
    int nd = S[i] - '0';
    int ni = i+1;
    for(int d = 0; d < 10; d++){
      int nj = j, nk = k;
      if(d != 0) nj++;
      if(nj > K) continue;
      if(nk == 0){
        if(d > nd) continue;
        if(d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  ans = dp[ketasu][K][0] + dp[ketasu][K][1];
  
  cout << ans << endl;
}