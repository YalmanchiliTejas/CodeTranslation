#include <bits/stdc++.h>
using namespace std;


int main() {
  long long N,K;
  cin >> N;
  K = N/2;
  vector<long long> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  long long ans = 0;
  long long term = 0;
  vector<vector<long long>> dp(K,vector<long long> (3,0));
  if (N % 2 == 0) {
    for (int i=0; i<N; i+=2) {
      term += A[i];
    }
    ans = term;
    for (int i=N-1; i>=0; i-=2) {
      term += A[i];
      term -= A[i-1];
      ans = max(term,ans);
    }
  }
  else {
    dp[0][0] = A[0];
    dp[0][1] = max(A[0],A[1]);
    dp[0][2] = max(dp[0][1],A[2]);
    for (int i=1; i<K; i++) {
      dp[i][0] = dp[i-1][0] + A[i*2];
      dp[i][1] = max(dp[i][0],dp[i-1][1] + A[i*2+1]);
      dp[i][2] = max(dp[i][1],dp[i-1][2] + A[i*2+2]);
    }
    ans = dp[K-1][2];
  }
  cout << ans << endl;

}