#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int N;
static long long X;

static vector<long long> B;
static vector<long long> P;

long long f(int N, long long X) {
  if (N == 0) {
    if (X <= 0) {
      return 0;
    } else {
      return 1;
    }
  } else if (X <= 1 + B[N - 1]) {
    return f(N - 1, X - 1);
  } else {
    return P[N - 1] + 1 + f(N - 1, X - 2 - B[N - 1]);
  }
}

void solve(int N, long long X) {
  B.resize(N + 1);
  P.resize(N + 1);
  B[0] = 1;
  P[0] = 1;
  for (int i = 0; i < N; i++) {
    B[i + 1] = 2 * B[i] + 3;
    P[i + 1] = 2 * P[i] + 1;
  }
  printf("%lld\n", f(N, X));
}

int main() {
  cin >> N >> X;
  solve(N, X);
  return 0;
}
