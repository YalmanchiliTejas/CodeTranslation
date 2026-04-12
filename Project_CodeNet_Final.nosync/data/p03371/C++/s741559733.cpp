#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  if (a + b >= 2 * c) {
    ll z = min(x, y);
    ans += 2 * c * z;
    x -= z;
    y -= z;
  }
  if (a >= 2 * c) ans += 2 * c * x;
  else ans += a * x;
  if (b >= 2 * c) ans += 2 * c * y;
  else ans += b * y;
  cout << ans << endl;
}