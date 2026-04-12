#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int H, W;
int A[400][400];
int dp[401][400][400];
int D[2] = {0, 1};

int main() {
  cin >> H >> W;
  long long sum = 0;
  for (int y=0; y<H; y++) {
    for (int x=0; x<W; x++) {
      cin >> A[x][y];
      sum += A[x][y];
    }
  }
  if (W == 1 || H == 1) {
    cout << sum << "\n";
    return 0;
  }

  dp[1][0][1] = A[0][0] + A[0][1] + A[1][0];
  for (int i=1; i<W+H-3; i++) {
    int r = 1+i;
    int nr = 2+i;
    for (int a=0; a<r; a++) {
      for (int b=a+1; b<r; b++) {
        for (int ka=0; ka<2; ka++) {
          for (int kb=0; kb<2; kb++) {
            int na = a+D[ka], nb = b+D[kb];
            if (na < 0 || na >= nr || nb < 0 || nb >= nr) continue;
            if (na >= nb) continue;
            if (r-na<0 || r-nb<0) continue;
            dp[i+1][na][nb] = max(dp[i+1][na][nb], dp[i][a][b] + A[na][r-na] + A[nb][r-nb]);
          }
        }
      }
    }
  }
  cout << 0LL + A[W-1][H-1] + dp[W+H-3][W-2][W-1] << "\n";
  return 0;
}
