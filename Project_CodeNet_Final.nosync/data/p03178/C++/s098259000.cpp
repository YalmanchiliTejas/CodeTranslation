#include<bits/stdc++.h>
using namespace std;
int main(){
  string K;
  cin >> K;
  int64_t L;
  cin >> L;
  int64_t dp[K.size()+1][L][2]; 
  for(int i=0; i<K.size()+1; i++){
    for(int j=0; j<L; j++){
      for(int k=0; k<2; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  
  
  
  for(int i=0; i<10; i++){
    if(i < K.at(0) - '0'){
      dp[1][i%L][0] += 1;
    }
    if(i == K.at(0) - '0'){
      dp[1][i%L][1] += 1;
    }
  }
  
  
  int64_t MOD = 1e9+7;
  
  for(int i=1; i<K.size(); i++){
    for(int j=0; j<L; j++){
      for(int k=0; k<2; k++){
        for(int l=0; l<10; l++){
          int ni = i+1;
          int nj = (j+l) % L;
          int nk = k;
          if(k == 1 && l > K.at(i) - '0'){
            continue;
          }
          if(k == 1 && l < K.at(i) - '0'){
            nk = 0;
          }
          dp[ni][nj][nk] += dp[i][j][k];
          dp[ni][nj][nk] %= MOD;
        }
      }
    }
  }
  
  int64_t ans = dp[K.size()][0][0] + dp[K.size()][0][1] - 1;
  if(ans < 0){
    ans += MOD;
  }
  
  
  cout << ans << endl;
}

