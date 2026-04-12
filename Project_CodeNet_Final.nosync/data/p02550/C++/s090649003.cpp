//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N,X,M; cin>>N>>X>>M;
    vector<ll> v;
    v.push_back(X);
    map<ll,ll> mp;
    
    ll i = 2;
    ll pos = -1;
    ll ans = X;
    mp[X] = 1;
    for(;i<=N;++i)
    {
        ll f = v.back() * v.back();
        f %= M;
        
        if(mp.find(f) != mp.end())
        {
            pos = mp[f];
            break;
        }
        
        v.push_back(f);
        ans += f;
        mp[f] = i;
    }
    vector<ll> patt;
    
    ll sum = 0;
    if(pos != -1)
    {
        for(ll j=(pos - 1);j<(i - 1);++j)
        {
            patt.push_back(v[j]);
            sum += v[j];
        }
        
        ll rem = N - i + 1;
        ll sz = patt.size();
        ans += sum * (rem/sz);

        for(ll j=0;j<rem%sz;++j)
            ans += patt[j];
    }
    
    cout<<ans<<endl;
}