//https://atcoder.jp/contests/dp/tasks/dp_s
//shauryakr
#include<bits/stdc++.h>
using namespace std;
string k;
int d, n;
const long long int mod = 1e9+7;
long long int dp[10010][105][2];
long long int solve(int ind, int rem, int constraint)
{
    if(ind == n)
    {
        if(rem == 0)
            return 1;
        return 0;
    }

    if(dp[ind][rem][constraint] != -1)
        return dp[ind][rem][constraint];

    long long int ans = 0;
    if(constraint)
    {
        for(int i=0; i<=(k[ind]-'0'); i++)
        {
            ans += solve(ind+1, (rem + i)%d, (i==(k[ind]-'0'))?1:0);
            if(ans >= mod)
                ans -= mod;
        }
    }
    else
    {
        for(int i=0; i<=9; i++)
        {
            ans += solve(ind+1, (rem+i)%d, 0);
            if(ans >= mod)
                ans -= mod;
        }
    }

    dp[ind][rem][constraint] = ans;
    return ans;
}

int main()
{
    cin >> k>> d;
    n = k.length();
    memset(dp, -1, sizeof dp);
    cout << (solve(0, 0, 1) + mod - 1)%mod << endl;
}