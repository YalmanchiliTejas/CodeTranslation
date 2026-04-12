#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main(){
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  
  vector<vector<long long>> dp(N + 1, vector<long long>(S + 1, 0));
  dp[N][0] = 1;
  for(int R = N - 1; R >= 0; R--){
    dp[R][0] = 1;
    for(int j = 0; j <= S; j++){
      (dp[R][j] += dp[R + 1][j]) %= mod;
      if(j + A[R] <= S) (dp[R][j + A[R]] += dp[R + 1][j]) %= mod;
    }
  }
  
  long long sum = 0;
  for(int L = 0; L < N; L++){
    (sum += dp[L][S]) %= mod;
  }
  
  cout << (sum + mod) % mod << endl;
  
  return 0;
}