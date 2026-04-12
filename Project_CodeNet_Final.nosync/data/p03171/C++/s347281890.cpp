//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define ld long double
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;



signed main()
{
    fast;
    int n;
    cin >> n ;
    vector<int> a(n+1,0) ;
    for(int i=1 ; i<=n ; i++ )
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int dp[n+1][n+1];
    memset( dp,0,sizeof(dp) );
    
    for(int i=1 ; i<=n ; i++ )
        dp[i][i] = a[i]-a[i-1];
    
    for(int len=2 ; len<=n ; len++ )
    {
        for(int st=1 ; st+len-1<=n ; st++ )
        {
            int i = st;
            int j = st+len-1;
            dp[i][j] = max( -a[i-1] + a[j] - dp[i+1][j] , a[j] - a[i-1] - dp[i][j-1] );
        }
    }
    //cout << dp[1][n] << "\n";
    cout << dp[1][n] - ( a[n]-dp[1][n] ) << "\n";
}



