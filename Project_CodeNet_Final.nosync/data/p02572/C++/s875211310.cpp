#include <bits/stdc++.h>
using namespace std;
#define rep2(i,m,n) for (int i = (m); i < (n); ++i)
#define rep(i,n) rep2(i,0,n)
#define debug(x) cout << x << endl
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> P;
template<typename T> struct V : vector<T> { using vector<T>::vector; };
V() -> V<int>;
V(size_t) -> V<int>;
template<typename T> V(size_t, T) -> V<T>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1<<30;
const ll LINF = 1LL<<61;
const ll MOD = 1000000007;

int main()
{
    ll n;
    cin >> n;
    V<ll> a(n), as(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1) as[i+1] = a[i];
    rep(i,n-1) as[i+1] += as[i];
    rep(i,n) as[i] %= MOD;
    // cout << as << endl;
    ll ans = 0;
    rep(i,n)
    {
        ans += (a[i] * as[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}