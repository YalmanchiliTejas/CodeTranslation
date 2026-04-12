#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  if (N % 2 == 0){
    vector<vector<long long>> dp(N / 2 + 1, vector<long long>(2, 0));
    //0: left 1: right
    for (int i = 0; i < N / 2; i++){
      dp[i + 1][0] = dp[i][0] + A[i * 2];
      dp[i + 1][1] = max(dp[i][0], dp[i][1]) + A[i * 2 + 1];
    }
    cout << max(dp[N / 2][0], dp[N / 2][1]);
  } else {
    vector<vector<long long>> dp(N / 2 + 1, vector<long long>(3, 0));
    for (int i = 0; i < N / 2; i++){
      dp[i + 1][0] = dp[i][0] + A[i * 2];
      dp[i + 1][1] = max(dp[i][0], dp[i][1]) + A[i * 2 + 1];
      dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]}) + A[i * 2 + 2];
    }
    cout << max({dp[N / 2][0], dp[N / 2][1], dp[N / 2][2]});
  }
}