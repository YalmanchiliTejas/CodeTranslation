#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main(){
  string s;
  int D;
  cin >> s >> D;
  int n = sz(s);
  vector<vector<int>> dp(2,vector<int>(D,0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    vector<vector<int>> next(2,vector<int>(D,0));
    for (int j = 0; j < D; j++) {
      for (int k = 0; k < 2; k++) {
        for (int c = 0; c <= (k ? 9 : d); c++) {
          (next[k | (c < d)][(j + c) % D] += dp[k][j] ) %= mod; 
        }
      }
    }
    dp = next;
  }
  cout << (dp[0][0] + dp[1][0] - 1 + mod ) % mod << endl; 
  return 0;
} 