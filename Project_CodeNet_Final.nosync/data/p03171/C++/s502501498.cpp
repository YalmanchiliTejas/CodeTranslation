#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MAX = 3e3+5;
const ll INF=1e15;

ll a[MAX];
ll dp[MAX][MAX];

ll calc(ll l,ll r,int flg)
{
    if(l>r)
        return 0;
    if(l==r)
    {
        if(flg)
            return a[l];
        else return 0;    
    }
    if(l==r-1)
    {
        if(flg)
            return max(a[l],a[r]);
        else return min(a[l],a[r]);    
    }
    if(dp[l][r]!=-INF)
        return dp[l][r];
        
    ll &sum1=dp[l][r];
    sum1=0;
    if(flg)
    {
        sum1+=max(a[l]+calc(l+1,r,0),a[r]+calc(l,r-1,0));
    }
    else
    {
        sum1+=min(calc(l+1,r,1),calc(l,r-1,1));
    }
    return sum1;
        
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-INF;
    for(int i=0;i<n;i++)
    {    
        cin>>a[i];
        sum+=a[i];
    }
    
    ll val=calc(0,n-1,1);
    //cout<<val<<endl;
    cout<<val-(sum-val)<<endl;
    
        
}