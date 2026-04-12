#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int kMaxn = 2e5 + 5;
const int MOD = 1e9 + 7;
int qpow(int x, int n);
int T, N, M, K;
int p[kMaxn];

int main() {
  //
  scanf("%d", &N);
  int sum = 0, sumpow2 = 0;
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    sum = (sum + x) % MOD;
    sumpow2 = (sumpow2 + qpow(x, 2)) % MOD;
  }
  int ans;
  ans = 1LL * (qpow(sum, 2) - sumpow2 + MOD) % MOD * qpow(2, MOD - 2) % MOD;
  printf("%d\n", ans);
  return 0;
}

int qpow(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return res;
}