#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

vector <int> v;
int n;

int dp[10010][2][110];

int solve(int pos, int flag, int sum)
{
    if(pos == v.size())
        return (sum == 0);

    if(dp[pos][flag][sum] == -1)
    {
        int cnt;
        int ans = 0;

        if(flag)
            cnt = 9;
        else
            cnt = v[pos];

        for(int i=0;i<=cnt;i++)
        {
            if(i == v[pos])
                ans = (ans + solve(pos+1,flag&1,(sum+i)%n))%mod;
            else
                ans = (ans + solve(pos+1,1,(sum+i)%n))%mod;
        }

        dp[pos][flag][sum] = ans;
    }

    return dp[pos][flag][sum];
}

int32_t main()
{
    for(int i=0;i<10010;i++)
    {
        for(int j=0;j<110;j++)
            dp[i][0][j] = dp[i][1][j] = -1;
    }

    string s;
    
    cin >> s >> n;

    for(char i:s)
        v.push_back(i-'0');

    cout << (solve(0,0,0) - 1 + mod)%mod << endl;
}