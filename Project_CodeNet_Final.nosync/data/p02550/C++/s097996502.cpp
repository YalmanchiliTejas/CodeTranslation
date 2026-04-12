#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=1e9+7;
int main()
{
    ll n,x,m;
    cin>>n>>x>>m;
    map<ll,ll> mp;
    vector<ll> v;
    ll sum=0;    
    v.push_back(0);
    ll last=0;
    for(ll i=1;i<=n;i++)
    {
        // cout<<x<<endl;
        x=x%m;
        if(x==0)
        break;
        if(mp[x])
        {
            last=i;
            break;
        }
        sum+=x;
        v.push_back(x);
        mp[x]=i;
        x=(x*x)%m;
    }
    // cout<<last<<" "<<mp[x]<<" "<<sum<<" "<<v.size();
    if(last==0)
    {
        cout<<sum<<endl;
        return 0;
    }
    ll ans=sum;
    ll my_size=last-mp[x];
    n=n-last+1;
    ll sum2=0;
    for(ll i=mp[x];i<last;i++)
    sum2+=v[i];
    ans+=(n/my_size)*sum2;
    n=n%my_size;
    for(ll i=mp[x];i<mp[x]+n;i++)
    ans+=v[i];
    cout<<ans<<endl;
}