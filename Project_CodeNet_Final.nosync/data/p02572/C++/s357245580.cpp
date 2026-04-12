#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200007];
ll brr[200007];
ll m = 1e9+7;
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>arr[i];
        brr[i] = ((arr[i]%m)+(brr[i-1]%m))%m;
    }
    ll sum = 0;
    for(ll i=2;i<=n;++i)
    {
        ll val  = ((arr[i]%m)*(brr[i-1]%m))%m;
        sum = ((sum%m)+(val%m))%m;
    }
    cout<<sum<<endl;
}
