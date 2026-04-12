// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 03/26/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  string N; cin>>N;
  int K; cin>>K;
  vector<array<int, 4>> dpe(N.size()), dpl(N.size());
  dpe[0][1] = 1;
  dpl[0][1] = N[0]-'1';
  dpl[0][0] = 1;
  for (int i = 1; i < N.size(); i++) {
    auto n = N[i]-'0';
    if (n == 0) {
      dpe[i] = dpe[i-1];
    } else {
      for (int j = 1; j < 4; j++) {
        dpe[i][j] = dpe[i-1][j-1];
        dpl[i][j] += dpe[i-1][j-1]*(n-1) + dpe[i-1][j];
      }
    }
    for (int j = 0; j < 4; j++) {
      dpl[i][j] += dpl[i-1][j];
    }
    for (int j = 1; j < 4; j++) {
      dpl[i][j] += dpl[i-1][j-1]*9;
    }
  }
  auto ans = dpe.back()[K] + dpl.back()[K];
  cout << ans << endl;

  return 0;
}
