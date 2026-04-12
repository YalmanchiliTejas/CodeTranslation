#include<bits/stdc++.h>
#define int long long
#define M 1000000007
#define deb(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
int d;
int dp[100005][102][2];

int g(string n,int pos=0,int sum=0,int tight=1)
{
    sum=sum%d;
    if (pos==n.length())
        return((sum%d)==0);
    else if (dp[pos][sum][tight]!=-1)
        return dp[pos][sum][tight];
    else if (tight)
    {
        int res=0;
        for(int i=0; i<=n[pos]-'0'; i++)
        {
            if (i==(n[pos]-'0'))
                res=(res+g(n,pos+1,sum+i,1))%M;
            else
                res=(res+g(n,pos+1,sum+i,0))%M;
        }
        dp[pos][tight][sum]=res;
        return res;
    }
    else
    {
        int res=0;
        for(int i=0; i<=9; i++)
            res=(res+g(n,pos+1,sum+i,0))%M;
        dp[pos][sum][tight]=res;
        return res;
    }
}



signed main()
{
    string s;
    cin>>s>>d;
    memset(dp,-1,sizeof(dp));
    int ans=g(s);
    ans=(ans-1+M)%M;
    cout<<ans<<endl;
}