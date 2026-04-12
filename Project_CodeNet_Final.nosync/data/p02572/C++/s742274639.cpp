#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
int main() {
    ll n;cin>>n;
    vector<ll>a(n);
    ll c=0,t=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        t+=a[i];
        // t=(t%m+a[i]%m)%m;
    }
    // cout<<t<<endl;
    for(ll i=0;i<n;i++)
    {
        t=t-a[i];
        // c+=a[i]*t;
        c=((c%m)+((a[i]%m)*(t%m))%m)%m;
    }
    cout<<c<<endl;
}
