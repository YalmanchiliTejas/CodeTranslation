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
    int s = 1+n%2;

    //3つまで飛ばして選べる
    //dp[i][j][k] := i-1番目までを見て、スキップをj回使い、直前の要素を使ったときの最大値
    auto dp = make_vec(n+1, s+1, 2, -LINF);
    dp[0][0][0] = 0;
    rep(i,n) rep(j,s+1)
    {
        int ni = i+1;
        
        //直前の要素をとった
        chmax(dp[ni][j][0], dp[i][j][1]);
        //a[i]をとる
        chmax(dp[ni][j][1], dp[i][j][0] + a[i]);
        //バックレ
        if(j < s) chmax(dp[ni][j+1][0], dp[i][j][0]);
    }
    ll ans = -LINF;
    if(n%2==1) rep2(i,1,s+1) rep(j,2) chmax(ans, dp[n][i][j]);
    else rep(i,s+1) rep(j,2) chmax(ans, dp[n][i][j]);
    cout << ans << endl;
    return 0;
}