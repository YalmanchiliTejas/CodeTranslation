#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int dp[1<<16];
int G[101][101];

string bin_str(int l, int x) {
    string ret(l, '0');
    for (int i = 0; i < l; i++) {
        ret[l - 1 - i] = '0' + (x % 2);
        x /= 2;
    }
    return ret;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        d[i]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> G[i][j];
            G[i][j]--;
        }
    }
    for (int bit = 0; bit < (1<<m); bit++) {
        dp[bit] = inf;
    }
    dp[(1<<m) - 1] = 0;
    queue<int> q;
    q.push((1<<m) - 1);
    while (not q.empty()) {
        int bit = q.front();
        q.pop();
        for (int i = 0; i < k; i++) {
            int nxt = 0;
            for (int j = 0; j < m; j++) {
                if (bit & (1<<j)) {
                    int to = G[d[j]][i];
                    for (int l = 0; l < m; l++) {
                        if (to == d[l]) {
                            nxt |= 1<<l;
                            break;
                        }
                    }
                }
            }
            // cout << bin_str(m, bit) << " " << bin_str(m, nxt) << endl;
            // cout << dp[bit] << " " << dp[nxt] << endl;
            
            if (dp[bit] + 1 < dp[nxt]) {
                // if (nxt == 65520 or nxt == 65280 or nxt == 61440 or nxt == 0) {
                //     dump(i);
                //     cout << bin_str(m, bit) << " " << bin_str(m, nxt) << endl;
                //     cout << bit << " " << nxt << endl;
                //     cout << dp[bit] << " " << dp[nxt] << endl;
                // }
                dp[nxt] = dp[bit] + 1;
                q.push(nxt);
            }
        }
    }
    // for (int i = 0; i < m; i++) {
    //     cout << d[i] << " " << G[d[i]][0] <<  " " << G[d[i]][80] << " " << G[d[i]][81] << endl;
    //     for (int j = 0; j < k; j++) {
    //         cout << G[d[i]][j] << " ";
    //     } cout << endl;
    // }
    for (int bit = (1<<m) - 1; bit >= 0; bit--) {
        //cout << bin_str(m, bit) << " " << dp[bit] << endl;
    }
    dump(dp[0]);
    return 0;
}

