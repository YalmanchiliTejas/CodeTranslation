#include <iostream>
#include <string>
using namespace std;

int main() {
  long long N; cin >> N;
  long long A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  
  if (N % 2 == 0){
    long long dp[N][2]; for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = -10000000000000000;
    for (long long i = 0; i < N; i++){
      if (i == 0) dp[i][0] = A[i];
      else if (i == 1) {
        if (i == N - 1) dp[i][0] = dp[i - 1][0];
        dp[i][1] = A[i];
      }
      else {
        if (i >= 2) dp[i][0] = dp[i - 2][0] + A[i];
        if (i == N - 1) dp[i][0] = dp[i - 1][0];
        if (i >= 3) dp[i][1] = dp[i - 3][0] + A[i];
        if (i >= 2) dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
      }
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
  }
  else {
    long long dp[N][3]; 
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) dp[i][j] = -10000000000000000;
    for (long long i = 0; i < N; i++){
      if (i == 0) dp[i][0] = A[i];
      else if (i == 1) dp[i][1] = A[i];
      else if (i == 2) {
        dp[i][2] = A[i];
        if (i <= N - 2) dp[i][0] = dp[i - 2][0] + A[i];
        else dp[i][0] = dp[i - 2][0];
        if (i == N - 1) dp[i][1] = dp[i - 1][1];
      }
      else {
        if (i >= 2 && i <= N - 3) dp[i][0] = dp[i - 2][0] + A[i];
        if (i >= N - 2) dp[i][0] = dp[i - 2][0];
        if (i >= 3) dp[i][1] = dp[i - 3][0] + A[i];
        if (i >= 2) dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
        if (i == N - 1) dp[i][1] = max(dp[i][1], dp[i - 1][1]);
        if (i >= 4) dp[i][2] = dp[i - 4][0] + A[i];
        if (i >= 3) dp[i][2] = max(dp[i][2], dp[i - 3][1] + A[i]);
        if (i >= 2) dp[i][2] = max(dp[i][2], dp[i - 2][2] + A[i]);
      }
    }
    cout << max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << endl;
  }
}