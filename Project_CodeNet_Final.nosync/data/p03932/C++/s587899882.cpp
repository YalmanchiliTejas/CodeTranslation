#include<bits/stdc++.h>
using namespace std;
 
int h, w, a1[400][400], a2[400][400], dp[400][400][400];
 
signed main()
{
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a1[i][j];
    }
  }
 
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      a2[i + j][i - j + w] = a1[i][j];
    }
  }
 
  dp[0][w][w] = a1[0][0];
 
  for(int i = 1; i <= h + w - 2; i++){
    for(int j = 1; j <= h + w - 1; j++){
      for(int k = 1; k <= h + w - 1; k++){
	dp[i][j][k] = max({dp[i - 1][j - 1][k - 1], dp[i - 1][j - 1][k + 1], dp[i - 1][j + 1][k - 1], dp[i - 1][j + 1][k + 1]});
	if(j == k){
	  dp[i][j][k] += a2[i][j];
	}
	else{
	  dp[i][j][k] += a2[i][j] + a2[i][k];
	}
      }
    }
  }
  
  cout << dp[h + w - 2][h][h] << endl;
  return 0;
}