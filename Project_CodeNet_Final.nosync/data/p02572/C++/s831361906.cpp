#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll i,j,n;
    cin>>n;
    vector<ll> v(n),z(n+1);
    map<ll,ll>m;
    ll sum=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i]; 
        sum=sum+v[i];
    }
    z[n-1]=0;
    for(i=n-2;i>=0;i--)
    {
        z[i]=z[i+1]+v[i+1];
    }
    ll prod=0;
    for(i=0;i<n;i++)
    {
        prod=(prod+ v[i]*(z[i]%mod)%mod)%mod;
    }
    cout<<prod;
}

    
