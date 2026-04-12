#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ll x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

// http://www.prefield.com/algorithm/dp/lis_fast.html
const ll inf = 999999999999;
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
ll lis_fast(vector<ll>& a) {
  const ll n = a.size();
  vector<ll> A(n, inf);
  vector<ll> id(n, -1);
  for (ll i = 0; i < n; ++i) {
      if(a[i] != inf){
        id[i] = index_of(A, a[i]);
        A[ id[i] ] = a[i];
      }
  }
  dump(id);
  ll m = *max_element(id.begin(), id.end());
  if(m == -1) return 0;
  vector<ll> b(m+1);
  ll cnt = 0;
  for (ll i = n-1; i >= 0; --i)
    if (id[i] == m) {
        b[m--] = a[i];
        a[i] = inf;
        cnt++;
    }
    dump(cnt);
  return cnt;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    rep(i, n){
        cin >> a[i];
        b[i] = INF-a[i];
    }
    ll ans = 0;
    /*
    while(lis_fast(a) > 0){
        dump(a);
        ans++;
    }
    */
    multiset<ll> ms;
    rep(i, n){
        ms.insert(b[i]);
        auto it = ms.upper_bound(b[i]);
        if(it != ms.end()){
            ms.erase(it);
        }
    }
    cout << SZ(ms) << endl;
    return 0;
}