#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n,cs=0,ans=0;
    cin>>n;
    ll a[n+5];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        cs+=a[i];
        cs=cs%1000000007;
    }
    for(ll i=0;i<n;i++)
    {
        cs=cs-a[i];
        if(cs<0) cs+=1000000007;
        ans+=cs*a[i];
        ans=ans%1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
