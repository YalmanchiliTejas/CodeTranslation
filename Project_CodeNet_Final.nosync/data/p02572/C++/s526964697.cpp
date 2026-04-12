#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
template <class T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);
int main() {  // TODO
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll s = 0;

  ll ans = 0;
  rep1(N) {
    ll a;
    cin >> a;
    ll aa = a % MOD;
    ans = (ans % MOD) + ((aa % MOD) * s);
    s = (s % MOD) + (a % MOD);
  }

  cout << ans % MOD << endl;

  return 0;
}