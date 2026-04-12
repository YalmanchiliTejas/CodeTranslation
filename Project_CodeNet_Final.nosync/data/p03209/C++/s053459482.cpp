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

vector<ll> burgerSize;
vector<ll> numberOfPatties;

// B BPPPB P BPPPB B
ll solve(ll n, ll x) {
  if (n == 0) return 1;

  ll size = burgerSize[n-1];
  ll patties = numberOfPatties[n-1];

  if (x <= 1) {
    return 0;
  } else if (x <= size + 1) {
    return solve(n-1, x-1);
  } else if (x <= size + 2) {
    return 1 + patties;
  } else if (x <= 2 * size + 2) {
    return solve(n - 1, x - (size + 2)) + patties + 1;
  } else {
    return 2 * patties + 1;
  }
}

int main() {
  ll N, X;
  cin >> N >> X;

  burgerSize.push_back(1);
  numberOfPatties.push_back(1);
  for (ll i = 0; i < N; i++) {
    burgerSize.push_back(2 * burgerSize[i] + 3);
    numberOfPatties.push_back(2 * numberOfPatties[i] + 1);
  }

  cout << solve(N, X) << endl;
  return 0;
}
