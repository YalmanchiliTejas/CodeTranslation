#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string N;
int K;
set <string> nd[3];

int dp[110][5][2]; // 

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    dp[0][0][0] = 1;
    for (int i = 0; i < N.length(); i++)
    {
        int d = N[i] - '0';
        for (int j = 0; j <= 3; j++)
            for (int k = 0; k < 2; k++)
            {
                if (k == 1)
                {
                    for (int l = 0; l < 10; l++)
                    {
                        if (l) dp[i+1][j+1][k] += dp[i][j][k];
                        else dp[i+1][j][k] += dp[i][j][k];
                    }
                }
                else
                {
                    for (int l = 0; l < d; l++)
                    {
                        if (l) dp[i+1][j+1][1] += dp[i][j][k];
                        else dp[i+1][j][1] += dp[i][j][k];                        
                    }

                    if (d == 0)
                    {
                        dp[i+1][j][0] += dp[i][j][k];
                    }
                    else
                        dp[i+1][j+1][0] += dp[i][j][k];
                }
            }
    }

    int nres = 0;
    for (int i = 0; i < 2; i++)
        nres += dp[N.length()][K][i];
    cout << nres << "\n";
}
