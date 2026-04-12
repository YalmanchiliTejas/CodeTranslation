#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int MOD = 1e9+7;

const int N = 1e4+10;
const int M = 101;

int dp[N][M][2];
int md[M][10];
    
string s;
int d;

signed main()
{
    fast;
    
    cin >> s >> d;
    
    int n = s.length();
    reverse(s.begin(),s.end());
    
    f(i,d) f(j,10)
        md[i][j] = ((i - j)%d + d)%d;
    
    dp[0][0][0] = dp[0][0][1] = 1;
    
    for(int i=1;i<=n;i++) f(j,d)
    {
        f(v,10)
        {
            dp[i][j][1] = (dp[i][j][1] + dp[i-1][md[j][v]][1])%MOD;
        }
        
        f(v,s[i-1]-'0')
        {
            dp[i][j][0] = (dp[i][j][0] + dp[i-1][md[j][v]][1])%MOD;
        }
        
        dp[i][j][0] = (dp[i][j][0] + dp[i-1][md[j][s[i-1]-'0']][0])%MOD;
    }
    
    cout << ( dp[n][0][0] - 1 + MOD)%MOD;
}