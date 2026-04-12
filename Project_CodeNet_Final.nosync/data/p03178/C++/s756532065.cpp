#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define REP2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define rep(i, n) REP(i, 0, n)
#define rep2(i, n) REP2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> inline void print(T x) { cout << x << '\n'; }
template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// v ector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(k+1, 0)));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    ll d;
    cin >> s >> d;
    ll n = s.size();
    vvvl dp(n+1,vvl(d+1,vl(2,0)));
    //0:s以下であることが確定。1:sより大きいことが未確定
    dp[0][0][0] = 1;
    rep(i,n) {
        rep(j,d) {
            rep(k,2) {
                rep(l,10) {
                    ll ns = s[i]-'0';
                    ll nk = k;
                    if (ns < l && !k) continue;
                    if (ns > l) nk = 1;
                    dp[i+1][(j+l)%d][nk] += dp[i][j][k];
                    dp[i+1][(j+l)%d][nk] %= MOD;
                }
            }

        }
    }
    print((dp[n][0][0]+dp[n][0][1]+MOD-1)%MOD);

    return 0;
}
