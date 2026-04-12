#include "bits/stdc++.h"
using namespace std;
typedef int li;

const li inf = 1 << 29;

li dp[2000][2000];
li dp_maxx[2000];
li dp_maxy[2000];
li dp_max = -inf;

void update(const li x, const li y, const li v) {
    dp[x][y] = max(dp[x][y], v);
    dp_maxx[y] = max(dp_maxx[y], v);
    dp_maxy[x] = max(dp_maxy[x], v);
    dp_max = max(dp_max, v);
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;
    vector<li> xs(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> xs[i];
        xs[i]--;
    }

    for (int i = 0; i < n; ++i) {
        dp_maxx[i] = -inf;
        dp_maxy[i] = -inf;
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -inf;
        }
    }

    update(xs[0], xs[1], 0);

    li offset = 0;
    for (int itr = 0; itr < n - 1; ++itr) {
        const li p = xs[2 + itr * 3];
        const li q = xs[2 + itr * 3 + 1];
        const li r = xs[2 + itr * 3 + 2];

        // add, use 3
        if (p == q && q == r) {
            offset++;
            continue;
        }

        vector<tuple<li, li, li>> updates;

        // add, use 2
        if (p == q || q == r || p == r) {
            li pair, rem;
            if (p == q) {
                pair = p;
                rem = r;
            } else if (q == r) {
                pair = q;
                rem = p;
            } else {
                pair = r;
                rem = q;
            }
            for (int k = 0; k < n; ++k) {
                updates.emplace_back(k, rem, dp[k][pair] + 1);
                updates.emplace_back(k, rem, dp[pair][k] + 1);
            }
        }

        // add, use 1
        updates.emplace_back(q, r, dp[p][p] + 1);
        updates.emplace_back(p, r, dp[q][q] + 1);
        updates.emplace_back(p, q, dp[r][r] + 1);

        // no-add, use 3
        // reusing the dp table to avoid O(n^2) updates.

        // no-add, use 2
        for (int k = 0; k < n; ++k) {
            updates.emplace_back(k, p, dp_maxx[k]);
            updates.emplace_back(k, p, dp_maxy[k]);
            updates.emplace_back(k, q, dp_maxx[k]);
            updates.emplace_back(k, q, dp_maxy[k]);
            updates.emplace_back(k, r, dp_maxx[k]);
            updates.emplace_back(k, r, dp_maxy[k]);
        }

        // no-add, use 1
        updates.emplace_back(p, q, dp_max);
        updates.emplace_back(p, r, dp_max);
        updates.emplace_back(q, r, dp_max);

        for (auto &upd: updates) {
            update(get<0>(upd), get<1>(upd), get<2>(upd));
        }
    }

    li ans = dp_max;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (x == y && y == xs[3 * n - 1]) {
                ans = max(ans, dp[x][y] + 1);
            }
        }
    }

    cout << ans + offset << endl;
    return 0;
}