#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll MOD = 998244353;
  vector<vector<int>> n(N + 1, vector<int>(S + 1, 0));
  vector<vector<int>> l(N + 1, vector<int>(S + 1, 0));
  vector<vector<int>> r(N + 1, vector<int>(S + 1, 0));
  n[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S + 1; j++) {
      n[i + 1][j] = (n[i + 1][j] + n[i][j]) % MOD;
      l[i + 1][j] = (l[i + 1][j] + n[i][j]) % MOD;
      l[i + 1][j] = (l[i + 1][j] + l[i][j]) % MOD;
      r[i + 1][j] = (r[i + 1][j] + n[i][j]) % MOD;
      r[i + 1][j] = (r[i + 1][j] + l[i][j]) % MOD;
      r[i + 1][j] = (r[i + 1][j] + r[i][j]) % MOD;
      if (j + A[i] <= S) {
        l[i + 1][j + A[i]] += n[i][j];
        l[i + 1][j + A[i]] += l[i][j];
        r[i + 1][j + A[i]] += n[i][j];
        r[i + 1][j + A[i]] += l[i][j];
      }
    }
  }
  // for (int i = 0; i <= N; i++) {
  //   for (int j = 0; j <= S; j++) {
  //     cout << n[i][j] << ' ';
  //   }
  //   cout << "  ";
  //   for (int j = 0; j <= S; j++) {
  //     cout << l[i][j] << ' ';
  //   }
  //   cout << "  ";
  //   for (int j = 0; j <= S; j++) {
  //     cout << r[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  cout << (r[N][S] % MOD) << '\n';
  return 0;
}
