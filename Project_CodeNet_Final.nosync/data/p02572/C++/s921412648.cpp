#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll arr[n],sum=0;
        for(int i=0;i<n;i++) {cin>>arr[i];sum=(sum+arr[i])%mod;}
        ll ans=0;
        for(int i=0;i<n-1;i++)
        {
            sum=(sum-arr[i]+mod)%mod;
            ans=(ans+ arr[i]*sum)%mod;
        }
        cout<<ans;
    }
}