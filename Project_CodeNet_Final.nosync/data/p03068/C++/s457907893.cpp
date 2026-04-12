#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;

  rep(i, N) {
    if (S[i] != S[K - 1])
      cout << '*';
    else
      cout << S[i];
  }

  return 0;
}