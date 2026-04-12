// https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[3005][3005];
ll a[3005];
ll n;

ll go(int i , int j , int turn)
{
     if(dp[i][j] != -1)
        return dp[i][j];
     if(i>j)
        return 0;
     if(i==j)
     {
        dp[i][j] = a[i];
        if(turn==1)
            dp[i][j]*=-1;
        return dp[i][j];
     }

     if(turn == 0)
     {
           dp[i][j] = go(i+1,j,1) + a[i];
           dp[i][j] = max(dp[i][j],go(i,j-1,1) + a[j]);
     }
     else
     {
           dp[i][j] = go(i+1,j,0) - a[i];
           dp[i][j] = min(dp[i][j], go(i,j-1,0) - a[j]);
     }
     return dp[i][j];
}

int main()
{
    cin >> n;
    for(int i=0; i <n ; i++)
        cin >> a[i];
    for(int i=0 ;i<3005 ; i++)
    {
        for(int j=0 ; j<3005 ; j++)
            dp[i][j] = -1;
    }
    cout << go(0,n-1,0);
    /*for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    return 0;
}
