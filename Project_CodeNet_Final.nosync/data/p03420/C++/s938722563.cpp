#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1e5+10;

int main()
{
    ll n,k,ans=0;
    cin>>n>>k;
    if(k==0){cout<<n*n;return 0;}
    //if(k==1){cout<<n*n-n;return 0;}
    for(int i=k+1;i<=n;i++)
    {
        if(n%i)
        {
            ll t=n/i;
            ans+=t*(i-k);
            if(n%i>=k)if(k)ans+=n%i-k+1;
            else ans+=n%i;
        }
        else
        {
            ll t=n/i;
            ans+=t*(i-k);
        }
    }
    cout<<ans;
    return 0;
}
