#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000000 + 7;

int64_t f1(int64_t x, int64_t y) {
  if(y == 0) {
    return 1;
  }
  else {
    int64_t ans = f1(x, y / 2) * f1(x, y / 2) % MOD;
    if(y % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    return ans;
  }
}

int main() {
  int64_t N, M, K;
  cin >> N >> M >> K;
  int64_t A = 1;
  for(int64_t i = 0; i < K - 2; i++) {
    A *= N * M - 2 - i;
    A %= MOD;
  }
  int64_t B = 1;
  for(int64_t i = 1; i <= K - 2; i++) {
    B *= i;
    B %= MOD;
  }
  A *= f1(B, MOD - 2);
  A %= MOD;
  int64_t X = (N - 1) * N * (N + 1) / 6;
  X %= MOD;
  X *= M;
  X %= MOD;
  X *= M;
  X %= MOD;
  X *= A;
  X %= MOD;
  int64_t Y = (M - 1) * M * (M + 1) / 6;
  Y %= MOD;
  Y *= N;
  Y %= MOD;
  Y *= N;
  Y %= MOD;
  Y *= A;
  Y %= MOD;
  cout << (X + Y) % MOD << endl;
}
