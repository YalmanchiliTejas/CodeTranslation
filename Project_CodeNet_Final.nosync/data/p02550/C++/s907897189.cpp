#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
const ll mod = (ll)998244353;

ll powmod(ll a, ll k, ll m) {
  if (k == 0) return 1;
  ll t = powmod(a, k / 2, m);
  t = (t * t) % mod;
  if (k % 2 == 1) t = (t * a) % mod;
  return t;
}

int vis[1 << 17];
long pre[1 << 17];

int main() {
  ll n;
  ll x, m;
  cin >> n >> x >> m;
  map<ll, int> mp;
  vector<ll> val;
  int idx = 0;
  auto it = mp.end();
  ll idxsum = 0;
  while ((it = mp.find(x)) == mp.end() && n > 0) {
    val.push_back(x);
    mp[x] = idx++;
    idxsum += x;
    x = (x * x) % m;
    n--;
  }
  if (n == 0) {
    cout << idxsum << endl;
    return 0;
  }
  int loop = idx - it->second;
  //n -= idx;
  ll loopsum = 0;
  for (int i = it->second; i < idx; i++) {
    loopsum += val[i];
  }
  ll mult = n / loop;
  n -= loop * mult;
  ll modsum = 0;
  for (int i = it->second; --n >= 0; i++) {
    modsum += val[i];
  }

  ll ans = idxsum + loopsum * mult + modsum;
  cout << ans << endl;

  return 0;
}
