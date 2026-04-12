#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    if(k==0)
    {
        cout<<n*n;
        return 0;
    }
    ll ans=0;
    for(ll i=k;i<n;i++)
    {
        ans+=(n-i);
    }
    for(ll i=k+1;i<=n;i++)
    {
        ll d=i+k;
        if(d>n)
        {
            break;
        }
        ll l,r,m;
        l=0;
        r=1e9;
        while(l<r)
        {
            m=(l+r+1)>>1;
            if(d+i*m<=n)
            {
                l=m;
            }
            else
            {
                r=m-1;
            }
        }
        ans+=(l*(i-k));
        d+=(i*l);
        ans+=min(i-k,n-d+1);
    }
    cout<<ans;
    return 0;
}
