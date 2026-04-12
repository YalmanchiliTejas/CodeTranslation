#include <bits/stdc++.h>
using namespace std;
#define w(x) int x;cin>>x;while(x--)
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define ff first
#define ss second
#define fr(a,b) for(int i=a;i<=b;i++)
#define inf 1e18
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    ll pre[n+1];
    for(int i=0;i<n;i++){
    cin>>a[i];
    pre[i]=a[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        pre[i]=pre[i]+pre[i+1];
        pre[i]=pre[i]%mod;
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ans=(ans%mod+(pre[i]%mod*a[i-1]%mod)%mod)%mod;
    }
    cout<<ans<<"\n";
    return 0;
    
}
