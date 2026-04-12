#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> V(N);
  for (auto &x : V) cin >> x;
  vector<ll> W = V;
  sort(W.begin(), W.end());
  int B = W[N / 2];
  int C = W[N / 2 - 1];
  for (int i = 0; i < N; i++) {
    if (V[i] <= C) {
      cout << B << endl;
    } else {
      cout << C << endl;
    }
  }
}