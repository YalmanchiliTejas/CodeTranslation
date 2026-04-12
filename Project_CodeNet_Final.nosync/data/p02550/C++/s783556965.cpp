#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int64_t solve() {
    int64_t N, X, M;
    cin >> N >> X >> M;
    int64_t ans = 0;
    map<int64_t, int> mp;
    vector<int64_t> A(M + 1);
    int L = -1;
    rep(i, min(N, M)) {
        A[i] = X;
        if(mp.find(X) != mp.end()) L = i - mp[X];
        mp[X] = i;
        ans += X;
        X = X * X % M;
    }
    if(N <= M || L == -1) return ans;
    N -= M;
    int64_t roop = N / L;
    int64_t move = N % L;
    vector<int64_t> dp(L + 1);
    rep(i, L) dp[i + 1] = A[M - L + i];
    rep(i, L) dp[i + 1] += dp[i];
    ans += dp[L] * roop + dp[move];
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << solve() << '\n';
}
