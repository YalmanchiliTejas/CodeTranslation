#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int A[4000];
ll dp[4000][4000];
int main() {
  ios::sync_with_stdio(false);
  int N, S;
  cin >> N >> S;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  dp[0][0] = 1;
  ll MOD = 998244353;
  ll ret = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<=S; j++) {
      dp[i+1][j] = dp[i][j];
    }
    for (int j=0; A[i] + j<=S; j++) {
      dp[i+1][A[i]+j] = (dp[i+1][A[i]+j] + dp[i][j]) % MOD;
    }
    dp[i+1][A[i]] = (dp[i+1][A[i]] + i) % MOD;
    ret = (ret + dp[i+1][S]) % MOD;
  }
  cout << ret << endl;
}