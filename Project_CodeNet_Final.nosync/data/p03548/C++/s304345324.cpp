#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>di;


int main()
{
    ll x,y,z;
    cin>>x>>y>>z;
    ll a=x/(y+z);
    if(x-a*(y+z)>=z)cout<<a;
    else cout<<a-1;
}
