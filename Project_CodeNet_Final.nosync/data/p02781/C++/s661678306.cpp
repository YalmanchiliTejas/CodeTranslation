#include<iostream>
#include<string>
using namespace std;

int main() {
  int D, N[110], K; string S;
  cin >> S >> K; D = S.size();
  if (D < K) cout << 0 << endl;
  else {
    int W = D - K + 1;
    int i, j, d, A[K+1][W+1], B[K+1][W+1];
    for (d = 0; d < D; d++) {
      N[d] = stoi(S.substr(d, 1));
    }
    for (i = 0; i <= K; i++) {
      for (j = 0; j <= W; j++) {
        A[i][j] = B[i][j] = 0;
      }
    }
    for (j = 0; j <= W; j++) A[0][j] = 1;
    i = 0; j = 1;
    for (d = 0; d < D; d++) {
      B[i][j] = 9 - N[d];
      if (N[d]) i++; else j++;
      if (i > K || j > W) break;
    }
    for (i = 1; i <= K; i++) {
      for (j = 1; j <= W; j++) {
        A[i][j] = A[i][j-1] + A[i-1][j] * 9 - B[i-1][j];
      }
    }
    cout << A[K][W] << endl;
  }
}