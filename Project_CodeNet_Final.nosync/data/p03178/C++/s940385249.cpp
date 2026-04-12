#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define long long 

const int K_SIZE = 2e5;
const int MAX_D = 110;
const int MOD = 1e9+7;

int dp[K_SIZE][MAX_D][2];

void modadd(int &a, int b){
  a = (a+b)%MOD;
}

signed main(void){
  
  string K; cin >> K;
  int D; cin >> D;
  
  //初期値について
  
  for(int i = 0; i <= (int)(K[0]-'0'); i++){
    if( i == (int)(K[0]-'0')){ dp[1][i%D][1]++;}
    else{ dp[1][i%D][0]++;}
  }
  
  for(int i = 1; i < (int)K.size(); i++){
    for(int j = 0; j < D; j++){ 
      
      for(int x = 0; x < 10; x++){
        modadd(dp[i+1][(j+x)%D][0],dp[i][j][0]);
      }
      for(int x = 0; x < (int)(K[i]-'0');x++){
        modadd(dp[i+1][(j+x)%D][0],dp[i][j][1]);
      }
        modadd(dp[i+1][(j+(int)(K[i]-'0'))%D][1],dp[i][j][1]);
      
    }
  }
  
  int N = K.size();
  
  cout << (dp[N][0][1]+dp[N][0][0]-1+MOD)%MOD << endl;
  
  return 0;
  
}
                
    