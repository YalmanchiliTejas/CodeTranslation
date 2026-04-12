#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll a, ll n) {
  ll ret = 1;
  while(n) {
    ret =ret * ((n % 2) ? a : 1) % MOD;
    a = a * a % MOD;
    n>>=1;
  }
	return ret;
}

ll comb(ll N, ll R) {
  if (N < 0 || R < 0 || N < R) return 0;
  ll n = 1, r = 1;
  R = min(R, N - R);
  for (ll i = 1; i <= R; i++) {
    n = n * N % MOD;
    r = r * i % MOD;
    N--;
  }
  return n * modpow(r, MOD - 2) % MOD;
}

int main() {
  ll N,M,K;
  cin>>N>>M>>K;
  ll ans = 0;
  for (ll d = 1; d < N; d++) ans = (ans + d * (N - d) * M * M) % MOD;
  for (ll d = 1; d < M; d++) ans = (ans + d * (M - d) * N * N) % MOD;
  ans = (ans * comb(N * M - 2, K - 2)) % MOD;
  cout<<ans<<endl;
  return 0;
}