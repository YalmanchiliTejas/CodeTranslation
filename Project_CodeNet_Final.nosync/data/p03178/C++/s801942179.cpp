#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
ll dp[10001][101][2];
ll solve(int i,string &s,int m,int d,bool tight)
{
    if(i==s.length())
    {
        if(m==0)
            {
                
                return 1;
            }
        return 0;
    }
    if(dp[i][m][tight]!=-1)
        return dp[i][m][tight];

    int en = (tight)?(s[i]-'0'):9;
    ll ans = 0;
    for(int j=0;j<=en;j++)
    {
        int newm = (m+j)%d;
       
        ans = (ans+solve(i+1,s,newm,d,tight&(j==en)))%mod;
     
    }

    return dp[i][m][tight] = ans;
}
int main()
{
    string k;
    cin>>k;

    memset(dp,-1,sizeof dp);

    int d;
    cin>>d;

    cout<<(mod+-1+solve(0,k,0,d,true))%mod;

    return 0;
}