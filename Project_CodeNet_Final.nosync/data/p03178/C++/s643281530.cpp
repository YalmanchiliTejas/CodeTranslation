#include <bits/stdc++.h>
#define pb push_back
#define int long long int
#define mod 1000000007
#define inf (1LL<<60)
#define f(i,a,b) for (int i= a; i <b; ++i)
using namespace std;

int dp[10001][101][2];
int solve(string s,int D,int pos,int d,bool tight)
{
    if(dp[pos][d][tight]!=-1)
        return dp[pos][d][tight];
    int ub=tight?s[pos]-'0':9;
    if(pos==s.size()-1)
    {
        int a=0;
        for(int x=0;x<=ub;x++)
        {
            if(x%D==d)
                a++;
        }
        return a;
    }
    int ans=0;
    for(int x=0;x<=ub;x++)
        ans=(ans+solve(s,D,pos+1,(D+d-x%D)%D,tight==1&&x==ub))%mod;
    return dp[pos][d][tight]=ans;
}

signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof dp);
    string s;
    int D;
    cin>>s>>D;
    cout<<(mod+solve(s,D,0,0,1)-1)%mod;
}

