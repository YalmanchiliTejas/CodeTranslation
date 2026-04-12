#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//最大公約数
long long gcd(long long a, long long b) {
  if (a < b) std::swap(a, b);
  long long r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll i = k + 1; i <= n; i++) {
    ll a, b = i;
    ans += (b - k) * (n / b);
    if (n % b > 0 && n % b > k - 1) {
      ans += n % b - max(0ll, k - 1);
    }
  }
  cout << ans << endl;
}