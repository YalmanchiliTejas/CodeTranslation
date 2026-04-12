#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n;
    cin >> n;
    int to_add = 0;
    VVI dp(n+2, VI(n+2, -1));
    int a1, a2;
    cin >> a1 >> a2;
    if (a1 > a2) swap(a1, a2);
    dp[0][0] = 0;
    dp[0][a1] = 0;
    dp[0][a2] = 0;
    dp[a1][a2] = 0;
    rep(i, n) {
        int x, y, z;
        if (i == n-1) {
            cin >> x;
            y = z = n+1;
        } else {
            cin >> x >> y >> z;
        }
        if (y < x) swap(x, y);
        if (z < x) swap(x, z);
        if (z < y) swap(y, z);
        if (x == y && y == z) {
            to_add += 1;
            continue;
        }
        vector<tuple<int, int, int>> to_update;
        if (x == y) {
            // [*][x] -> [*][0] / [*][z]
            rep(w, n+1) {
                int s = min(x, w), t = max(x, w);
                if (dp[s][t] < 0) continue;
                int nsc = dp[s][t] + 1;
                to_update.emplace_back(w, 0, nsc);
                to_update.emplace_back(w, z, nsc);
            }
        }
        if (y == z) {
            rep(w, n+1) {
                int s = min(y, w), t = max(y, w);
                if (dp[s][t] < 0) continue;
                int nsc = dp[s][t] + 1;
                to_update.emplace_back(w, 0, nsc);
                to_update.emplace_back(w, x, nsc);
            }
        }
        for(auto p: {tuple<int, int, int>{x, y, z}, {y, z, x}, {z, x, y}}) {
            int s, t, u;
            tie(s, t, u) = p;
            // [s][s] -> [0][0] / [0][t] / [0][u] / [t][u]
            if (dp[s][s] < 0) continue;
            int nsc = dp[s][s] + 1;
            to_update.emplace_back(0, 0, nsc);
            to_update.emplace_back(t, 0, nsc);
            to_update.emplace_back(u, 0, nsc);
            to_update.emplace_back(t, u, nsc);
        }
        for(int s: {x, y, z}) {
            // [0][*] -> [x][*]
            rep(w, n+1) {
                if (dp[0][w] < 0) continue;
                to_update.emplace_back(s, w, dp[0][w]);
            }
        }
        if (dp[0][0] >= 0) for(auto p: {P{x, y}, {y, z}, {z, x}}) {
            // [0][0] -> [x][y]
            int s, t;
            tie(s, t) = p;
            to_update.emplace_back(s, t, dp[0][0]);
        }
        for(auto p: to_update) {
            int s, t, score;
            tie(s, t, score) = p;
            if (s > t) swap(s, t);
            chmax(dp[s][t], score);
        }
    }
    int ans = 0;
    rep(i, n+1) rep(j, n+1) chmax(ans, dp[i][j]);
    ans += to_add;
    cout << ans << endl;
}
