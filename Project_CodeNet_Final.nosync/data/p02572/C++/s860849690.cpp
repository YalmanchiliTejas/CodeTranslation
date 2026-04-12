#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;
ll a[maxn];
ll suf[maxn];




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1]+a[i];
        suf[i]%=mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll temp=a[i]*suf[i+1];
        temp%=mod;
        ans+=temp;
        ans%=mod;

    }
    cout<<ans<<'\n';





}
