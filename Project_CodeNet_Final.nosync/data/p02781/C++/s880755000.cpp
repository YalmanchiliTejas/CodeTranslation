#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int64_t dp[111][2][4];
int main()
{
    string N;
    int K, M;
    cin >> N;
    cin >> K;
    M = N.size();
    //   cout << N << " " << K << endl;

    dp[0][0][0] = 1;
    int r, c, i, j, k, l;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < 2; j++)
        {
            //j=0すなわちN未満であることが確定：0-9の値をとれる
            //j=1すなわちN未満であることが未確定：i桁目と同じ値
            r = j ? 9 : N[i] - '0';
            for (k = 0; k <= K; k++)
            {
                for (l = 0; l <= r; l++)
                {
                    c = k + !!l; //l=0で0,l!=0で1をkに足す
                    if (c <= K)
                        dp[i + 1][j || l < r][c] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[M][0][K] + dp[M][1][K] << endl;
}