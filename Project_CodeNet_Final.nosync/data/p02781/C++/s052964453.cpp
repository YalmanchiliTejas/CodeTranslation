#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  vector<vector<vector<int>>> DP(N + 1, vector<vector<int>>(K + 1, vector<int>(2)));
  DP.at(0).at(0).at(0) = 1;
  for (int dig = 0; dig < N; dig++) {
    for (int not0 = 0; not0 <= K; not0++) {
      for (int id = 0; id < 2; id++) {
        int tmp = S.at(dig) - '0';
        for (int num = 0; num < 10; num++) {
          int next_dig = dig + 1, next_not0 = not0, next_id = id;
          if (id == 0) {
            if (num > tmp) continue;
            if (num < tmp) next_id = 1;
          }
          if (num != 0) next_not0++;
          if (next_not0 > K) continue;
          DP.at(next_dig).at(next_not0).at(next_id) += DP.at(dig).at(not0).at(id);
        }
      }
    }
  }
  cout << DP.at(N).at(K).at(0) + DP.at(N).at(K).at(1) << "\n";
}