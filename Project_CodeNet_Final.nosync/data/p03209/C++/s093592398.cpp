#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define size_t int

long r = 0;

void f(long p, long n) {
  long m = 4 * pow(2, n - 1) - 1;
  if (n == 0) {
    r += p;
    return;
  }
  if (p == 1 || p == 0) {
    return;
  } else if (p == m) {
    r += pow(2, n);
    return;
  } else if (p == m*2 - 1) {
    r += pow(2, n + 1) - 1;
    return;
  } else if (p < m) {
    f(p - 1, n - 1);
  } else if (p > m) {
    r += pow(2, n);
    f(p - m, n - 1);
  }
}

int main(int argc, char const *argv[]) {
  long N, X;
  scanf("%ld %ld", &N, &X);
  f(X, N);
  printf("%ld\n", r);
  return 0;
}
