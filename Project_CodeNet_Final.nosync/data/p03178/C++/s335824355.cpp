#include <iostream>
#include <vector>

using namespace std;

int dp[10010][100][2];

const int MOD = 1e9 + 7;

int main()
{
    string k;
    int d;

    cin >> k;
    cin >> d;

    int n = k.length();

    vector <int> number(n);

    for (int i = 0; i < n; i++)
        number[i] = k[i] - '0';

    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++)
    {
        int maxDigit = number[i];

        for (int j = 0; j < d; j++)
        {
            for (int digit = 0; digit < 10; digit++)
            {
                int rest = (j + digit) % d;

                dp[i + 1][rest][1] = (dp[i + 1][rest][1] + dp[i][j][1]) % MOD;
            }

            for (int digit = 0; digit < maxDigit; digit++)
            {
                int rest = (j + digit) % d;

                dp[i + 1][rest][1] = (dp[i + 1][rest][1] + dp[i][j][0]) % MOD;
            }

            int rest = (j + maxDigit) % d;

            dp[i + 1][rest][0] = (dp[i + 1][rest][0] + dp[i][j][0]) % MOD;
        }
    }
    int answer = dp[n][0][1]+dp[n][0][0] - 1;

    cout << (answer + MOD) % MOD << endl;

    return 0;
}
