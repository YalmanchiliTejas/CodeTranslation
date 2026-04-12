#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <set>
#include <map>
#include <algorithm>  
#include <cmath>
#include <iomanip>
#define ll long long
using namespace std;
ll n;
ll mod=pow(10,9)+7;
ll arr[3005];
ll dp[3005][3005][2];
ll calc(ll i,ll j,ll flag)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j][flag]!=-1)
    {
        return dp[i][j][flag];
    }
    if(flag==0)
    {
        ll ans1=calc(i+1,j,1)+arr[i];
        ll ans2=calc(i,j-1,1)+arr[j];
        return dp[i][j][0]=max(ans1,ans2);
    }
    ll ans1=calc(i+1,j,0)-arr[i];
        ll ans2=calc(i,j-1,0)-arr[j];
        return dp[i][j][1]=min(ans1,ans2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<calc(0,n-1,0)<<endl;
}




































