#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
ll N;
vector<ll> Inv, Pow2, Fact, InvFact;
ll Res;

int main() {
  cin >> N;
  Res = 1;
  for (ll i = 0; i < N; ++i) (Res *= 3) %= MOD;
  Inv.resize(N + 1);
  Inv[1] = 1;
  for (ll i = 2; i <= N; ++i) {
    Inv[i] = MOD - MOD / i * Inv[MOD % i] % MOD;
  }
  Pow2.resize(N + 1);
  Fact.resize(N + 1);
  InvFact.resize(N + 1);
  Pow2[0] = Fact[0] = InvFact[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    Pow2[i] = 2 * Pow2[i - 1] % MOD;
    Fact[i] = i * Fact[i - 1] % MOD;
    InvFact[i] = Inv[i] * InvFact[i - 1] % MOD;
  }
  for (ll k = N / 2 + 1; k <= N; ++k) {
    (Res += MOD - 2 * Pow2[N - k] * Fact[N] % MOD * InvFact[k] % MOD *
                      InvFact[N - k] % MOD) %= MOD;
  }
  cout << Res << endl;
  return 0;
}
