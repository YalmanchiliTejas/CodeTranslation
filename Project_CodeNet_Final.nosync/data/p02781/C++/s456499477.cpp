#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

ll C(int n, int k)
{
    ll res = 1;
    for (int i = 0; i < k; i++) res *= (n - i);
    for (int i = 1; i <= k; i++) res /= i;
    return res;
}

int pow(int n, int k)
{
    int res = 1;
    for (int i = 0; i < k; i++) res *= n;
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n; cin >> n;
    int K; cin >> K;
    const int len = n.length();

    ll dp[len + 1][K + 1][2] = {};
    dp[0][0][0] = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 2; k++) {
                int nxt = n[i] - '0';
                for (int num = 0; num <= 9; num++) {
                    if (k == 0 && num > nxt) continue;

                    int ni = i + 1;
                    int nj = (num ? j + 1 : j);
                    int nk = (k == 0 && num == nxt ? 0 : 1);

                    if (nj > K) continue;

                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[len][K][0] + dp[len][K][1] << endl;
    return 0;
}