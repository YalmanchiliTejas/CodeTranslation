#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
string k;
long long n,d,dp[150][150000][3];
long long f(int sum,int i,int mx)
{
    if(i==n)
    {
        if(sum==0)return 1;
        else return 0;
    }
    if(dp[sum][i][mx]!=-1)return dp[sum][i][mx];
    long long ans=0;
    if(i==0)
    {
        ans=-1;
        for(int j=0;j<=k[i]-'0';j++)
        {
            if(k[i]-'0'!=j)ans+=f((sum+j)%d,i+1,0);
            else ans+=f((sum+j)%d,i+1,1);
            ans%=mod;
        }
    }
    else
    {
        for(int j=0;j<=9;j++)
        {
            if(j>k[i]-'0'&&mx==0)ans+=f((sum+j)%d,i+1,0);
            else if(j<k[i]-'0')ans+=f((sum+j)%d,i+1,0);
            else if(j==k[i]-'0')ans+=f((sum+j)%d,i+1,mx);
            ans%=mod;
        }
    }
    return dp[sum][i][mx]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin>>k>>d;
    n=k.size();
    cout<<f(0,0,0);
}
