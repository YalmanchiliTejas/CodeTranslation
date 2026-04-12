#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long R;
#define MAX_N 3000
long long I[MAX_N + 1], F[MAX_N + 1], IF[MAX_N + 1];
long long P[MAX_N + 1], PP[MAX_N + 1];
long long PX[MAX_N + 1][MAX_N + 1];
long long D[MAX_N + 1][MAX_N + 1];

int main() {
  cin >> N >> M;
  I[0] = I[1] = F[0] = F[1] = IF[0] = IF[1] = 1;
  for(int i = 2; i <= N; ++i) {
    I[i] = M - (M / i) * I[M % i] % M;
    F[i] = i * F[i - 1] % M;
    IF[i] = I[i] * IF[i - 1] % M;
  }
  P[0] = 1;
  for(int i = 1; i <= N; ++i) {
    P[i] = 2 * P[i - 1] % M;
  }
  for(int i = 0; i <= N; ++i) {
    PP[i] = 2;
    for(int k = 0; k < i; ++k) {
      (PP[i] *= PP[i]) %= M;
    }
  }
  for(int i = 0; i <= N; ++i) PX[i][0] = 1;
  for(int i = 0; i <= N; ++i) for(int k = 1; k <= N; ++k) {
    PX[i][k] = PX[i][k - 1] * P[i] % M;
  }
  D[0][0] = 1;
  for(int i = 1; i <= N; ++i) for(int j = 0; j <= N; ++j) {
    D[i][j] = (D[i - 1][j] * (j + 1) + (j == 0 ? 0 : D[i - 1][j - 1])) % M;
  }
  for(int i = 0; i <= N; ++i) {
    long long tmp = i % 2 == 0 ? 1 : M - 1;
    (tmp *= (F[N] * IF[i]) % M * IF[N - i] % M) %= M;
    (tmp *= PP[N - i]) %= M;
    long long buf = 0;
    for(int j = 0; j <= i; ++j) {
      (buf += D[i][j] * PX[N - i][j] % M) %= M;
    }
    (tmp *= buf) %= M;
    (R += tmp) %= M;
  }
  cout << R << endl;
  return 0;
}
