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
#define MOD 998244353ll

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> a;
  vector<bool> isuse(m);
  a.emplace_back(x);
  ll last = x, nx;
  isuse[x] == 0;
  while(1) {
    nx = (last * last) % m;
    if (isuse[nx]) break;
    isuse[nx] = true;
    a.emplace_back(nx);
    last = nx;
  }

  ll ans = 0, now = x, cnt = 0;
  while(nx != now) {
    cnt++;
    if (cnt > n) break;
    ans += now;
    now = (now * now) % m;
  }
  n -= cnt;
  ll loop = 0;
  ll len = 0;
  for (ll as: a) {//loop += as;
    if (as == nx) len++;
    if (len == 0) continue;
    loop += as;
    len++;
    if (as == nx) len--;
  }
  ans += loop * (n / len);

  n %= len;
  now = nx;
  for (int i = 0; i < n; i++) {
    ans += now;
    now = (now * now) % m;
  }
  cout << ans << endl;
}
