#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll mod=1e9+7;
ll f(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1){
            ret=ret*x%mod;
        }
        x=x*x%mod;
        y/=2;
    }
    return ret;
}
int main()
{
    FASTINOUT;
    ll x;
    cin>>x;
    ll a[x];
    for (int i=0;i<x;i++)
        cin>>a[i];
    ll sum=0;
    for (int i=0;i<x;i++)
        sum=(sum%mod+a[i]%mod)%mod;
    ll k=(sum*sum)%mod;
    ll m=0;
    for (int i=0;i<x;i++){
        m=(m+((a[i]*a[i])%mod))%mod;
    }
    cout<<(((k-m+mod)%mod)*(f(2,mod-2)%mod))%mod;
    return 0;
}
