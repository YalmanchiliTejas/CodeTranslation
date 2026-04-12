// The moment you think of giving up you have already lost the battle
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long int ll;
typedef long double dl;
#define PI  3.14159265358979323846
#define M   1000000007
ll fast(ll n,ll a,ll m)
{
    if(n==0)
        return 1;
    else if(n==1)
        return a;
    else
    {
        ll r=fast(n/2,a,m);
        if(n%2==0)
        {
            return (((r%m)*(r%m))%m);
        }
        else
        {
            return (((((r%m)*a)%m)*r)%m);
        }

    }
}
int main()
{
    ll n,i;
    cin>>n;
    ll A[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    ll pref[n+1];
    pref[0]=0;
    for(i=1;i<=n;i++)
        pref[i]=(pref[i-1]%M+A[i-1]%M)%M;

    ll ans=0;
    for(i=1;i<=n-1;i++)
    {
        ll d=pref[n]-pref[i];
        if(d<0)
        {
            d+=M;
            d%=M;
        }
        d=((d%M)*(A[i-1]%M))%M;
        ans=(ans%M+d%M)%M;
    }
    cout<<ans;

}
