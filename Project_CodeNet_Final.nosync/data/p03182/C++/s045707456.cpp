#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

struct LzyST {
    ll n;
    vll data, lazy;
    
    LzyST(ll m, ll init_value=0){
        n = 1;
        while(n < m) n <<= 1;
        data.assign(2*n-1, init_value);
        lazy.assign(2*n-1, 0);
    }

    void eval(ll k, ll kl, ll kr){
        if(lazy[k] == 0) return;
        data[k] += lazy[k];
        if(kr - kl > 1){
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    // [s,t)
    void update(ll s, ll t, ll x, ll k, ll kl, ll kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return;
        if(s <= kl && kr <= t){
            lazy[k] += x;
            eval(k, kl, kr);
            return;
        }
        ll kc = (kl+kr)/2;
        update(s, t, x, 2*k+1, kl, kc);
        update(s, t, x, 2*k+2, kc, kr);
        data[k] = max(data[2*k+1], data[2*k+2]);
    }

    void update(ll s, ll t, ll x) {
        update(s, t, x, 0, 0, n);
    }

    // [s,t)
    ll query(ll s, ll t, ll k, ll kl, ll kr){
        eval(k, kl, kr);
        if(kr <= s || t <= kl) return 0;
        if(s <= kl && kr <= t) return data[k];
        ll kc = (kl+kr)/2;
        ll vl = query(s, t, 2*k+1, kl, kc);
        ll vr = query(s, t, 2*k+2, kc, kr);
        return max(vl, vr);
    }

    ll query(ll s, ll t) {
        return query(s, t, 0, 0, n);
    }
};

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, m;
  cin >> n >> m;

  vvP itvls(n+1);
  rep(i, m){
    ll l, r, a;
    cin >> l >> r >> a;
    itvls[r].emplace_back(l, a);
  }

  LzyST dp(n+2);
  rep(i, n){
    ll now = dp.query(0, i+1);
    dp.update(i+1, i+2, now);
    for(P p : itvls[i+1]){
        ll l, a;
        tie(l, a) = p;
        dp.update(l, i+2, a);
    }
  }

  cout << dp.query(0, n+1) << endl;

  return 0;
}
