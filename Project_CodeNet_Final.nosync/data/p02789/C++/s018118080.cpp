#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

ll power(ll x, ll y)
{
    ll res = 1;
    x = x%mod;
    while (y)
    {
        if (y&1) res = ((res%mod)*(x%mod))%mod;

        y>>=1;
        x = ((x%mod)*(x%mod))%mod;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    n==m?cout<<"Yes\n":cout<<"No\n";

    return 0;
}
