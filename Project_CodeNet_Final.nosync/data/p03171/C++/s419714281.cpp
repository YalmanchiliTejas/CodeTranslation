#include <bits/stdc++.h>
using namespace std;
#define rep2(i,m,n) for (int i = (m); i < (n); ++i)
#define rep(i,n) rep2(i,0,n)
#define debug(x) cerr << x << endl
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
    int n;
    cin >> n;
    V<ll> a(n);
    rep(i,n) cin >> a[i];

    auto dp = make_vec(n+1, n+1, 2, 0LL);
    auto rec = [&](auto self, int l, int r, bool is_first) -> ll
    {
        if(abs(r - l) < 1)
        {
            return 0;
        }
        if(dp[l][r][is_first])
        {
            return dp[l][r][is_first];
        }
        if(is_first) //先手番
        {
            ll res = -LINF;
            chmax(res, self(self, l+1, r, 0) + a[l]);
            chmax(res, self(self, l, r-1, 0) + a[r-1]);
            chmax(dp[l][r][is_first], res);
            return res;
        }
        else
        {
            ll res = LINF;
            chmin(res, self(self, l+1, r, 1) - a[l]);
            chmin(res, self(self, l, r-1, 1) - a[r-1]);
            chmin(dp[l][r][is_first], res);
            return res;
        }
    };
    cout << rec(rec, 0, n, 1) << endl;


    return 0;
}