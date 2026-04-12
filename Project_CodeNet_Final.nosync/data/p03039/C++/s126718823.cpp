#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll pow(ll a, ll n) {
  ll res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}

ll fact(int n) {
  ll res = 1;
  for (int i = 2; i <= n; i++)
    res = res * i % MOD;
  return res;
}

ll comb(ll n, ll r) {
  ll inv_fact_p = pow(fact(n-r), MOD-2);
  ll inv_fact_q = pow(fact(r), MOD-2);
  ll tmp = inv_fact_p * inv_fact_q % MOD;
  return tmp * fact(n) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, K; cin >> N >> M >> K;
    ll res = 0;
    for (int i = 1; i < N; i++) {
        res += (N - i) * M * M * i % MOD;
        res %= MOD;
    }
    for (int i = 1; i < M; i++) {
        res += (M - i) * N * N * i % MOD;
        res %= MOD;
    }
    cout << comb(N*M-2, K-2) * res % MOD << "\n";
}