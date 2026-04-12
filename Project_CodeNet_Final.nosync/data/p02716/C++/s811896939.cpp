#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ll dp[200010][4];

void solve() {
    ll N;
    cin >> N;
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    fill_n(&dp[0][0], sizeof(dp) / sizeof(dp[0][0]), -L_INF);

    dp[0][0] = 0;
    dp[1][0] = A[0];

    ll lm;
    if (N & 1)
        lm = 2;
    else
        lm = 1;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j <= lm; j++) {
            for (ll k = 0; k <= 2; k++) {
                if (i - (2 + k) >= 0 && j - k >= 0 && dp[i - (2 + k)][j - k] != -L_INF) {
                    dp[i][j] = max(dp[i][j], dp[i - (2 + k)][j - k] + A[i - 1]);
                }
            }
        }
    }

    ll ans = -L_INF;
    if (N & 1) {
        ans = max(ans, dp[N - 2][0]);
        ans = max(ans, dp[N - 1][0]);
        ans = max(ans, dp[N - 1][1]);
        ans = max(ans, dp[N][1]);
        ans = max(ans, dp[N][2]);
    }
    else {
        ans = max(ans, dp[N - 1][0]);
        ans = max(ans, dp[N][0]);
        ans = max(ans, dp[N][1]);
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}