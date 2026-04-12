#include<bits/stdc++.h>
using namespace std;

#define sync {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define ll long long int
#define mod 1000000007

int n;

void solve()
{
    cin>>n;
    ll a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    ll presum[n];
    presum[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        presum[i]=(presum[i+1]+a[i+1])%mod;;
    }
    
    ll ans = 0;
    
    for(int i=0;i<n;i++)
    {
        ans = (ans + (a[i]*presum[i])%mod)%mod;
    }
    
    cout<<ans;
}

int main()
{
    sync;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}





