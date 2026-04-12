#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;
ll dfs(ll& d,int pos,bool flag,string& s,ll sum,ll int ***dp)
{
    if(pos>=s.length())
    {
        if((sum%d)==0)
        {
            
            return 1;
        }
        return 0;
    }
    int limit=s[pos]-'0';
    if(flag)
        limit=9;
    ll res=0;
    if(dp[pos][sum][flag]!=-1)
        return dp[pos][sum][flag];
    for(int g=0;g<=limit;g++)
    {
        if(flag||g<limit)
            res=(res%MOD+dfs(d,pos+1,1,s,(sum+g)%d,dp)%MOD)%MOD;
        else
            res=(res%MOD+dfs(d,pos+1,0,s,(sum+g)%d,dp)%MOD)%MOD;
    }
     dp[pos][sum][flag]=res;
    return res;
}
int main()
{
    string s;
    ll d;
    cin>>s>>d;
    int n=(int)s.length();
    ll int ***dp=new ll int**[n+1];
   
    for(int i=0;i<=n;i++)
    {
        dp[i]=new ll int*[d];
        for(int j=0;j<d;j++)
        {
            dp[i][j]=new ll int[2];
            dp[i][j][0]=-1;
             dp[i][j][1]=-1;
        }
        
    }
    cout<<(dfs(d,0,0,s,0,dp)-1+MOD)%MOD;
}
