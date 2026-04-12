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

using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;

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

    ll n = inp1;
    vector<ll> a = inp(n);

    ll num = n / 2;

    if (n % 2 == 0) {

        // ここが違うんかい！

        // 間に合計1つ以下の空白を入れる

        // どこにいれるかを全探索 O(n^2)

        // iまでにj個空白を入れるdp
        vector<vector<ll>> dp(n + 2, vector<ll>(2, -infll));

        dp[0][0] = 0LL;

        Rep(i, 2, n + 2) {
            rep(j, 2) {
                // 空白を1つ入れる場合
                if (j == 0 && i - 3 >= 0) {
                    if (dp[i - 3][j] != -infll)
                        chmax(dp[i][j + 1], dp[i - 3][j] + a[i - 2]);
                }

                // 空白を入れない場合
                if (dp[i - 2][j] != -infll)
                    chmax(dp[i][j], dp[i - 2][j] + a[i - 2]);
            }
        }

        ll ans = -infll;

        // 終着点は決まってる
        ans = max({ dp[n][0], dp[n + 1][1] });

        Cout(ans);
    }
    else {
        // 間に合計2つ以下の空白を入れる

        // どこにいれるかを全探索 O(n^2)

        // iまでにj個空白を入れるdp
        vector<vector<ll>> dp(n + 2, vector<ll>(3, -infll));

        dp[0][0] = 0LL;

        Rep(i, 2, n + 2) {
            rep(j, 3) {
                // 空白を1つ入れる場合
                if (j <= 1 && i - 3 >= 0) {
                    if(dp[i - 3][j] != -infll)
                        chmax(dp[i][j + 1], dp[i - 3][j] + a[i - 2]);
                }
                // 空白を２つ入れる場合
                if (j == 0 && i - 4 >= 0) {
                    if (dp[i - 4][j] != -infll)
                        chmax(dp[i][j + 2], dp[i - 4][j] + a[i - 2]);
                }
                // 空白を入れない場合
                if (dp[i - 2][j] != -infll)
                    chmax(dp[i][j], dp[i - 2][j] + a[i - 2]);
            }
        }

        ll ans = -infll;

        // 終着点は決まってる
        ans = max({dp[n - 1][0], dp[n][1], dp[n + 1][2]});

        Cout(ans);
    }

    // E解けたらこれも解けてたなぁ もったいない
    // けどDPに抵抗感がなくなってきた？
    // WAでした　雑魚でごめんなさい

    return 0;
}
