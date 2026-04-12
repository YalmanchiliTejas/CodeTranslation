#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    string N;
    int K;
    cin >> N >> K;
    int n = (int)N.size();
    auto dp = make_vec<ll>(2, K + 1, n + 1);
    dp[true][0][0] = 1;
    /* for (int i = 1; i < n + 1; i++) {
        dp[false][0][i] = 1;
    }*/

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= K; k++) {
            if (N[i] != '0') {
                dp[false][k][i + 1] += dp[true][k][i];  // 0 になる
                if (k != K) {
                    dp[true][k + 1][i + 1] += dp[true][k][i];                       // ぴったりおなじ
                    dp[false][k + 1][i + 1] += dp[true][k][i] * (int)(N[i] - '1');  // 0でも同じでもない
                }
            } else {
                dp[true][k][i + 1] = dp[true][k][i];  // 0のとき
            }
            if (k != K) dp[false][k + 1][i + 1] += dp[false][k][i] * 9;  // 0以外
            dp[false][k][i + 1] += dp[false][k][i];                      // 0 になる
                                                                         // cout << i << " " << k << " ";
            //debug(dp[false][k][i]);
        }
    }

    //cout << dp[true][K][n] << " " << dp[false][K][n] << " " << dp[false][K][n - 1] << " " << dp[false][K][n - 2] << endl;
    cout << dp[true][K][n] + dp[false][K][n] << endl;
}
