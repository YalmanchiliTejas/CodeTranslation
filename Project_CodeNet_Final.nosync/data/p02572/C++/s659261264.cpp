#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define oo 0x3f3f3f3f

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,s=0,mod=1e9+7;
    cin>>n;
    vector<ll>A(n);
    for(auto&x:A)cin>>x,s+=x;

    ll res = 0;
    for(auto&x:A)res = (res + ((s-x)%mod)*x)%mod;

    res=  (res * ((mod+1)/2))%mod;

    cout<<res;
}
