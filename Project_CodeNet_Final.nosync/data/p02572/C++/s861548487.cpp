#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int x=1;
    //cin>>t;
    while( x-- )
    {
        ll n;
        cin>>n;
        ll a[n];

        for( int i=0 ; i<n ; i++ )
            cin>>a[i];

        ll suf_sum[n];
        suf_sum[n-1]=a[n-1];

        for( int i=n-2 ; i>=0 ; i-- )
            suf_sum[i]=(suf_sum[i+1]+a[i])%mod;

        ll ans=0;

        for( int i=0 ; i<n-1 ; i++ )
        {
            ans= (ans + (( a[i]*suf_sum[i+1] )%mod))%mod;
        }
        cout<<ans;
    }
    return 0;
}
