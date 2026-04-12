#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string N; int K, dp[105][2][105];
int main() {
  cin >> N >> K;
  int lng = N.size(); dp[0][0][0] = 1;
  for(int i = 1; i <= lng; ++i) {
    int n = N.at(i-1)-'0';
    for(int j = 0; j < 2; ++j) {
      for(int k = 0; k <= i; ++k) {
        for(int d = 0; d <= (j?9:n); ++d) {
          dp[i][j||d<n][k+(d>0)] += dp[i-1][j][k];
        }
      }
    }
  }
  cout << dp[lng][0][K]+dp[lng][1][K] << endl;
}