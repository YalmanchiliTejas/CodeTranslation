#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<long long>& layers,
                const vector<long long>& paties, int N, long long X) {
  if (N == 0) return 1;
  if (X <= 1) return 0;
  if (X == layers[N - 1] + 2) {
    return paties[N - 1] + 1;
  }
  if (X == 2 * layers[N - 1] + 3) {
    return 2 * paties[N - 1] + 1;
  }
  if (X <= layers[N - 1] + 1) {
    return solve(layers, paties, N - 1, X - 1);
  }
  if (X <= 2 * layers[N - 1] + 2) {
    return paties[N - 1] + 1 +
           solve(layers, paties, N - 1, X - layers[N - 1] - 2);
  }
}

int main(void) {
  int N;
  long long X;
  cin >> N >> X;
  vector<long long> layers(N + 1);
  vector<long long> paties(N + 1);
  layers[0] = paties[0] = 1;
  for (int i = 1; i < N; i++) {
    layers[i] = 2 * layers[i - 1] + 3;
    paties[i] = 2 * paties[i - 1] + 1;
  }
  cout << solve(layers, paties, N, X) << endl;
  return 0;
}