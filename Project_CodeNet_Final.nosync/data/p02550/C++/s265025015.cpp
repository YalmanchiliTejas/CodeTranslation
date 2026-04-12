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
  ll n, x, m;
  cin >> n >> x >> m;
  deque <ll> a = {x};
  vector <int> vis(m, 0);
  vis[x] = 1;
  int s = 0;
  while (true) {
    ll add = (1LL * a.back() * a.back()) % m;
    if (vis[add]) {
      s = vis[add];
      break;
    }
    a.pb(add);
    vis[add] = sz(a);
  }
  if (n <= s) {
    ll ret = 0;
    for (int i = 0; i < n; i++) {
      ret += a[i];
    }
    cout << ret << '\n';
    return (0);
  }
  ll ret = 0;
  for (int i = 0; i < s - 1; i++) {
    ret += a.front();
    a.pop_front();
    n -= 1;
  }
  int lambda = sz(a);
  ll xx = n / lambda;
  ll yy = n % lambda;
  ret += xx * accumulate(all(a), 0LL);
  for (int i = 0; i < yy; i++) {
    ret += a[i];
  }
  cout << ret << '\n';
  return (0);
}
