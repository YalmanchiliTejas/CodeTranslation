// vvvvvvvvvvvv TEMPLATE vvvvvvvvvvvv
#include <bits/stdc++.h>
using namespace std; using ll = long long; using P = pair<ll, ll>;
const ll linf = 1e18; const double eps = 1e-12, pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define each(i,a) for (auto&& i : a)
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x < y ? y : x)
template<typename Head> void out(Head h) { cout << h << endl; } template<typename Head, typename... Tail>void out(Head h, Tail... t) { cout << h << " "; out(t...); }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { each(x,v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i,v.size()) { if (i) os << " "; os << v[i]; } return os; }
ostream& operator<<(ostream& os, const vector<string>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
struct yes_no : std::numpunct<char> { string_type do_truename() const { return "Yes"; } string_type do_falsename() const { return "No"; } };
void solve(); int main() {
  ios::sync_with_stdio(false); cin.tie(0); locale loc(locale(), new yes_no); cout.imbue(loc); cout << fixed << setprecision(10) << boolalpha;
  solve();
}
// ^^^^^^^^^^^^ TEMPLATE ^^^^^^^^^^^^

class StarrySkyTree {
private:
  ll base;
  vector<ll> s;
  vector<ll> mn;
  void update_mn(ll n) {
    if (n == 0) return;
    mn[n] = min(get_min(n*2), get_min(n*2+1));
  }
  void add(ll l, ll r, ll n, ll L, ll R, ll val) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
      s[n] += val;
      return;
    }
    ll m = (l + r) / 2;
    add(l, m, n*2, L, R, val);
    add(m, r, n*2+1, L, R, val);
    mn[n] = min(get_min(n*2), get_min(n*2+1));
  }
  ll get_min(ll n) {
    return min(linf, mn[n] + s[n]);
  }
  ll get_min(ll l, ll r, ll n, ll L, ll R) {
    if (r <= L || R <= l) return linf;
    if (L <= l && r <= R) return get_min(n);
    ll m = (l + r) / 2;
    ll res = min(get_min(l, m, n*2, L, R), get_min(m, r, n*2+1, L, R));
    return min(linf, res+s[n]);
  }
  void get_min_pos(ll l, ll r, ll n, ll L, ll R, ll sum, vector<ll>& res) {
    if (r <= L || R <= l) return;
    if (mn[n] + s[n] + sum > 0) return;
    assert(l < r);
    if (r - l == 1) {
      res.pb(n-base);
    }
    else {
      ll m = (l + r) / 2;
      get_min_pos(l, m, n*2, L, R, sum+s[n], res);
      get_min_pos(m, r, n*2+1, L, R, sum+s[n], res);
    }
  }
public:
  StarrySkyTree(ll n) {
    for (base = 1; base < n; base <<= 1);
    s = vector<ll>(base*2, 0);
    mn = vector<ll>(base*2, 0);
  }
  void add(ll l, ll r, ll val) {
    add(0, base, 1, l, r, val);
  }
  ll get_min(ll l, ll r) {
    assert(0 <= l && l < r && r <= base);
    return get_min(0, base, 1, l, r);
  }
  vector<ll> get_min_pos(ll l, ll r) {
    ll min_value = get_min(l, r);
    vector<ll> res;
    get_min_pos(0, base, 1, l, r, -min_value, res);
    return res;
  }
};

void solve() {
  ll n, m; cin >> n >> m;
  vector<ll> l(m), r(m), a(m);
  rep(i, m) {
    cin >> l[i] >> r[i] >> a[i]; --l[i];
    a[i] *= -1;
  }
  vector<ll> S(n+1, 0);
  rep(i, m) S[l[i]] += a[i];
  rep(i, n) S[i+1] += S[i];
  vector<vector<ll>> evl(n+1);
  vector<vector<ll>> evr(n+1);
  rep(i, m) evl[l[i]].pb(i);
  rep(i, m) evr[r[i]].pb(i);
  StarrySkyTree sst(n+1);
  ll ans = 0;
  rep(i, n) {
    each(j, evl[i]) {
      sst.add(0, l[j]+1, a[j]);
    }
    each(j, evr[i]) {
      sst.add(0, l[j]+1, -a[j]);
    }
    ll dp = sst.get_min(0, i+1);
    chmin(ans, dp);
    sst.add(i+1, i+2, dp);
  }
  cout << -ans << endl;
}
