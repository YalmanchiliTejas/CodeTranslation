#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
    string N;
    int K;
    cin >> N >> K;
    int n = N.size();

    vector<vector<vector<int>>> dp(105, vector<vector<int>>(4, vector<int>(2, 0)));
    dp[0][0][0] = 1;
    rep(i, n) rep(j, 4) rep(k, 2)
    {
        int nd = N[i] - '0';
        rep(d, 10)
        {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0)
                nj++;
            if (nj > K)
                continue;
            if (k == 0)
            {
                if (d > nd)
                    continue;
                else if (d < nd)
                    nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
    return 0;
}