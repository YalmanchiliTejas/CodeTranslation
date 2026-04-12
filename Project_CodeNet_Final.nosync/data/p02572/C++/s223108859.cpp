#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
#define pi pair<int,int>
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define mx 1000000
#define mn 0
#define hello 123

signed main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum[n];
    sum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)sum[i]=(arr[i]+sum[i+1])%mod;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans=ans+(arr[i]*sum[i+1])%mod;
        ans%=mod;
    }
    cout<<ans;
}