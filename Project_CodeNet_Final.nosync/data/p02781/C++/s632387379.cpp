#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<vector<int>>> dp(127, vector<vector<int>>(2, vector<int>(8, 0)));
/// dp[digit][isSmall][num of K]

int main() {
    string N;
    int K;
    cin >> N >> K;

    dp[0][0][0] = 1;

    const int L = N.size();
    rep(i, L) {
        const int D = N.at(i) - '0';
        rep(j, 2) {
            rep(k, K + 1) {
                for(int d = 0; d <= (j ? 9 : D); ++d) {
                    dp[i + 1][j || (d < D)][k + (d != 0)] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[L][0][K] + dp[L][1][K] << endl;
}
