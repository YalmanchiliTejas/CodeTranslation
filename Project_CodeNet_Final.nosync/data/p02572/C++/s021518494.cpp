#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
long double mm=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll i,a[n],s=0,ans=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s=s+a[i];
    }
    for(i=0;i<n;i++)
    {
        s=s-a[i];
        ans=(ans+((a[i]%mod)*(s%mod))%mod)%mod;
    }
    cout<<ans<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
