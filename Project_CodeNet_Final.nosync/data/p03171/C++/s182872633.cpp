#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const long long INF = 1e18;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    rep(i, 0, N) cin >> A[i];
    vector<vector<long long>> memo(N, vector<long long>(N, INF));
    function<long long(int, int)> dp = [&](int l, int r) {
        if(memo[l][r] != INF) return memo[l][r];
        if(l == r) return memo[l][r] = A[l];
        return memo[l][r] = max(A[l] - dp(l + 1, r), A[r] - dp(l, r - 1));
    };
    cout << dp(0, N - 1) << '\n';
    return 0;
}
