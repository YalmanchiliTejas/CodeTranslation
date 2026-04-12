#include <bits/stdc++.h>

using namespace std;
#define ll long long


string k;
const int N = 1e4 + 5, mod = 1e9 + 7;
int dp[N][2][105], d;

//complexity 1e4 * 1e2 * 2 * 10

int add(int a, int b, int Mod)
{
    return (a + b) % Mod;
}
int solve(int idx, bool smaller, int sum)
{
    if(idx == k.size())
        return sum == 0;
    int &ans = dp[idx][smaller][sum];
    if(ans != -1)
        return ans;
    ans = 0;
    for(int digit = 0; digit <= 9; digit++)
    {
        if(!smaller && digit > k[idx] - '0')
            continue;
        bool new_smaller;
        if(smaller)
            new_smaller = 1;
        else
            if(digit < k[idx] - '0')
                new_smaller = 1;
            else
                new_smaller = 0;
        ans = add(ans, solve(idx + 1, new_smaller, add(sum, digit, d)), mod);
    }
    return ans;
}

int table()
{
    dp[k.size()][0][0] = dp[k.size()][1][0] = 1;
    for(int idx = k.size() - 1; idx >= 0; idx--)
    {
        for(int smaller = 0; smaller <= 1; smaller++)
        {
            for(int sum = 0; sum < d; sum++)
            {
                //compute dp[idx][smaller][sum]
                for(int digit = 0; digit <= 9; digit++)
                {
                    if(!smaller && digit > k[idx] - '0')
                        continue;
                    int &ans = dp[idx][smaller][sum];
                    ans = add(ans, dp[idx + 1][smaller | (digit < k[idx] - '0')][add(sum, digit, d)], mod);
                }
            }
        }
    }
    return dp[0][0][0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> k >> d;
    cout << (table() - 1 + mod) % mod;
    return 0;
}
