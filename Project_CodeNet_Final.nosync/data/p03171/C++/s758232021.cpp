#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

ll a[3000];
ll dp[3000][3000];

ll dfs(int left, int right, int turn) {
    if (dp[left][right] != -1) {
        return dp[left][right];
    }
    if (left == right) {
        return dp[left][right] = turn == 0 ? a[left] : -a[left];
    }
    if (turn == 0) {
        ll ret = -INF;
        chmax(ret, dfs(left + 1, right, 1) + a[left]);
        chmax(ret, dfs(left, right - 1, 1) + a[right]);
        return dp[left][right] = ret;
    } else {
        ll ret = INF;
        chmin(ret, dfs(left + 1, right, 0) - a[left]);
        chmin(ret, dfs(left, right - 1, 0) - a[right]);
        return dp[left][right] = ret;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 3000; ++i) {
        for (int j = 0; j < 3000; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, n - 1, 0) << "\n";
    return 0;
}