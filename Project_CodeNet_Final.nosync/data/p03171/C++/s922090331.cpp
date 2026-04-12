#include <bits/stdc++.h>
using namespace std;



int main(void)
{
    int N;
    cin >> N;

    vector<int> a(N,0);

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        a.at(i) = tmp;
    }

    long long int dp[N+1][N+1] = {};

    for(int len = 1; len <= N; ++len)
    {
        for(int i = 0; i + len <=N; ++i)
        {
            int j = i + len;

            // 先手
            if((N - len) % 2 == 0)
            {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }
            else
            {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);                
            }
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}

