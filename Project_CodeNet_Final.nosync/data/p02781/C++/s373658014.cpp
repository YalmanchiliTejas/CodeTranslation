#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S; cin >> S;
  ll d = S.size();
  int K; cin >> K;

  vector<vector<ll>> eq(d, vector<ll>(5, 0));
  vector<vector<ll>> lt(d, vector<ll>(5, 0));

  eq[0][1] = 1;
  lt[0][1] = S[0] - '0' - 1;
  lt[0][0] = 1;

  for (ll i = 1; i < d; i++) {
    int temp = S[i] - '0';
    if (temp == 0) {
      for (ll k = 0; k < 4; k++) {
        eq[i][k] += eq[i - 1][k];
      }
    } else {
      for (ll k = 0; k < 4; k++) {
        eq[i][k + 1] += eq[i - 1][k];
        lt[i][k + 1] += eq[i - 1][k] * max(0, temp - 1);
      }
      for (ll k = 0; k < 4; k++) {
        lt[i][k] += eq[i - 1][k];
      }
    }

    for (ll k = 0; k < 4; k++) {
      lt[i][k + 1] += lt[i - 1][k] * 9;
      lt[i][k] += lt[i - 1][k];
    }
  }

  
  cout << (eq[d - 1][K] + lt[d - 1][K]) << '\n';
  return 0;
}