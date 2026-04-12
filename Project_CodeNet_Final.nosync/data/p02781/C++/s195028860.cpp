#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 2147483647;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = sz(s);
    auto dp0 = make_vec<ll>(110, 4);
    auto dp1 = make_vec<ll>(110, 4);
    dp0[0][0] = 1;
    rep(i, n) {
        rep(j, 4) {
            for (char d = '1'; d <= '9'; d++) {
                if (d < s[i]) {
                    dp1[i + 1][j + 1] += dp0[i][j];
                    dp1[i + 1][j + 1] += dp1[i][j];
                }
                if (d == s[i]) {
                    dp0[i + 1][j + 1] += dp0[i][j];
                    dp1[i + 1][j + 1] += dp1[i][j];
                }
                if (d > s[i]) {
                    dp1[i + 1][j + 1] += dp1[i][j];
                }
            }

            if ('0' == s[i]) {
                dp0[i + 1][j] += dp0[i][j];
                dp1[i + 1][j] += dp1[i][j];
            } else {
                dp1[i + 1][j] += dp0[i][j];
                dp1[i + 1][j] += dp1[i][j];
            }
        }
    }
    cout << dp0[n][k] + dp1[n][k] << endl;
}