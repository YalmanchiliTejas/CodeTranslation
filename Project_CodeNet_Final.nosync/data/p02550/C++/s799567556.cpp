#include <bits/stdc++.h>
#define nl endl
#define dbg(a) cout << #a << "=" << a << endl
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define md 1000000007

using namespace std;

ll qpow(ll n, ll k, ll mod)
{
    ll ans = 1;
    assert(k >= 0);
    n %= mod;
    while (k > 0)
    {
        if (k & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return ans % mod;
}

int solve()
{
    ll n, x, m;
    cin>>n>>x>>m;
    ll ct=0;
    ll prv=x;
    map<ll, ll> mp;
    vector<long long> v;
    for(ll i=1;i<=n;i++)
    {
        if(mp[x]!=0)
        {
            // dbg(i);
            ll tot=v.back();
            if(mp[x]!=1) tot-=v[mp[x]-2];
            ll ln=i-mp[x];
            tot*=(n-i)/ln;
            i+=((n-i)/ln)*ln;
            ct+=tot;
            mp.clear();
        }
        ct+=x;
         mp[x]=i;
         ll pb=0;
       if(v.size()) pb+=v.back();
        v.push_back(x+pb);
        x=(x*x)%m;
       
        
    }
    cout<<ct<<endl;

    return 0;
}

int main()
{
    fast;
    solve();
    return 0;
}