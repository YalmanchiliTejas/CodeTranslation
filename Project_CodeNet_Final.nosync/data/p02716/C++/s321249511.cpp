
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n";
#define pair pair<ll,ll> 
ll MAX=LLONG_MAX;
ll MIN=LLONG_MIN;
const int siz=200001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i,j,k,l,m,n,o,p,q,r,s,t,x,a[siz+10]={0},prefix[siz+10]={0},dp[siz+10]={0};
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i-2>=0)
        prefix[i]=prefix[i-2]+a[i];
        else 
        prefix[i]=a[i];
    }
    dp[1]=0;
    for(i=2;i<=n;i++)
    {
        if(i%2==1)
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else 
        dp[i]=max(prefix[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}  
    
