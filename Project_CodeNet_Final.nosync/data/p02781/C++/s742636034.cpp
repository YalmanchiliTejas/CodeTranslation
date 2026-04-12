#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
  string s;
  int K;
  cin >> s >> K;
  int n = s.size();
  vector<int> a;
  for (auto c : s) a.push_back(c - '0');

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (K + 1, vector<int> (2)));
  dp[0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k < 2; k++) {
        for (int d = 0; d < 10; d++) {
          int ni = i + 1;
          int nj = j + !!d;
          int nk = (k && d >= a[i]);
          if (nj > K) continue;
          if (k && d > a[i]) continue;
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n][K][0] + dp[n][K][1] << endl;
}