#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  vector<vector<vector<int>>> DP(N + 1, vector<vector<int>>(K + 1, vector<int>(2)));
  DP.at(0).at(0).at(0) = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 2; k++) {
        int d = S.at(i) - '0';
        for (int nd = 0; nd < 10; nd++) {
          int ni = i + 1, nj = j, nk = k;
          if (!k) {
            if (nd > d) continue;
            if (nd < d) nk = 1;
          }
          if (nd) nj++;
          if (nj > K) continue;
          DP.at(ni).at(nj).at(nk) += DP.at(i).at(j).at(k); 
        }
      }
    }
  }
  cout << DP.at(N).at(K).at(0) + DP.at(N).at(K).at(1) << "\n";
}