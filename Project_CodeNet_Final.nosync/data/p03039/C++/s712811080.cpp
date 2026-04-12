#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll fact[200003];
ll ifact[200003];
ll Combination(ll a,ll b) {
  ll s = (fact[a] * ifact[b]) % Mod;
  return (s * ifact[a-b]) % Mod;
}

int main() {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i <= 200003; i++) {
    fact[i] = fact[i-1] * i;
    fact[i] %= Mod;
    ifact[i] = modinv(fact[i],Mod);
  }
  ll N,M,K;
  cin >> N >> M >> K;
  ll res = 0;
  for (ll i = 0; i < N; i++) {
    ll a = i * (N - i);
    a %= Mod;
    a *= M * M;
    a %= Mod;
    res += a;
    res %= Mod;
  }
  for (ll i = 0; i < M; i++) {
    ll a = i * (M - i);
    a %= Mod;
    a *= N * N;
    a %= Mod;
    res += a;
    res %= Mod;
  }
  ll C = Combination(N*M - 2,K - 2);
  ll ans = res * C;
  ans %= Mod;
  cout << ans << endl;
  return 0;
}