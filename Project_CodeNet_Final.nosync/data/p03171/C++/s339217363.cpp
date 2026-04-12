#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3000;

int N;
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> dp[i][i];
    for (int w = 2; w <= N; w++)
        for (int l = 0, r = w - 1; r < N; l++, r++)
            dp[l][r] = max(dp[l][l] - dp[l + 1][r], dp[r][r] - dp[l][r - 1]);
    cout << dp[0][N - 1] << endl;
}
