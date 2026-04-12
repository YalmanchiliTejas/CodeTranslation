#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll arr[200005],pref[200005],sum=0,ans=0,n,m=1e9+7;
    vector <ll> adj;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pref[0]=arr[0];
    sum+=arr[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=arr[i]+pref[i-1];
        sum+=arr[i];
    }
    for(int i=1;i<n;i++)
    {
        adj.push_back(sum-pref[i-1]);
    }
    for(int i=0;i<adj.size();i++)
    {
        ans=(ans%m+((arr[i]%m)*(adj[i]%m))%m)%m;
    }
    cout<<ans<<'\n';
}