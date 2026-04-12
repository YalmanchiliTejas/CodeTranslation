#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  vector<vector<long long>> dp(3010, vector<long long>(3010, 0));
  for (int len = 1; len <= N; len++) {
    for (int i = 0; i <= N - len; i++) {
      int j = i + len;
      if ((N - len) % 2 == 0) {
        dp.at(i).at(j) = max(dp.at(i+1).at(j) + a.at(i), dp.at(i).at(j-1) + a.at(j-1));
      }
      else {
        dp.at(i).at(j) = min(dp.at(i+1).at(j) - a.at(i), dp.at(i).at(j-1) - a.at(j-1));
      }
    }
  }
  cout << dp.at(0).at(N) << endl;
}