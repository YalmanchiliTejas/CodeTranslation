#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
ll memo[10005][105][2];
string str;
ll solve(int idx,ll m,int safe,int n,ll k)
{
    if(idx==n)
    {
        if(m==0) return 1;
        return 0;
    }
    
    if(memo[idx][m][safe]!=-1) return memo[idx][m][safe];
    ll ret=0;
    if(idx==0)
    {
        for(int i=0;i<(str[idx]-'0');i++)
        {
            ret=(ret%M+solve(idx+1,(m%k+i%k)%k,0,n,k)%M)%M;
        }
        ret=(ret%M+solve(idx+1,(m%k+(str[idx]-'0')%k)%k,1,n,k)%M)%M;
    }
    
    else
    {
        if(safe==0)
        {
            for(int i=0;i<=9;i++)
            {
                ret=(ret%M+solve(idx+1,(m%k+i%k)%k,0,n,k)%M)%M;
            }
        }
        
        else
        {
            for(int i=0;i<(str[idx]-'0');i++)
            {
                ret=(ret%M+solve(idx+1,(m%k+i%k)%k,0,n,k)%M)%M;
            }
            ret=(ret%M+solve(idx+1,(m%k+(str[idx]-'0')%k)%k,1,n,k)%M)%M;
        }
    }
    
    return memo[idx][m][safe]=ret;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    cin>>str;
    ll k;
    cin>>k;
    ll ans=solve(0,0,0,str.size(),k);
    cout<<((ans%M - 1)%M+M)%M<<endl;
    
    
}