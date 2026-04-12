#include<bits/stdc++.h>
#define chal ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n],i,ans=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        b[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            b[i]=(b[i+1]%mod+a[i+1]%mod)%mod;
        }
        for(i=0;i<n;i++)
        {
            ans=(ans%mod+(a[i]*b[i])%mod)%mod;
        }
        cout<<ans;

    }
    return 0;
}
