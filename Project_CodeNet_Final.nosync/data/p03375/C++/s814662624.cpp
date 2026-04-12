#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3456;

long long N, M;
long long C[MAX_N][MAX_N], P2[MAX_N], P2P2[MAX_N], way[MAX_N][MAX_N];

long long add(long long a, long long b) { return (a + b) % M; }
long long mul(long long a, long long b) { return (a * b) % M; }

int main() {
  cin >> N >> M;
  
  for (int i = 0; i <= N; ++i) {
    C[i][0] = C[i][i] = 1; 
    for (int j = 1; j < i; ++j) {
      C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }

  for (int i = 0; i <= N * N; ++i) {
    P2[i] = (i == 0 ? 1 : mul(P2[i - 1], 2));
  }

  for (int i = 0; i <= N; ++i) {
    P2P2[i] = (i == 0 ? 2 : mul(P2P2[i - 1], P2P2[i - 1]));
  }

  // divide i to j groups, i-th can appear or not-appear
  memset(way, 0x00, sizeof(way));
  for (int i = 0; i <= N; ++i) {
    way[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      way[i][j] = 0;
      // i-th not-appear
      way[i][j] = add(way[i][j], way[i - 1][j]);
      // i-th appear, self group
      way[i][j] = add(way[i][j], way[i - 1][j - 1]);
      // i-th appear, with-other group
      way[i][j] = add(way[i][j], mul(j, way[i - 1][j]));
    }
  }

  long long res = 0;
  for (int i = 0; i <= N; ++i) {

    long long tmp = 0;
    for (int j = 0; j <= i; ++j) {
      // each j group could have 2^(N-i) types
      tmp = add(tmp, mul(way[i][j], P2[(N - i) * j]));
    }
    tmp = mul(tmp, mul(C[N][i], P2P2[N - i]));

    if (i & 1) res = add(res, M - tmp);
    else res = add(res, tmp);

  }

  cout << res << endl;

  return 0;
}