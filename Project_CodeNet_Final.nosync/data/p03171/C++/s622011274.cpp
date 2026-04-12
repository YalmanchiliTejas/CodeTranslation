#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

ll dp[3030][3030][2];

ll dfs(const vector<ll>& a, int l, int r, bool is_first) {
    // [l,r)
    if (l == r) return 0;
    if (dp[l][r][is_first] > -INF) {
        return dp[l][r][is_first];
    }
    if (is_first) {
        ll left_score = a[l] + dfs(a, l + 1, r, false);
        ll right_score = a[r - 1] + dfs(a, l, r - 1, false);
        return dp[l][r][is_first] = max(left_score, right_score);
    }
    else {
        ll left_score = dfs(a, l + 1, r, true) - a[l];
        ll right_score = dfs(a, l, r - 1, true) - a[r - 1];
        return dp[l][r][is_first] = min(left_score, right_score);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N + 1) rep(j, 0, N + 1) {
        dp[i][j][0] = dp[i][j][1] = -INF;
    }
    cout << dfs(A, 0, N, true) << endl;
    return 0;
}