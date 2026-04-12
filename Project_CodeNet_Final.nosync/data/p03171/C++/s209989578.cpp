#include<iostream>
#include<vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];  
  vector<vector<int64_t>> DP(N+1, vector<int64_t>(N+1, 0));
                         
  for(int length = 1; length <= N; ++length) {
    for(int lp = 0; (lp + length) <= N; ++lp) {
      int rp = lp + length;
      bool first = ((N - length) % 2) == 0;
      if(first) {
        DP[lp][rp] = max(DP[lp+1][rp] + A[lp], DP[lp][rp-1] + A[rp-1]);
      } else {
        DP[lp][rp] = min(DP[lp+1][rp] - A[lp], DP[lp][rp-1] - A[rp-1]);
      }
    }
  }
  cout << DP[0][N] << endl;
  return 0;
}