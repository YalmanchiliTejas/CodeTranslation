#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll MAX=1e4+5;
const ll MAX1=1e2+5;
const ll INF=1e15+2;
const ll MOD=1e9+7;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi pair<ll,ll>
#define map1 unordered_map

string k;
ll d,sz;
ll dp[2][MAX][MAX1];

ll solve(ll pos,ll sum,int flag)
{
    if(pos==sz)
        return sum==0;
        
    if(dp[flag][pos][sum]!=-1)
        return dp[flag][pos][sum];
    ll ans=0;
    
    for(int i=0;i<10;i++)
    {
        if(flag)
            ans=(ans+solve(pos+1,(sum+i)%d,flag))%MOD;
        else
        {
            if(i<k[pos]-'0')
                ans=(ans+solve(pos+1,(sum+i)%d,1))%MOD;
            else if(i==k[pos]-'0')    
                ans=(ans+solve(pos+1,(sum+i)%d,0))%MOD;
        }
    }
    return dp[flag][pos][sum]=ans;
}    
int main()
{
    memset(dp,-1,sizeof(dp));
    faster;
    cin>>k;
    cin>>d;
    sz=k.length();
    cout<<(solve(0,0,0)-1+MOD)%MOD;
    
}