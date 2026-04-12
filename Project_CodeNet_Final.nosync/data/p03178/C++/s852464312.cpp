#include <iostream>
#include <string>
using namespace std;

using ll = long long;
int MOD  = 1e9 + 7;

template <class T> void Add(T& a, const T& b, const T& mod = MOD) {
  auto value = ((a % mod) + (b % mod)) % mod;
  if(value < 0)
    value += mod;
  a = value;
}

int dp[10010][2][110];

int main() {
  string K;
  int D;
  cin >> K >> D;

  dp[0][0][0] = 1;

  for(int k = 0; k < K.size(); ++k) {
    for(int smaller : {0, 1}) {
      int limit = smaller ? 9 : (K[k] - '0');
      for(int i = 0; i <= limit; ++i) {
        for(int d = 0; d < D; ++d) {
          Add(dp[k + 1][smaller || (i < limit)][(d + i) % D], dp[k][smaller][d]);
        }
      }
    }
  }
  int ans = 0;
  for(int smaller : {0, 1}) {
    Add(ans, dp[K.size()][smaller][0]);
  }
  Add(ans, -1);
  cout << ans << endl;

  return 0;
}