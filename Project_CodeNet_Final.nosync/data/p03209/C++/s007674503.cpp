#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;
ll MOD = 1000000007;

// a^p
// 2^3 = 2 * 2^2
// 2^2 = 2 * (2^1)
// 2^1 = 2
ll modpow(ll a, ll p, ll mod) {
  if (p == 0) return 1;

  if (p % 2 == 0) {
    ll half = modpow(a, p / 2, mod) % mod;
    return half * half % mod;
  } else {
    return a * modpow(a, p - 1, mod) % mod;
  }
}

// nCa を求める
ll modCombination(ll n, ll a, ll mod) {
  if (n - a < a) {
    return modCombination(n, n - a, mod);
  }

  ll denominator = 1;  // 分母
  ll numerator = 1;    // 分子

  for (ll i = 0; i < a; i++) {
    denominator *= a - i;
    numerator *= n - i;
    denominator %= mod;
    numerator %= mod;
  }

  return numerator * modpow(denominator, mod - 2, mod) % mod;
}

// B Burger(L-1) P Burger(L-1) B
ll solve(vector<ll> sizeOfBurger, vector<ll> numberOfPutties, ll level, ll x) {
  if (x == 0) return 0;
  if (level == 0) return 1;

  ll length = sizeOfBurger[level - 1];
  ll putties = numberOfPutties[level - 1];

  if (x == 1) {
    return 0;
  }
  else if (x <= length + 1 ) {
    return solve(sizeOfBurger, numberOfPutties, level - 1, x -1);
  }
  else if (x <= length + 2) {
    return putties + 1;
  }
  else if (x < 2 * length + 2) {
    return putties + 1 + solve(sizeOfBurger, numberOfPutties, level - 1, x - 2 - length);
  }
  else {
    return 2 * putties + 1;
  }
}

int main() {
  ll N, X;
  cin >> N >> X;

  vector<ll> sizeOfBurger(N+1, 0);
  vector<ll> numberOfPutties(N+1, 0);

  sizeOfBurger[0] = 1;
  numberOfPutties[0] = 1;

  for (ll i = 1; i <= N; i++) {
    sizeOfBurger[i] = 2 * sizeOfBurger[i-1] + 3;
    numberOfPutties[i] = 2 * numberOfPutties[i-1] + 1;
  }

  ll ans = solve(sizeOfBurger, numberOfPutties, N, X);
  cout << ans << endl;
  return 0;
}
