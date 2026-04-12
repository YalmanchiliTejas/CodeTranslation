#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

ll pty(ll lev) {
  if (lev == 0) return 1;
  return pty(lev - 1) * 2 + 1;
}

ll ply(ll lev) {
  if (lev == 0) return 1;
  return ply(lev - 1) * 2 + 3;
}

ll solve(ll n, ll x) {
  ll m = ply(n);
  if (x <= 1) return 0;
  if (x < m / 2) return solve(n - 1, x - 1);
  if (x == m / 2) return pty(n - 1);
  if (x == m / 2 + 1) return pty(n - 1) + 1;
  if (x < m - 1) return pty(n - 1) + 1 + solve(n - 1, x - m / 2 - 1);
  if (x >= m - 1) return pty(n - 1) * 2 + 1;
}

int main() {
  ll n, x;
  cin >> n >> x;
  cout << solve(n, x) << endl;
}