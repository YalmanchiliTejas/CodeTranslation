#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int K;
  cin >> K;
  int64_t dp[S.size()+1][4][2];
  for(int i=0; i<S.size()+1; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<2; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  
  for(int i=0; i<S.size(); i++){
    int x = S.at(i) - '0';
    for(int j=0; j<4; j++){
      for(int k=0; k<2; k++){
        for(int a=0; a<10; a++){ //次の桁をどうするか
          int ni = i+1;
          int nj = j;
          int nk = k;  //遷移先
          if(a != 0){
            nj++;
          }
          if(nj > K){
            continue;
          }
          if(x > a && k == 0){
            nk = 1;
          }
          if(x < a && k == 0){
            continue;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  
  cout << dp[S.size()][K][0] + dp[S.size()][K][1] << endl;
}