#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

class modint {
  ll n;

public:
  modint(): n(0) {};
  modint(ll _n): n((_n + MOD) % MOD) {}
  modint(const modint &i): n(i.n) {}
  operator ll() const { return n; }

  modint operator+(const modint &i) const { return modint(n + i.n); }
  modint operator-(const modint &i) const { return modint(n - i.n); }
  modint operator*(const modint &i) const { return modint(n * i.n); }
  modint operator/(const modint &i) const { return modint(n * i.inverse().n); }

  modint operator+=(const modint &i) { return *this = *this + i; }
  modint operator-=(const modint &i) { return *this = *this - i; }
  modint operator*=(const modint &i) { return *this = *this * i; }
  modint operator/=(const modint &i) { return *this = *this / i; }

  modint inverse() const {
    modint p = 1, q = n;
    for(ll t = MOD - 2; t > 0; t /= 2) {
      if(t % 2) p *= q;
      q *= q;
    }
    return p;
  }
};

int main(void) {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;

  vector<modint> fact(N + 1);
  fact[0] = 1;
  REP(i, 1, N + 1) fact[i] = fact[i - 1] * modint(i);

  vector< vector<modint> > dp(N + 1, vector<modint>(B + 2, 0));
  REP(i, A, B + 2) dp[0][i] = 1;
  REP(i, 1, N + 1) {
    for(ll j = B; j >= A; j--) {
      modint comb = 1;
      for(ll k = 1; k <= D && i - j * k >= 0; k++) {
        comb *= fact[N - (i - j * k)] / fact[j] / fact[N - (i - j * k) - j];
        if(k >= C) dp[i][j] += dp[i - j * k][j + 1] * comb / fact[k];
      }
      dp[i][j] += dp[i][j + 1];
    }
  }
  cout << dp[N][A] << endl;
}
