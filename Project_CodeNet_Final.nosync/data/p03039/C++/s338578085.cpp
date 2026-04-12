#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll N, M, K;
vector<ll> Inv, Fact, InvFact;

void init(ll limit) {
  Inv.resize(limit + 1);
  Fact.resize(limit + 1);
  InvFact.resize(limit + 1);
  Inv[1] = 1;
  Fact[0] = Fact[1] = InvFact[0] = InvFact[1] = 1;
  for (ll i = 2; i <= limit; ++i) {
    Inv[i] = MOD - MOD / i * Inv[MOD % i] % MOD;
    Fact[i] = i * Fact[i - 1] % MOD;
    InvFact[i] = Inv[i] * InvFact[i - 1] % MOD;
  }
}
ll choose(ll n, ll k) {
  return Fact[n] * InvFact[k] % MOD * InvFact[n - k] % MOD;
}
ll perm(ll n, ll k) { return Fact[n] * InvFact[n - k] % MOD; }
ll calc(ll m, ll n) {
  ll res = 0;
  for (ll i = 1; i <= n - 1; ++i) {
    (res += i * 2 * (n - i) * m * m) %= MOD;
  }
  return res;
}
ll solve() {
  return choose(K, 2) * (calc(M, N) + calc(N, M)) % MOD *
         perm(N * M - 2, K - 2) % MOD * InvFact[K] % MOD;
}
int main() {
  cin >> N >> M >> K;
  init(N * M);
  cout << solve() << endl;
  return 0;
}
