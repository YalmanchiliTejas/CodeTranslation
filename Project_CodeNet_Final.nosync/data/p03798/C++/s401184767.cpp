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

    int n = inp1;
    string s = inp1;

    // 2つ決めたらすべて決まりそう

    // ハイ天才

    // 1で羊 0で狼
    vector<int> ans(n);

    rep(i, 4) {
        ans[0] = i & 1;
        ans[1] = (i & 2) >> 1;

        Rep(k, 1, n - 1) {
            if (s[k] == 'o') {
                if (ans[k] == 1) ans[k + 1] = ans[k - 1];
                else ans[k + 1] = 1 - ans[k - 1];
            }
            else {
                if (ans[k] == 0) ans[k + 1] = ans[k - 1];
                else ans[k + 1] = 1 - ans[k - 1];
            }
        }

        // 最終的に矛盾がないか
        bool ok = true;
        if (s[n - 1] == 'o') {
            if (ans[n - 1] == 1) ok &= ans[n - 2] == ans[0];
            else ok &= ans[n - 2] != ans[0];
        }
        else {
            if (ans[n - 1] == 0) ok &= ans[n - 2] == ans[0];
            else ok &= ans[n - 2] != ans[0];
        }

        if (s[0] == 'o') {
            if (ans[0] == 1) ok &= ans[n - 1] == ans[1];
            else  ok &= ans[n - 1] != ans[1];
        }
        else {
            if (ans[0] == 0) ok &= ans[n - 1] == ans[1];
            else  ok &= ans[n - 1] != ans[1];
        }

        if (ok) break;
        else if (i == 3) {
            Cout(-1);
            return 0;
        }
    }

    rep(i, n) {
        cout << ((ans[i] == 1) ? 'S' : 'W');
    }
    cout << '\n';

    return 0;
}
