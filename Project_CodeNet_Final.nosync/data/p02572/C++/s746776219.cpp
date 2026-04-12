#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,i,j,sum=0,ans=0;
    j=(1e9)+7;
    vector<ll> a;
    cin>>n;
    a.resize(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=(sum+a[i])%j;
    }
    for(i=0;i<n;i++)
    {
        sum=(sum-a[i]+j)%j;
        ans=(ans+(a[i]*sum))%j;
    }
    cout<<ans<<endl;
}
