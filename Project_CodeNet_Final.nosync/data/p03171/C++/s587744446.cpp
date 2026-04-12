#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n , a[3000];
ll dp[3000][3000][2];// the time complexity is the size of the dp
ll play( int i = 0 , int j = n-1 , bool p = 0 )
{
    ll &d = dp[i][j][p];
    if( i == j )
        if( p == 0 )
            return a[i];
        else 
            return -a[i];
    if( d != -1 )
        return d;
    if( p == 0 )
        d = max( play( i+1 , j , 1-p ) + a[i] , play( i , j-1 , 1-p ) + a[j] );
    else
        d = min( play( i+1 , j , 1-p ) - a[i] , play( i , j-1 , 1-p ) - a[j] );
    return d;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> a[i];
    
    cout << play();
    return 0;
}
