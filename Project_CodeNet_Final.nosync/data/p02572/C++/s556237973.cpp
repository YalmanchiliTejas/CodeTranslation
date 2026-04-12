#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  const int mod = 1e9 + 7;
  auto add = [&] (int x, int y) { return (x + y) % mod; };
  auto mul = [&] (ll x, ll y) { return (x * y) % mod; };
  vi a(n);
  vi acc(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    acc[i] = add(acc[i + 1], a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = add(ans, mul(a[i], acc[i + 1]));
  }
  cout << ans << '\n';
  return (0);
}
