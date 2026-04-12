#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 110, maxl = 5;
int dp[maxn][maxl], K;
string N;

int C(int n, int k)
{
        if (n < k)
                return 0;
        if (k == 0)
                return 1;
        int res = 1;
        for (int i = 1; i <= k; i++)
                res *= n--;
        for (int i = 1; i <= k; i++)
                res /= i;
        return res;
}

signed main()
{
        cin >> N >> K;

        int sz = N.size();
        dp[sz][0] = 1;
        for (int i = sz - 1; ~i; i--) {
                for (int k = 0; k <= K; k++) {
                        if (!k)
                                dp[i][k] = 1;
                        else if (N[i] == '0')
                                dp[i][k] = dp[i + 1][k];
                        else {
                                dp[i][k] = (N[i] - '1') * C(sz - i - 1, k - 1) * pow(9, k - 1)
                                    + C(sz - i - 1, k) * pow(9, k);
                                dp[i][k] += dp[i + 1][k - 1];
                        }
                }
        }

        cout << dp[0][K];

        return 0;
}
