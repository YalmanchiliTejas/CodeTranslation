#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10);

    string n;
    int kk;
    cin >> n >> kk;

    // dp[i][j]: ある桁まで確定したとき 0でない数字がちょうどj個あるものの個数 iは数がN以下なのが確定したかのフラグ
    vector<vector<int>> dp(2, vector<int>(kk + 1, 0));
    dp[false][0] = 1;

    for (int i = 0; i < n.size(); i++)
    {
        vector<vector<int>> ndp(2, vector<int>(kk + 1, 0));

        // N以下が確定していないとき
        const int lim = n[i] - '0';
        for (int k = 0; k <= kk; k++)
        {
            for (int l = 0; l <= lim; l++)
            {
                if (k + (l != 0) <= kk)
                    ndp[l != lim][k + (l != 0)] += dp[false][k];
            }
        }

        // N以下が確定しているとき
        for (int k = 0; k <= kk; k++)
        {
            for (int l = 0; l <= 9; l++)
            {
                if (k + (l != 0) <= kk)
                    ndp[true][k + (l != 0)] += dp[true][k];
            }
        }
        dp = ndp;
    }

    int ans = dp[false][kk] + dp[true][kk];
    cout << ans << endl;
}
