#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;

ll power(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(res*a)%mod;
        n=n/2;
        a=(a*a)%mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>v(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i];

    ll E=0,X=0,R=0,P=0;

    for(int i=1;i<=n;i++)
    {
        E=(E+v[i])%mod;
    }
    E=(E%mod*E%mod)%mod;

    for(int i=1;i<=n;i++)
    {
        R=(v[i]%mod*v[i]%mod)%mod;
        X=(X+R)%mod;
    }

    P=((E-X)*power(2,mod-2))%mod;
    if(P<0)
        P=(P+mod)%mod;
    cout<<P<<"\n";
}
