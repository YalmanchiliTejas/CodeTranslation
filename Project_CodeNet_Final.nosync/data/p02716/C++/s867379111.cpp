#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5*2 + 10;
int64_t MINF = -1e18;
int64_t dp[MAX][3];

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      dp[i][j] = MINF;
    }
  }
  
  if(N == 2){
    cout << max(vec[0],vec[1]);
  }
  else{
    dp[0][0] = vec[0];
    dp[1][1] = vec[1];
    dp[2][2] = vec[2];
    for(int i=0; i<N; i++){
      for(int j=0; j<3; j++){
        if(dp[i][j] == MINF){
          continue;
        }
        else{
          for(int k=0; k<3; k++){
            if(i + k + 2 < N && j + k < 3){
              dp[i+k+2][j+k] = max(dp[i+k+2][j+k], dp[i][j] + vec[i+k+2]);
            }
          }
        }
      }
    }
    int64_t ans = MINF;
    for(int i=0; i<N; i++){
      for(int j=0; j<3; j++){
        if((i+2-j)/2 == N/2){
          ans = max(ans,dp[i][j]);
        }
      }
    }
    cout << ans << endl;
  }
}