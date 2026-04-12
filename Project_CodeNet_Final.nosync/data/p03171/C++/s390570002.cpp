#include<iostream>
#include<vector>
using namespace std;

long long calc_dp(int i, int j, vector<vector<long long>>& dp, vector<long long>& a){
  int N = dp.size();
  if(dp[i][j] != 1e15){
    return dp[i][j];
  }

  calc_dp(i + 1, j, dp, a);
  calc_dp(i, j - 1, dp, a);
  if(N % 2 == (j - i) % 2){
    // jiro
    dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
  }else{
    // taro
    dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
  }
  return dp[i][j];
}

int main(){
  int N;
  cin >> N;

  vector<long long> a(N);
  for(auto& aa: a){
    cin >> aa;
  }

  // dp[i][j] := [i, j]
  vector<vector<long long>> dp(N, vector<long long>(N, 1e15));
  for(int i = 0; i < N; i++){
    dp[i][i] = a[i];
    if(N % 2 == 0){
      dp[i][i] *= -1;
    }
  }
  
  cout << calc_dp(0, N - 1, dp, a) << endl;
  

}
