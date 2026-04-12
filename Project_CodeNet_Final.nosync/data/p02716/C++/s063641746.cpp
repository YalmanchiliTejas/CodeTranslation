#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    vector<vector<ll>> dp(N + 1, vector<ll>(3, -LINF));
    // 最後に選んだ要素がA_iであって、パスした回数がj回
    dp[0][0] = A[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    if(N % 2 == 0) {
        dp[1][1] = A[1];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 2; j++) {
                // dp[i][j]からの遷移
                if(i + 2 < N)
                    dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + A[i + 2]);
                if(i + 3 < N && j + 1 < 2)
                    dp[i + 3][j + 1] =
                        max(dp[i + 3][j + 1], dp[i][j] + A[i + 3]);
            }
        }
        cout << max(dp[N - 2][0], dp[N - 1][1]) << endl;
    } else {
        dp[1][1] = A[1];
        dp[2][2] = A[2];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 3; j++) {
                // dp[i][j]からの遷移
                if(i + 2 < N)
                    dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + A[i + 2]);
                if(i + 3 < N && j + 1 < 3)
                    dp[i + 3][j + 1] =
                        max(dp[i + 3][j + 1], dp[i][j] + A[i + 3]);
                if(i + 4 < N && j + 2 < 3)
                    dp[i + 4][j + 2] =
                        max(dp[i + 4][j + 2], dp[i][j] + A[i + 4]);
            }
        }
        cout << max(dp[N - 3][0], max(dp[N - 2][1], dp[N - 1][2])) << endl;
    }

    return 0;
}