#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    string k;
    cin >> k;
    int d;
    cin >> d;
    int len = k.size();
    vector<vector<int>> dp(d, vector<int>(2));
    dp[0][0] = 1;
    for(int index = 0; index < len; index++)
    {
        vector<vector<int>> dp2(d, vector<int>(2));
        for(int sum = 0; sum < d; sum++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int digit = 0; digit < 10; digit++)
                {
                    if(digit > k[index] - '0' && j == 0)
                    {
                        continue;
                    }
                    dp2[(sum + digit) % d][j || (digit < k[index] - '0')] = (dp2[(sum + digit) % d][j || (digit < k[index] - '0')] + dp[sum][j]) % mod;
                }
            }
        }
        dp = dp2;
    }
    int ans = (dp[0][0] + dp[0][1]) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans;
    return 0;
}