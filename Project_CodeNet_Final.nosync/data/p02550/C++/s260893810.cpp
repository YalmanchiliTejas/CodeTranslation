#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, x, m;
  cin >> n >> x >> m;
  
  vector<vector<ll>> G(m);
  ll now = x, cyclelen, cycleacc, taillen, tailacc, keep;
  vector<ll> d(m, -1), acc(m);
  d[x] = 0;
  acc[x] = x;
  while (true) {
    ll next = (now * now) % m;
    if (d[next] == -1) {
      d[next] = d[now] + 1;
      acc[next] = acc[now] + next;
      now = next;
    }
    else {
      cyclelen = d[now] - d[next] + 1;
      cycleacc = acc[now] - acc[next] + next;
      keep = next;
      now = next;
      taillen = d[now];
      tailacc = acc[now] - now;
      break;
    }
  }
  
  ll ans = 0, res = n;
  if (res < taillen) {
    keep = x;
    while (res > 0) {
      ans += keep;
      res--;
      keep = keep * keep % m;
    }
  }
  else {
    ans += tailacc;
    res -= taillen;
    ll times = res / cyclelen;
    ans += cycleacc * times;
    res %= cyclelen;
    while (res > 0) {
      ans += keep;
      res--;
      keep = keep * keep % m;
    }
  }
  
  cout << ans << '\n';
}