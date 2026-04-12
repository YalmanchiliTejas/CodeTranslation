#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;
typedef long long int ll;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T>
bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false;}
template<typename T>
bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false;}
// clang-format on

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    auto dp = make_v(n + 1, k + 1, 2, 0LL);
    dp[0][0][1] = 1;
    REP(i, 0, n) {
        REP(j, 0, k + 1) {
            REP(t, 0, 2) {
                int mx = (t ? s[i] + 1 : '9' + 1);
                REP(a, '0', mx) {
                    if (a == '0') {
                        dp[i + 1][j][t && a + 1 == mx] += dp[i][j][t];
                    } else {
                        if (j != k) {
                            dp[i + 1][j + 1][t && a + 1 == mx] += dp[i][j][t];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(i, 0, 2) {
        ans += dp[n][k][i];
    }
    cout << ans << endl;

    return 0;
}
