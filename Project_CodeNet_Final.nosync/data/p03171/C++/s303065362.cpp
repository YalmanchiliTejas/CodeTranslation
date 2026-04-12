#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[3005][3005][2];
ll arr[3005];
ll solve(int left,int right,int flag)
{
    if(left>right) return 0;
    if(memo[left][right][flag]!=-1) return memo[left][right][flag];
    ll ret=0;
    if(flag==0)
    {
        ret=max(arr[left]+solve(left+1,right,1),arr[right]+solve(left,right-1,1));
    }
    
    else
    {
        ret=1e18;
        ret=min(-arr[left]+solve(left+1,right,0),-arr[right]+solve(left,right-1,0));
    }
    
    return memo[left][right][flag]=ret;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    
    int n;
    cin>>n;
    ll tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }
    
    ll ans=solve(0,n-1,0);
    printf("%lld\n",ans);
}