#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int main(){
  int N, S;
  cin >> N >> S;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<long long> dp(S + 1, 0);
  long long total = 0;
  for (int i = 0; i < N; i++){
    for (int j = S; j > A[i]; j--){
      dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
    }
    if (A[i] <= S){
      dp[A[i]] = (dp[A[i]] + dp[0] + i + 1) % MOD;
    }
    total += dp[S] * (N - i) % MOD;
    dp[S] = 0;
  }
  cout << total % MOD;
}