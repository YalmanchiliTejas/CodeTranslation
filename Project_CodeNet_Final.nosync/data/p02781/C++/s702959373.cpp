#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;
ll K;

// i: 何文字目か
// j; N未満か
// k: 0が何回出て来たか
ll dp[110][2][110];

int main() {
    cin >> S >> K;
    dp[0][0][0] = 1;

    ll N = S.size();

    for (int i = 0; i < N; i++) {
        int D = S[i] - '0';

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                int target = (j == 1 ? 9 : D);

                for (int d = 0; d <= target; d++) {
                    int cnt = 0;
                    if (d != 0) cnt++;

                    dp[i + 1][j || (d < D)][k + cnt] += dp[i][j][k];
                }
            }
        }
    }

    ll ans = 0;
    ans += dp[N][0][K];
    ans += dp[N][1][K];

    cout << ans << endl;
}