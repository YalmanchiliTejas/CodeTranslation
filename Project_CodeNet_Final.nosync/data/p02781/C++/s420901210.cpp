#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ing long long 

int dp[110][5],ap[110][5];

signed main(void){ 
  string N; cin >> N;
  int K; cin >> K;
  int n = (int)N.size();
  
  dp[0][1] = 1; //N[0]に一致する場合のみ
  ap[0][1] = (int)(N[0]-'0')-1; // 1,,,,N[0]-1までのみ
  ap[0][0] = 1; //0の場合
  
  for(int i = 0; i < n-1; i++){ 
    // N[i]からN[i+1]への遷移を考える
    for(int j = 0; j <= K; j++){ 
      
      ap[i+1][j+1] += ap[i][j]*9;
      ap[i+1][j] += ap[i][j]; //s+1個目で0を出した場合のみ
      
      if( N[i+1] != '0'){
        ap[i+1][j] += dp[i][j]*1;
        ap[i+1][j+1] += dp[i][j]*( (int)(N[i+1]-'0')-1 );
      }
      
      if(  N[i+1] != '0'){
        dp[i+1][j+1] += dp[i][j];
      }
      else{
        dp[i+1][j] += dp[i][j];
      }//else
    }//for-j
  }//for-i
  
  
  cout << dp[n-1][K] + ap[n-1][K] << endl;
  
  return 0;
}
