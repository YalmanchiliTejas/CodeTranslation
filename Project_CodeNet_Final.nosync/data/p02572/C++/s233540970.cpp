#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007


void solve()
{
    int n;cin>>n;
    vector<int>arr(n);
    vector<int>sum(n,0);
    for(int i=0;i<n;i++)
    cin>>arr[i];
   sum[n-1]=arr[n-1];
   for(int i=n-2;i>=0;i--)
   sum[i]=(sum[i+1]+arr[i])%mod;
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int term=(arr[i]*(sum[i]-arr[i]+mod))%mod;
        ans+=term%mod;
        ans=ans%mod;
    }
    cout<<ans%mod<<endl;
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
    t=1;
       while(t--)
       solve();
}