#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll prefix[n+1];
    prefix[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        prefix[i]=prefix[i+1]+a[i];
    }
    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
        ll res=((a[i]%mod)*(prefix[i+1]%mod))%mod;
        sum=((sum%mod)+(res%mod))%mod;
    }
    
    cout<<sum<<'\n';
    
    
    return 0;
}