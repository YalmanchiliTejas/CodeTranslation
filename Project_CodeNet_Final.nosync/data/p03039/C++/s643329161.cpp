#include <iostream>
#include <vector>
 
using namespace std;
 
using ll = long long;
 
vector<ll> fact;
vector<ll> ifact;
const int mod = 1e9 + 7;
 
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll ret = (n & 1) ? x : 1;
  ll half = mod_pow(x, n / 2, mod);
  ret *= half * half % mod;
  return ret % mod;
}
 
void init() {
  const int f_max = 200000;
  fact.resize(f_max + 1);
  ifact.resize(f_max + 1);
  fact[0] = 1;
  for(int i = 1; i <= f_max; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  ifact[f_max] = mod_pow(fact[f_max], mod - 2, mod);
  for(int i = f_max - 1; i >= 0; i--) {
  	ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
  }
}

ll comb(ll n, ll k) {
  return fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}
 
 
int main() {
  init();
  ll N, M, K;
  cin >> N >> M >> K;
  ll sum = 0;
  for(ll d = 1; d <= N; d++) {
    sum += (d * (N - d)) % mod * M % mod * M % mod;
    sum %= mod;
  }
  for(ll d = 1; d <= M; d++) {
    sum += (d * (M - d)) % mod * N % mod * N % mod;
    sum %= mod;
  }
  cout << sum * comb(N * M - 2, K - 2) % mod << endl;
}
