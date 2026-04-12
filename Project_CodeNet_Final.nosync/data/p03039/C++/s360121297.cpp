#include "bits/stdc++.h"
using namespace std;

#define REMNUM 1000000007

// x+y
static inline long modadd(long x, long y) {
  return (long)((long long)(x + y) % REMNUM);
}

// x*y
static inline long modmul(long x, long y) {
  return (long)(((long long)(x * y)) % REMNUM);
}

// x^y
static long modpow(long x, long y) {
  long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = modmul(res, x);
    }
    x = modmul(x, x);
    y >>= 1;
  }

  return res;
}

static inline long modinv(long x) {
  return modpow(x, REMNUM - 2);
}

// x/y
static inline long moddiv(long x, long y) { return modmul(x, modinv(y)); }

// xCy => x*(x-1)*...*(x-y+1)/y*(y-1)*...*1
static long combination(long x, long y) {
  long divided = 1;
  long divisor = 1;

  for (int i = 0; i < y; i++) {
    divided = modmul(divided, (x - i));
    divisor = modmul(divisor, (y - i));
  }

  return moddiv(divided, divisor);
}

int main(int argc, char **argv) {
  long N, M, K;

  cin >> N >> M >> K;

  long comb = combination((modmul(N, M) - 2), (K - 2));

  long xsum = 0, xfixed;
  for (long d = 1; d < M; d++) {
    xfixed = modmul(comb, d);
    xfixed = modmul(modmul(N, N), xfixed);
    xfixed = modmul((M - d), xfixed);
    xsum = modadd(xsum, xfixed);
  }

  long ysum = 0, yfixed;
  for (long d = 1; d < N; d++) {
    yfixed = modmul(comb, d);
    yfixed = modmul(modmul(M, M), yfixed);
    yfixed = modmul((N - d), yfixed);
    ysum = modadd(ysum, yfixed);
  }

  cout << modadd(xsum, ysum) << endl;

  return 0;
}
