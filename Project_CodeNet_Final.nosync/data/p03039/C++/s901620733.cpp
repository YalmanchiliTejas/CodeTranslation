#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

/*
  階乗計算（MODで割った余りで返す）
*/

class Factorial {
    private:
        vector<ll> fac;
    public:
        Factorial();
        Factorial(ll n_max);
        void initialization(ll n_max);
        ll getFactorial(ll n);
};

Factorial::Factorial() {}
Factorial::Factorial(ll n_max) {
    fac.clear();
    fac.push_back(1);
    fac.push_back(1);
    for (ll i = 2; i <= n_max; i++) {
        fac.push_back(fac[i-1] * i % MOD);
    }
}
void Factorial::initialization(ll n_max) {
    fac.clear();
    fac.push_back(1);
    fac.push_back(1);
    for (ll i = 2; i <= n_max; i++) {
        fac.push_back(fac[i-1] * i % MOD);
    }
}
ll Factorial::getFactorial(ll n) {
    return fac[n];
}

/*
  MOD計算
*/
// 割り算のための逆元を求める（mod m での a の逆元）
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u % m;
}

/*
    順列と組み合わせ (P, C, H)
*/

class PCH {
    private:
        Factorial fact;
    
    public:
        PCH(ll n_max);
        ll P(ll n, ll r);
        ll C(ll n, ll r);
        ll H(ll n, ll r);
};
PCH::PCH(ll n_max) {
    fact.initialization(n_max);
}
ll PCH::P(ll n, ll r) {
    return fact.getFactorial(n) % MOD * modinv(fact.getFactorial(n - r), MOD) % MOD;
}

ll PCH::C(ll n, ll r) {
    return fact.getFactorial(n) % MOD * modinv(fact.getFactorial(r), MOD) % MOD * modinv(fact.getFactorial(n - r), MOD) % MOD;
}

ll PCH::H(ll n, ll r) {
    return C(n - 1 + r, r);
}

ll sum(ll i) {
  ll ans = (1 + i) * i / 2;
  ans %= MOD;
  return ans;
}

int main() {
  
  ll N, M, K;
  cin >> N >> M >> K;

  PCH pch(N * M);

  ll ans = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ans += M * (sum(i - 1) + sum(N - i)) % MOD;
      ans += N * (sum(j - 1) + sum(M - j)) % MOD;
      ans %= MOD;
    }
  }

  ans *= pch.C(N * M - 2, K - 2);
  ans %= MOD;

  ans *= modinv(2, MOD);
  ans %= MOD;

  cout << ans << endl;

  return 0;
}