#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 8;
vector<int> e[N];
int n, m, f, t, ans;
int dp[1 << N][N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> t;
        e[f - 1].push_back(t - 1);
        e[t - 1].push_back(f - 1);
    }
    dp[1][0] = 1;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] != 0) {
                for (int k : e[j]) {
                    if (!(i & (1 << k))) {
                        dp[i ^ (1 << k)][k] += dp[i][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += dp[(1 << n) - 1][i];
    }
    cout << ans << endl;
    return 0;
}
