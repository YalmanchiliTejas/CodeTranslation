#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
int main()
{
    ll n,x,m;
    cin>>n>>x>>m;

    vector<ll> v;

    map<ll,ll> mp;
    v.pb(x);
    ll next;
    while(true)
    {
        next=v[v.size()-1]*v[v.size()-1];

        next%=m;
        if(mp.count(next))
            break;
        mp[next]=v.size();
        v.pb(next);
    }

    ll sum=0;
    for(int i=0;i<min(n,mp[next]);i++)
    {
        sum+=v[i];
    }
    n-=mp[next];


    ll cycsum=0;

    for(int i=mp[next];i<v.size();i++)
    {
        cycsum+=v[i];
    }

    sum+=(n/(v.size()-mp[next]))*cycsum;
    n%=(v.size()-mp[next]);

    for(int i=mp[next];i<mp[next]+n;i++)
    {
        sum+=v[i];
    }

    cout<<sum;

}