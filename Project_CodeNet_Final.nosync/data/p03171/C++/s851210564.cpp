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
        template <typename T> operator std::vector<T>() const { std::vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
    };

    inp inp1; // input one

    ll rec(int left, int right, int n, const vector<ll>& a, vector<vector<ll>>& dp) {
        if (left >= right) return 0LL;
        if (dp[left][right] != infll) return dp[left][right];

        int drop_num = (n - right) + left;

        if (right - left == 1) {
            if (drop_num % 2 == 0) return dp[left][right] = a[left];
            else return dp[left][right] = -a[left];
        }

        // 右か左か
        ll res = 0LL;
        if (drop_num % 2 == 0) { // 最大化
            res = -infll;
            chmax(res, rec(left + 1, right, n, a, dp) + a[left]);
            chmax(res, rec(left, right - 1, n, a, dp) + a[right - 1]);
        }
        else { // 最小化 
            res = infll;
            chmin(res, rec(left + 1, right, n, a, dp) - a[left]);
            chmin(res, rec(left, right - 1, n, a, dp) - a[right - 1]);
        }

        return dp[left][right] = res;
    }
}

int main() {

    int n = inp1;
    vector<ll> a = inp(n);

    // dp[i][j] := 左からi個，右からj個取った時の　最適な X-Y
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, infll));

    Cout(rec(0, n, n, a, dp));

    // この区間DP，あまり見えないなぁ
    // ゲームAIで活用できそう

    // 階層ごとにどっちが選ぶか分けるとわかりやすい？

    return 0;
}
