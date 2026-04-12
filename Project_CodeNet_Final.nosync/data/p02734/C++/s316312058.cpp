#include <iostream>
#include <vector>
 
using ll = long long;
using namespace std;
 
#define MOD 998244353
 
int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i< N; i++) cin >> A[i];
  vector<ll> dp(S+1, 0);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    vector<ll> next(S+1, 0);
    (dp[0] += 1) %= MOD;
    for (int j = 0; j <= S; j++) {
      (next[j] += dp[j]) %= MOD;
      if (j+A[i] <= S) (next[j+A[i]] += dp[j]) %= MOD;
    }
    swap(next, dp);
    (ans += dp[S]) %= MOD;
  }
  cout << ans << endl;
}