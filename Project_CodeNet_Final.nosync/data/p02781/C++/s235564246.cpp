#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;

int main() {
  string s;
  cin >> s;
  int K;
  cin >> K;
  int n = s.size();
  vector<vector<int>> dp(2, vector<int>(K + 2, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> ndp(2, vector<int>(K + 2, 0));
    int c = s[i] - '0'; 
    for (int j = 0; j < 2; j++) {
      for (int d = 0; d <= (j ? 9 : c); d++) {
        for (int k = 0; k <= K; k++) {
          ndp[j | (d < c)][k + (d != 0)] += dp[j][k];
        }
      }
    }
    dp = move(ndp);
  }
  cout << dp[0][K] + dp[1][K] << endl;
  return 0;
} 