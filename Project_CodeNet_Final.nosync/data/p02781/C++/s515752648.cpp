#include <bits/stdc++.h>
using namespace std;
string n;
int k;

long long dp[102][100][2];

long long int solve(int i, int j, int tight)
{
    if (i < 0)
    {
        return j == k;
    }
    if (dp[i][j][tight] != -1 && tight != 1)
        return dp[i][j][tight];
    int k = (tight) ? n[i]-'0' : 9;
    long long int r=0;
    for (int g = 0; g <= k; g++)
    {
        int newTight = (n[i]-'0' == g) ? tight : 0;
        int nj = (g == 0) ? 0 : 1;
        r+=solve(i-1,j+nj,newTight);
    }
    if(!tight)
        dp[i][j][tight]=r;
    return r;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    reverse(n.begin(),n.end());
    cout<<solve(n.size()-1,0,1);
}