#include <bits/stdc++.h>
using namespace std;
int n;
long long a[3010];
long long dp[3001][3001][2];
long long getScore(int i = 0 , int j = n-1 , bool player = 0)
{
    if(i>j)return 0;

    long long &ret = dp[i][j][player];
    if(~ret)    return ret;

    if(player)
    return ret = min(getScore(i+1,j,!player) -a[i],getScore(i,j-1,!player) -a[j]);
    else
    return ret = max(getScore(i+1,j,!player) +a[i],getScore(i,j-1,!player) +a[j]);

}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    memset(dp,-1,sizeof dp);
    cout << getScore();
    return 0;
}
