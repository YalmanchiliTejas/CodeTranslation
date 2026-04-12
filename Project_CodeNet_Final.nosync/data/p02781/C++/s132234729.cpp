// After Contest

#include <bits/stdc++.h>
using namespace std;

int dp[101][4][2];

int main()
{
    string S;
    int K;
    cin >> S >> K;
    dp[0][0][0] = 1;
    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int digit = S[i] - '0';
                for (int d = 0; d < 10; d++)
                {
                    int ni = i + 1, nj = j, nk = k;
                    if (d != 0)
                    {
                        if (j >= K)
                            continue;
                        nj++;
                    }
                    if (k == 0)
                    {
                        if (d < digit)
                            nk = 1;
                        if (d > digit)
                            continue;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << (dp[S.length()][K][0] + dp[S.length()][K][1]) << endl;
}
