#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL
ll modPow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n-1, p)) % p;
  ll t = modPow(a, n/2, p);
  return (t * t) % p;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll temp = 0, sub = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    temp += a[i];
    temp %= MOD;
    sub += a[i] * a[i];
    sub %= MOD;
  }

  cout << ((((((temp * temp) % MOD) + MOD) - sub) % MOD) * modPow(2, MOD-2, MOD)) % MOD << endl;

}
