#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <tuple>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;
using ll = long long int;
using P = pair<int, int>;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...) do{ } while(false)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template<typename T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }
template<typename T> void print(T a) { cout << a << endl; }
template<typename T, typename... Ts> void print(T a, Ts... ts) { cout << a << ' '; print(ts...); }
template<typename T> istream &operator,(istream &in, T &t) { return in >> t; }
// clang-format on

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin, n;
    vector<ll> a(n);
    REP(i, 0, n) {
        cin, a[i];
    }
    const ll inf = 1LL << 60;
    ll ans = -inf;
    if (n % 2 == 0) {
        vector<ll> dp(n, -inf);
        dp[0] = a[0];
        dp[1] = a[1];
        REP(i, 2, n) {
            chmax(dp[i], dp[i - 2] + a[i]);
            if (i % 2) {
                chmax(dp[i], dp[i - 3] + a[i]);
            }
        }
        ans = max(dp[n - 1], dp[n - 2]);
    } else {
        if (n == 3) {
            ans = max({a[0], a[1], a[2]});
        } else {
            vector<ll> dp1(n, -inf), dp2(n, -inf);
            dp1[0] = a[0];
            dp1[1] = a[1];
            REP(i, 2, n) {
                chmax(dp1[i], dp1[i - 2] + a[i]);
                if (i % 2) {
                    chmax(dp1[i], dp1[i - 3] + a[i]);
                }
            }
            dp2[n - 1] = a[n - 1];
            dp2[n - 2] = a[n - 2];
            for (int i = n - 3; i >= 0; i--) {
                chmax(dp2[i], dp2[i + 2] + a[i]);
                if (i % 2) {
                    chmax(dp2[i], dp2[i + 3] + a[i]);
                }
            }
            for (int i = 1; i < n; i += 2) {
                if (i > 1 && i < n - 2) {
                    chmax(ans, a[i - 1] + dp1[i - 3] + dp2[i + 2]);
                    chmax(ans, a[i - 1] + dp1[i - 3] + dp2[i + 3]);
                    chmax(ans, a[i] + dp1[i - 3] + dp2[i + 2]);
                    chmax(ans, a[i] + dp1[i - 3] + dp2[i + 3]);
                    chmax(ans, a[i] + dp1[i - 2] + dp2[i + 2]);
                    chmax(ans, a[i] + dp1[i - 2] + dp2[i + 3]);
                    chmax(ans, a[i + 1] + dp1[i - 2] + dp2[i + 3]);
                    chmax(ans, a[i + 1] + dp1[i - 3] + dp2[i + 3]);
                }
                if (i == n - 2) {
                    chmax(ans, a[i - 1] + dp1[i - 3]);
                    chmax(ans, a[i] + dp1[i - 3]);
                    chmax(ans, a[i] + dp1[i - 2]);
                    chmax(ans, a[i + 1] + dp1[i - 2]);
                    chmax(ans, a[i + 1] + dp1[i - 3]);
                }
                if (i == 1) {
                    chmax(ans, a[i - 1] + dp2[i + 2]);
                    chmax(ans, a[i - 1] + dp2[i + 3]);
                    chmax(ans, a[i] + dp2[i + 2]);
                    chmax(ans, a[i] + dp2[i + 3]);
                    chmax(ans, a[i + 1] + dp2[i + 3]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
