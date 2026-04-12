#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  ll n, x, m;
  cin >> n >> x >> m;
  x %= m;
  vi v{(int)x}, hash(m);
  ll cycle = -1, l = x, i = 1;
  hash[x] = 1;
  for (; i < n; i++) {
    ll t = (l * l) % m;
    if (hash[t]) {
      for (int k = 0; k < sz(v); k++) {
        if (v[k] == t) {
          cycle = k;
          break;
        }
      }
      break;
    }
    hash[t] = 1;
    l = t;
    v.push_back(t);
  }

  if (cycle == -1) {
    ll res = 0;
    for (auto e : v)
      res += e;
    cout << res;
    return 0;
  }
  
  ll res = 0;
  for (int j = 0; j < cycle; j++)
    res += v[j];
  ll len = i - cycle;
  ll t = (n - cycle) / len;
  ll r = n, tmp = 0;
  r -= cycle + t * len;

  for (int j = 0; j < len; j++) {
    if (j < r) {
      res += v[cycle + j];
    }
    tmp += v[cycle + j];
  }

  res += tmp * t;
  cout << res;
}