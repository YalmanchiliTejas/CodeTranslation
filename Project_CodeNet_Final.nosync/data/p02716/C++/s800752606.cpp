#include<bits/stdc++.h>

const long long INF = 1e15;

using namespace std;

template<typename T>
bool chmax(T& a, const T& b){
  if(a < b){
    a = b;
    return true;
  }else return false;
}

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N + 1);
  A[0] = 0;
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  
  vector<vector<long long>> dp(N + 10, vector<long long>(3, -INF));
  
  dp[0][1] = 0;
  dp[1][0] = A[1];
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= 2; j++){
      if(i + 2 <= N) chmax(dp[i + 2][j], dp[i][j] + A[i + 2]);
      if(i + 1 <= N && j + 1 <= 2) chmax(dp[i + 1][j + 1], dp[i][j]);
    }
  }
  
  cout << dp[N][(N & 1) + 1] << endl;
  
  return 0;
}