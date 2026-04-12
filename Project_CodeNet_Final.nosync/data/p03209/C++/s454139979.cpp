#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
long long pow2(int n) {
  if (n == 0) {
	  return 1;
	}
  if (n % 2 == 1) {
	  return 2 * pow2(n - 1);
	}
  else {
	  long long a = pow2(n / 2);
	  return a * a;
	}
}

long long ans(long long N, long long X) {
  if (N == 0) {
	  return 1;
	}
  if (X == 1) {
	  return 0;
	}
  if (X <= pow2(N + 1) - 2) {
	  return ans(N - 1, X - 1);
	}
  if (X == pow2(N + 1) - 1) {
	  return pow2(N);
	}
  if (X <= pow2(N + 2) - 4) {
	  return pow2(N) + ans(N - 1, X - (pow2(N + 1) - 1));
	}
  return pow2(N + 1) - 1;
}

int main() {
  long long N, X;
  cin >> N >> X;
  cout << ans(N, X) << endl;
  return 0;
}
