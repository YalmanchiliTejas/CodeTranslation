#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

vll ply_memo(51, 0);
ll ply(ll n) {
  if (ply_memo[n] > 0) return ply_memo[n];
  if (n == 0) return 1;
  else return ply_memo[n] = 2 * ply(n - 1) + 3;
}

vll bs_memo(51, 0);
ll bs(ll n) {
  if (bs_memo[n] > 0) return bs_memo[n];
  if (n == 0) return 1;
  else return bs_memo[n] = 2 * bs(n - 1) + 1;
}

void solve(ll n, ll x, ll &ans) {
  if (x == 1) {
    if (n == 0) ans++;
    return;
  }
  if (x == ply(n)) ans += bs(n);
  else if (x > ply(n) / 2 + 1) {
    ans += bs(n - 1) + 1;
    solve(n - 1, x - ply(n) / 2 - 1, ans);
  }
  else if (x > ply(n) / 2) ans += bs(n - 1) + 1;
  else solve(n - 1, x - 1, ans);
}

int main() {
  ll n, x;
  cin >> n >> x;
  ll ans = 0;
  solve(n, x, ans);
  cout << ans << endl;
}