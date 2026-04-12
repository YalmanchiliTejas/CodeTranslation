#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define rrep(i, a, b) for(int i=(a); i>=(b); i--)
typedef long long ll;

int main()
{
  string S; cin >> S;
  int K; cin >> K;
  int len = S.size();
  vector<vector<ll>> dp0(len+1, vector<ll>(5, 0));
  vector<vector<ll>> dp1(len+1, vector<ll>(5, 0));
  dp1[0][0] = 1;
  for (int i=0; i<len; i++) {
    for (int k=0; k<K+1; k++) {
      if (S[i] != '0') {
        dp0[i+1][k] += dp0[i][k] + dp1[i][k];
      } else {
        dp0[i+1][k] += dp0[i][k];
        dp1[i+1][k] += dp1[i][k];
      }
      for (int d=1; d<10; d++) {
        if (d < S[i] - '0') {
          dp0[i+1][k+1] += dp0[i][k] + dp1[i][k];
        } else if (d == S[i] - '0') {
          dp0[i+1][k+1] += dp0[i][k];
          dp1[i+1][k+1] += dp1[i][k];
        } else {
          dp0[i+1][k+1] += dp0[i][k];
        }
      }
    }
  }
  cout << dp0[len][K] + dp1[len][K] << endl;

  return 0;
}
