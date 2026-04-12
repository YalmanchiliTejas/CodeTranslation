#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[3002];
ll dp[3003][3003],n;
ll finds(int st=0,int en=n-1)
{
    if(st>en)
        return 0;
    if(dp[st][en]!=-1)
        return dp[st][en];
    ll ans1=arr[st]+min(finds(st+2,en),finds(st+1,en-1));
    ll ans2=arr[en]+min(finds(st+1,en-1),finds(st,en-2));

    return dp[st][en]=max(ans1,ans2);

}

int main()
{
    ll i,j,s=0;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(i=0;i<n;i++)
        {
            cin>>arr[i];
            s+=arr[i];
        }
    ll y=finds();
    ll x=s-y;
    cout<<y-x<<endl;


}
