#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
ll const MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> tmp(n, 0);
  tmp[n-1] = a[n-1];
  for(ll i = n-2; i >= 1; i--) {
    tmp[i] = (tmp[i+1] + a[i]) % MOD;
  }

  ll ans = 0;
  rep(i, n-1) {
    ans =  (ans + ((a[i] * tmp[i+1]) % MOD)) % MOD;
  }

  cout << ans << endl;

  return 0;
}
