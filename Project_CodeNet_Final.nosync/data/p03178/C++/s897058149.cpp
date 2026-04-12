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

string s;
int d;

int go(int i,int md,int flag)
{
    if(i == s.length()) return (md == 0);
    
    int & res = dp[i][md][flag];
    
    if(res != -1) return res;
    
    res = 0;

    int r = 9*flag + (1-flag)*(s[i]-'0');
    
    for(int v=0;v<=r;v++)
    {
       int nmd = ((md - v)%d + d)%d;
       res+=go(i+1,nmd,flag | (v < r));
    }
    
    res%=MOD;
    
    return res;
}

signed main()
{
    fast;
    
    memset(dp,-1,sizeof(dp));
    
    cin >> s >> d;
    
    cout << (go(0,0,0) - 1 + MOD)%MOD;
}