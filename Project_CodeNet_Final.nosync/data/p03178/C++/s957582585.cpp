#include<iostream>
#include<cstring>

int const MAXEK = 10000;
int const MAXD = 100;
int const MOD = 1000000007;

char K[MAXEK+1];
int D, L;

int dpK[2][MAXD], dpL[2][MAXD];

int main() {
  std::cin >> K >> D;
  L = std::strlen(K);

  for(int i = 0; i < D; ++i) dpK[0][i] = dpL[0][i] = 0;
  dpK[0][0] = 1; // 0
  int sum = MOD-1;  // exclude 0
  for(int i = 0; i < L; ++i) {
    int c = K[i] - '0';
    for(int j = 0; j < D; ++j) {
      dpK[(i+1)%2][j] = dpK[i%2][(j-c+D*9)%D];
      int tmp = 0;
      for(int k = 0; k < c; ++k) {
        tmp = (tmp + dpK[i%2][(j-k+D*8)%D])%MOD;
      }
      for(int k = 0; k < 10; ++k) {
        tmp = (tmp + dpL[i%2][(j-k+D*9)%D])%MOD;
      }
      dpL[(i+1)%2][j] = tmp;
    }
  }
  sum = (sum + dpK[L%2][0] + dpL[L%2][0])%MOD;
  std::cout << sum << std::endl;
  return 0;
}
