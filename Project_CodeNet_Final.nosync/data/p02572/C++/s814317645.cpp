#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll mod=1e9+7;

int main()
{
    ll n,m;
    cin>>n;
    ll ara[n];
    ll sum[n];

    for(int i=0;i<n;i++) cin>>ara[i];
    for(int i=n-1;i>=0;i--){
        if(i==n-1) sum[i]=ara[i];
        else sum[i]=(sum[i+1]+ara[i])%mod;
    }

    ll ans=0;

    for(int i=0;i<n-1;i++){
        ll p=(sum[i+1]*ara[i])%mod;
        ans=(ans + p)%mod;
    }

    cout<<ans<<'\n';
}
