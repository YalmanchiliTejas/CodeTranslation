#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
    template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
    template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
    template<typename T> void chadd(T& a, T b) { a = a + b; }

    void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

    // 標準入出力
    struct inp {
        std::size_t sz;
        inp(std::size_t _sz = 1) : sz(_sz) {}
        template <typename T> operator T () const { T a; std::cin >> a; return a; }
        template <typename T> operator std::vector<T>() const { vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
        template <typename T, typename U> operator std::pair<T, U>() const { T f; U s; std::cin >> f >> s; return std::pair<T, U>(f, s); } 
    };

    inp inp1; // input one
}

int main() {

    string k = inp1;
    ll d = inp1;

    // dp[i][j][f] := i桁目まで見たときに，各桁の総和をDで割った余りがjとなるような場合の数
    // f=1のときは最大値を超えるかもしれない
    vector<vector<vector<ll>>> dp(k.length() + 1, vector<vector<ll>>(d, vector<ll>(2, 0LL)));

    dp[0][0][1] = 1;

    rep(i, k.length()) {
        rep(j, d) {
            // 0~9が入る
            rep(c, 10) {
                int new_j = (j + c) % d;
                int t = k[i] - '0';
                if (c < t) { // 必ず小さくなれる
                    dp[i + 1][new_j][0] += dp[i][j][0] + dp[i][j][1];
                }
                else if (c == t) { // 必ず小さい時ならそのまま，それ以外ならそれ以外
                    dp[i + 1][new_j][0] += dp[i][j][0];
                    dp[i + 1][new_j][1] += dp[i][j][1];
                }
                else {
                    dp[i + 1][new_j][0] += dp[i][j][0];
                }
                dp[i + 1][new_j][0] %= mod;
                dp[i + 1][new_j][1] %= mod;
            }
        }
    }

    //rep(i, k.length() + 1) {
    //    rep(j, d) {
    //        rep(f, 2) {
    //            cout << dp[i][j][f] << " ";
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}

    // 0だけのやつもいる dp[k.length()][0][0]とdp[k.length()][0][1]がどちらも0になってるとき？
    ll ans = (dp[k.length()][0][0] + dp[k.length()][0][1] - 1 + mod) % mod;

    Cout(ans);

    // 実装はやくなりたい

    return 0;
}
