#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll n;
ll a[200005];
map<pair<ll, ll>, ll> ma;

ll f(ll p, ll q)
{
    if(p <= 0 && q == 0) return 0;
    if(q == 0) return 0;
    if(p <= 0) return -4e18;
    ll t = (p + 1) / 2;
    if(q > t) return -4e18;
    if(ma[{p, q}]) return ma[{p, q}];
    ll re = -4e18;
    re = max(re, f(p - 2, q - 1));
    re = max(re, f(p - 3, q - 1));
    re = max(re, f(p - 4, q - 1));
    re += a[p];
    re = max(re, f(p - 1, q));
    return ma[{p, q}] = re;
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    cout<<f(n, n / 2)<<endl;
    return 0;
}
