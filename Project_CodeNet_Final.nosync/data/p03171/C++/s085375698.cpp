#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool abs_chmin(ll &a, ll &b) {
    if (abs(a) > abs(b)) {
        b = a;
        return 1;
    };
    return 0;
}
bool abs_chmax(ll &a, ll &b) {
    if (abs(a) < abs(b)) {
        b = a;
        return 1;
    };
    return 0;
}

int N, K;
ll dp[3005][3005];
int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N;
    vector<int> A(N + 1);
    REP(i, N) cin >> A.at(i + 1);

    FOR(s, 2, N + 2) {
        FOR(j, s, N + 2) {
            int i = j - s + 1;
            if ((N - (j - i)) % 2 == 0) {  // 太郎
                dp[i][j] = max(dp[i][j - 1] + A[j - 1], dp[i + 1][j] + A[i]);
            } else {  // 次郎
                dp[i][j] = min(dp[i][j - 1] - A[j - 1], dp[i + 1][j] - A[i]);
            }
        }
    }

    cout << dp[1][N + 1] << endl;

    return 0;
}
