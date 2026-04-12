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
    ll N, X, M;
    cin >> N >> X >> M;
    vector<int> f(M, -1);
    vector<vector<ll>> s(40, vector<ll>(M));
    auto func = [&](ll x)
    {
        return (x * x) % M;
    };
    int cur = X;
    rep(i,M)
    {
        if(~f[cur]) break;
        s[0][cur] = cur;
        f[cur] = func(cur);
        cur = f[cur];
    }
    vector<vector<int>> d(40, vector<int>(M, -1));
    d[0] = f;
    // iota(s[0].begin(), s[0].end(), 0LL);
    rep(i,39)
    {
        rep(j,M)
        {
            d[i+1][j] = d[i][d[i][j]];
            s[i+1][j] = s[i][j] + s[i][d[i][j]];
        }
    }
    int pos = X;
    ll ans = 0;
    rep(i,40)
    {
        if((N >> i) & 1)
        {
            ans += s[i][pos];
            pos = d[i][pos];
        }
    }
    cout << ans << endl;

    return 0;
}
