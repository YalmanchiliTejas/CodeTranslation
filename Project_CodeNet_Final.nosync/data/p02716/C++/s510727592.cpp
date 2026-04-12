#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

const int64_t INF = 1e16;

template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

int64_t dp[200005][6][2];

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    rep(i, N + 1) rep(j, 6) rep(k, 2) dp[i][j][k] = -INF;
    dp[0][2][0] = 0;
    rep(i, N) rep(j, 6) rep(k, 2) {
        if(!k && j + 1 < 6) chmax(dp[i + 1][j + 1][1], dp[i][j][k] + A[i]);
        if(j - 1 >= 0) chmax(dp[i + 1][j - 1][0], dp[i][j][k]);
    }
    if(N % 2) cout << max(dp[N][1][0], dp[N][1][1]) << '\n';
    else cout << max(dp[N][2][0], dp[N][2][1]) << '\n';
    return 0;
}
