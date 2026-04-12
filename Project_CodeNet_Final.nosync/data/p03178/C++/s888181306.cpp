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

constexpr ll mod = 1e9+7;
constexpr ll mul(ll a, ll b) { return a * b % mod; }
ll mul(initializer_list<ll> t) { ll res = 1; each(v, t) res = mul(res, v); return res; }
ll add(ll a, ll b) { return (a + b) % mod; }
ll add(initializer_list<ll> t) { ll res = 0; each(v, t) res = add(res, v); return res; }
ll sub(ll a, ll b) { return (a - b + mod) % mod; }
ll sub(initializer_list<ll> t) { auto it = t.begin(); ll res = *(it++); while (it != t.end()) res = sub(res, *(it++)); return res; }
ll inv(ll n); ll power(ll x, ll n) { if (n < 0) return inv(power(x, -n)); ll res = 1; for (ll i = 1; i <= n; i <<= 1) { if (i & n) res = mul(res, x); x = mul(x, x); } return res; }
ll inv(ll n) { return power(n, mod-2); }
ll divi(ll a, ll b) { return mul(a, inv(b)); }
ll divi(initializer_list<ll> t) { auto it = t.begin(); ll res = *(it++); while (it != t.end()) res = divi(res, *(it++)); return res; }
// template<int n> struct Fact { ll fact[n+1]; public: constexpr Fact() : fact() { fact[0] = 1; rep(i, 1, n+1) fact[i] = fact[i-1] * i % mod; } ll operator[](size_t idx) const { return fact[idx]; } };
// const auto fact = Fact<int(300000)>();
// ll comb(ll n, ll r) { if (r < 0) return 0; if (r > n) return 0; return divi(fact[n], mul(fact[r], fact[n-r])); }

using Row = vector<ll>;
using Matrix = vector<Row>;
Matrix E(ll n) { Matrix res(n, Row(n, 0)); rep(i, n) res[i][i] = 1; return res; }
Matrix mul(const Matrix& A, const Matrix& B) { const ll n = A.size(), m = A[0].size(), l = B[0].size(); assert(m == B.size()); Matrix res(n, Row(l, 0)); rep(i, n) rep(j, m) rep(k, l) res[i][k] = add(res[i][k], mul(A[i][j], B[j][k])); return res; }
Row mul(const Matrix& A, const Row& x) { Matrix tx(x.size()); rep(i, x.size()) tx[i] = Row(1, x[i]); tx = mul(A, tx); Row res(x.size()); rep(i, x.size()) res[i] = tx[i][0]; return res; }
Matrix power(Matrix A, ll n) { assert(A.size() == A[0].size()); Matrix res = E(A.size()); for (ll i = 1; i <= n; i <<= 1) { if (i & n) res = mul(res, A); A = mul(A, A); } return res; }

void solve() {
  string s; cin >> s;
  ll D; cin >> D;
  const ll n = s.size();
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(D, 0)));
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 2) rep(k, D) rep(l, 10) {
    if (j == 0 && l > s[i]-'0') continue;
    ll nj = j == 1 || l < s[i]-'0';
    ll nk = (k + l) % D;
    dp[i+1][nj][nk] = add(dp[i+1][nj][nk], dp[i][j][k]);
  }
  ll ans = 0;
  rep(j, 2) ans = add(ans, dp[n][j][0]);
  ans = sub(ans, 1);
  cout << ans << endl;
}
