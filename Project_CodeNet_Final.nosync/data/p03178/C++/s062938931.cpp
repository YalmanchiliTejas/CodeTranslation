#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(void) {
  string S;
  ll D;
  cin >> S >> D;

  ll N = S.length();
  vector<ll> A(N);
  REP(i, 0, N) {
    A[i] = S[i] - '0';
  }

  vector<vector<ll>> dp1(N, vector<ll>(D));
  vector<vector<ll>> dp2(N, vector<ll>(D));
  dp1[0][A[0] % D]++;
  dp1[0][A[0] % D] %= MOD;
  REP(i, 0, A[0]) {
    dp2[0][i % D]++;
    dp2[0][i % D] %= MOD;
  }

  REP(i, 0, N - 1) {
    REP(j, 0, D) {
      REP(k, 0, 10) {
        ll r = (j + k) % D;
        if (k < A[i + 1]) {
          dp2[i + 1][r] += dp1[i][j];
          dp2[i + 1][r] %= MOD;
        }
        if (k == A[i + 1]) {
          dp1[i + 1][r] += dp1[i][j];
          dp1[i + 1][r] %= MOD;
        }
        dp2[i + 1][r] += dp2[i][j];
        dp2[i + 1][r] %= MOD;
      }
    }
  }

  cout << (dp1[N - 1][0] + dp2[N - 1][0] + MOD - 1) % MOD << endl;
}