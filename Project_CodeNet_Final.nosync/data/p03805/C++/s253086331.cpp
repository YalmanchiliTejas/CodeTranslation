#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, m; cin >> n >> m;
  V<set<ll>> nodes(n, set<ll>());
  REP(i, m) {
    ll a, b; cin >> a >> b;
    nodes.at(a-1).insert(b-1);
    nodes.at(b-1).insert(a-1);
  }
  vll perm(n);
  iota(perm.begin(), perm.end(), 0);
  ll ans = 0;
  do {
    if (perm.at(0) != 0) break;
    bool is_exist = true;
    for (ll i = 1; i<n; i++) {
      if (nodes.at(perm.at(i-1)).find(perm.at(i)) == nodes.at(perm.at(i-1)).end()) is_exist = false;
    }
    if (is_exist) ans++;
  } while(next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;
  return 0;
}
