#include <bits/stdc++.h>
using namespace std;
#define rep2(i,m,n) for (int i = (m); i < (n); ++i)
#define rep(i,n) rep2(i,0,n)
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> P;
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
const int INF = 1e9;
const ll LINF = 1LL<<61;
const ll MOD = 1000000007;

int main()
{
    string s;
    int n, d;
    cin >> s >> d;
    n = s.size();
    auto dp = make_vec(d, 2, 0LL); //dp[j][k] : (i文字目まで見た時の)dで割ったあまりがjでSより小さいことが確定している数
    dp[0][0] = 1;
    rep(i,n)
    {
        // cout << dp << endl;
        auto dp2 = make_vec(d,2,0LL);
        int c = s[i] - '0';
        rep(j,d) rep(k,2)
        {
            rep(l,10)
            {
                int nk = k;
                if(k == 0 && l < c) nk = 1;
                if(k == 0 && l > c) continue;
                int nj = (j + l) % d;
                dp2[nj][nk] += dp[j][k];
                dp2[nj][nk] %= MOD;
            }
        }
        swap(dp, dp2);
    }
    cout << (MOD + dp[0][0] + dp[0][1] - 1) % MOD << endl;

    return 0;
}
