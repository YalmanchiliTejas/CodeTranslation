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
template<typename T> ostream& operator<<(ostream& os, const vector<string>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
struct yes_no : std::numpunct<char> { string_type do_truename() const { return "Yes"; } string_type do_falsename() const { return "No"; } };
void solve(); int main() {
  ios::sync_with_stdio(false); cin.tie(0); locale loc(locale(), new yes_no); cout.imbue(loc); cout << fixed << setprecision(10) << boolalpha;
  solve();
}
// ^^^^^^^^^^^^ TEMPLATE ^^^^^^^^^^^^

void solve() {
  ll n; cin >> n;
  vector<ll> a(n); cin >> a;
  sort(all(a));
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  map<ll, ll> m;
  rep(i, n) m[a[i]] = i;
  rep(i, n) rep(j, i) {
    dp[j][i] = 2;
  }
  rep(i, n) rep(j, n) {
    if (dp[i][j] == 0) continue;
    // cout << i << " " << j << " " << dp[i][j] << endl;
    if (m.count(a[j] + a[j]-a[i]) > 0) {
      ll nj = m[a[j] + a[j]-a[i]];
      chmax(dp[j][nj], dp[i][j]+1);
    }
  }
  ll ans = 1;
  rep(i, n) rep(j, n) {
    chmax(ans, dp[i][j]);
  }
  cout << ans << endl;
}

