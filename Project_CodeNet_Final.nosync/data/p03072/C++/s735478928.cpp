#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second

ll FastModExp(ll a,ll b,ll m)
{
// To compute a^b mod m
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }

    return res;
}
int main()
{
    ll n,i,j,c=0;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ll mx=v[0];
    for(auto h:v)
    {
        if(h>=mx) c++;
        mx=max(mx,h);
    }
    cout<<c;
    
    return 0;
}



