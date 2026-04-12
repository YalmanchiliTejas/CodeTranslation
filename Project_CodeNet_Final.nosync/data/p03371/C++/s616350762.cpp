#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
vi d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  if (a >= 2 * c) {
    ans += 2 * c * x;
    y -= x;
    x = 0;
    if (y > 0) {
      if (b >= 2 * c) ans += 2 * c * y;
      else ans += b * y;
    }
  }
  else if (b >= 2 * c) {
    ans += 2 * c * y;
    x -= y;
    y = 0;
    if (x > 0) ans += a * x;
  }
  else if (a + b >= 2 * c) {
    ans += 2 * c * min(x, y);
    while (x > 0 && y > 0) {
      x--;
      y--;
    }
    if (x > 0) ans += a * x;
    else ans += b * y;
  }
  else ans += a * x + b * y;
  cout << ans << endl;
}