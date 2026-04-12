#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S; cin >> S;
  int K; cin >> K;

  int len = S.size();
  int K_MAX = 4;
  vector<vector<ll>> eq(len, vector<ll>(K_MAX + 1, 0));
  vector<vector<ll>> lt(len, vector<ll>(K_MAX + 1, 0));

  eq[0][1] = 1;
  lt[0][1] = S[0] - '1';
  lt[0][0] = 1;

  for (ll i = 1; i < len; i++) {
    int d = S[i] - '0';
    for (ll k = 0; k < K_MAX; k++) {
      if (d == 0) {
        eq[i][k] += eq[i - 1][k];
      } else {
        eq[i][k + 1] += eq[i - 1][k];
        lt[i][k + 1] += eq[i - 1][k] * (d - 1);
        lt[i][k] += eq[i - 1][k];
      }
      lt[i][k + 1] += lt[i - 1][k] * 9;
      lt[i][k] += lt[i - 1][k];
    }
  }

  cout << (eq[len - 1][K] + lt[len - 1][K]) << '\n';
  return 0;
}