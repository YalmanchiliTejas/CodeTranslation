#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
vector<vector<bool>> Graph(10, vector<bool>(10, false));

int dp[(1 << 10) + 1][10];
int rec(int bit, int v) {
    if (dp[bit][v] != -1) return dp[bit][v];

    if (bit == (1 << v)) {
        if (v == 0)
            return dp[bit][v] = 1;
        else
            return dp[bit][v] = 0;
    }

    int res = 0;

    int prev_bit = bit & ~(1 << v);

    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1 << u))) continue;
        if (!Graph[u][v]) continue;
        res += rec(prev_bit, u);
    }

    return dp[bit][v] = res;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        Graph[a][b] = true;
        Graph[b][a] = true;
    }

    for (int bit = 0; bit < (1 << N); ++bit) {
        for (int v = 0; v < N; ++v) {
            dp[bit][v] = -1;
        }
    }

    ll ans = 0;
    rep(i, N) ans += rec((1 << N) - 1, i);

    cout << ans << endl;
}