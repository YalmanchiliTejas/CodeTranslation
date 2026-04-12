#include<bits/stdc++.h>
using namespace std;
const int N_MAX = 3010;
int64_t dp[N_MAX][N_MAX];
bool decide[N_MAX][N_MAX];
int vec[N_MAX];

int64_t calc(int i, int j, int n){
  if(decide[i][j]){
    return dp[i][j];
  }
  if(i == j){
    if(n %2 == 0){
      dp[i][j] = vec[i]*-1;
    }
    else{
      dp[i][j] = vec[i];
    }
    decide[i][j] = true;
  }
  else{
    if((n - (j-i+1)) %2 == 0){ //Aさんのターン
      dp[i][j] = max(calc(i+1,j,n) + vec[i], (calc(i,j-1,n) + vec[j]));
    }
    else{
      dp[i][j] = min(calc(i+1,j,n) - vec[i], (calc(i,j-1,n) - vec[j]));
    }
    decide[i][j] = true;
  }
  return dp[i][j];
}

int main(){
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  cout << calc(0,N-1,N) << endl;
}