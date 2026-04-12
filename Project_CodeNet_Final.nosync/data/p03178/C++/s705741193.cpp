//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

const int mod = 1e9+7;
const int nax =1e4+10;
int dp[nax][100][2];
signed main()
{
    fast;
    string s;
    cin >> s;
    int n;
    cin >> n;
    int len = (int)(s.size());
    memset( dp,-1,sizeof(dp) );
    
    function< int(int,int,int) > solve = [&](int pos,int m,int f)
    {
        if( pos==len )
            return (int)(m==0);
        if( dp[pos][m][f] != -1) 
            return dp[pos][m][f];
        int &res = dp[pos][m][f];
        res = 0;
        int lim = 9;
        if( !f ) lim = s[pos]-'0';
        
        for(int i=0 ; i<lim ; i++ )
        {
            res += solve( pos+1 , (m+i)%n , 1 );
            res %= mod;
        }
        res += solve( pos+1 , (m+lim)%n , f );
        res %= mod;
        return res;
    };
    
    cout << (solve(0,0,0)-1+mod)%mod;
}



